#include "dtauth.h"
#include <QFile>
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

DTAuth::DTAuth(const QString &secretsFile, QNetworkAccessManager *nm, QObject *parent) : QObject(parent), networkManager(nm)
{
    if (!this->readLocalSecret(secretsFile)) {
        qFatal("Could not read secrets file");
    }

    connect(this->networkManager, &QNetworkAccessManager::finished,
            this, &DTAuth::receiveAccessToken);
    connect(&this->expirationTimer, &QTimer::timeout,
            this, &DTAuth::requestAccessToken);
    this->expirationTimer.setInterval(std::chrono::seconds(3400));
}

const QUrl DT_AUTH_URL("https://identity.disruptive-technologies.com/oauth2/token");

void DTAuth::authenticate()
{
    this->requestAccessToken();
    this->expirationTimer.start();
}

void DTAuth::requestAccessToken()
{
    QJsonWebToken jwt;
    QJsonObject header({
                           {"kid", this->keyId},
                           {"alg", "HS256"}
                       });
    jwt.setHeaderJDoc(QJsonDocument(header));
    auto now = QDateTime::currentSecsSinceEpoch();
    QJsonObject payload({
                            {"iat", now},
                            {"exp", now + 3500},
                            {"aud", DT_AUTH_URL.toString()},
                            {"iss", this->email}
                        });
    jwt.setPayloadJDoc(QJsonDocument(payload));
    jwt.setSecret(this->keySecret);

    QNetworkRequest req(DT_AUTH_URL);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QString body("grant_type=urn:ietf:params:oauth:grant-type:jwt-bearer&assertion=" + jwt.getToken());
    this->networkManager->post(req, body.toUtf8());
}

void DTAuth::receiveAccessToken(QNetworkReply *reply)
{
    if (reply->url().host() == DT_AUTH_URL.host()) {
        auto err = reply->error();
        if (err != QNetworkReply::NoError) {
            qCritical() << "Failed requesting access token:" << err;
        }
        reply->deleteLater();

        auto json = QJsonDocument::fromJson(reply->readAll());
        if (json.isEmpty()) {
            qCritical() << "Received empty JSON document in access token";
            return;
        }
        if (!json.isObject()) {
            qCritical() << "Access token JSON document does not contain a JSON object: " << json;
            return;
        }
        auto jo = json.object();
        if (jo.isEmpty()) {
            qCritical() << "Access token JSON object is empty";
            return;
        }

        if (!jo.contains("access_token")) {
            qCritical() << "Access token object does not contain access_token: " << json;
            return;
        }
        if (!jo["access_token"].isString()) {
            qCritical() << "access_token is not a string: " << json;
            return;
        }
        this->accessToken = jo["access_token"].toString();

        if (!jo.contains("expires_in")) {
            qCritical() << "Access token object does not contain expires_in: " << json;
            return;
        }
        if (!jo["expires_in"].isDouble()) {
            qCritical() << "expires_in is not a double: " << json;
            return;
        }
        this->accessTokenExpiration = QDateTime::currentDateTime().addSecs(int(jo["expires_in"].toDouble()));
        qInfo() << "Access token: " << this->accessToken;
        emit this->authenticated(this->accessToken);
    }
}

bool DTAuth::readLocalSecret(const QString &filename)
{
    QFile f(filename);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        qCritical() << "Could not open secrets file (" << f.fileName() << "): " << f.errorString();
        return false;
    }
    auto json = QJsonDocument::fromJson(f.readAll());
    if (json.isEmpty()) {
        qCritical() << "JSON document is empty";
        return false;
    }
    if (!json.isObject()) {
        qCritical() << "No JSON object in JSON document";
        return false;
    }
    auto obj = json.object();
    if (obj.isEmpty()) {
        qCritical() << "JSON object is empty";
        return false;
    }
    if (!obj.contains("email")) {
        qCritical() << "Missing email in JSON object";
        return false;
    }
    this->email = obj["email"].toString();
    if (!obj.contains("keyId")) {
        qCritical() << "Missing keyId in JSON object";
        return false;
    }
    this->keyId = obj["keyId"].toString();
    if (!obj.contains("keySecret")) {
        qCritical() << "Missing keySecret in JSON object";
        return false;
    }
    this->keySecret = obj["keySecret"].toString();
    return true;
}

QString DTAuth::getAccessToken() const
{
    return this->accessToken;
}
