#ifndef DTAUTH_H
#define DTAUTH_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include "qjsonwebtoken.h"

class DTAuth : public QObject
{
    Q_OBJECT
public:
    explicit DTAuth(const QString &secretsFile, QNetworkAccessManager *nm, QObject *parent = nullptr);
    void authenticate();
    QString getAccessToken() const;

signals:
    void authenticated(QString accessToken);

public slots:

private slots:
    void requestAccessToken();
    void receiveAccessToken(QNetworkReply *reply);

private:
    bool readLocalSecret(const QString &filename);

    QNetworkAccessManager *networkManager;
    QString email;
    QString keyId;
    QString keySecret;
    QString accessToken;
    QDateTime accessTokenExpiration;
    QTimer expirationTimer;
};

#endif // DTAUTH_H
