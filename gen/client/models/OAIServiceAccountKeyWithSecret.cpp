/**
 * API, Disruptive Technologies
 * This api provides access to management, configuration and access to streams of data from Disruptive Technologies sensor solutions. 
 *
 * The version of the OpenAPI document: v2
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include "OAIServiceAccountKeyWithSecret.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIServiceAccountKeyWithSecret::OAIServiceAccountKeyWithSecret(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIServiceAccountKeyWithSecret::OAIServiceAccountKeyWithSecret() {
    this->initializeModel();
}

OAIServiceAccountKeyWithSecret::~OAIServiceAccountKeyWithSecret() {}

void OAIServiceAccountKeyWithSecret::initializeModel() {

    m_key_isSet = false;
    m_key_isValid = false;

    m_secret_isSet = false;
    m_secret_isValid = false;
}

void OAIServiceAccountKeyWithSecret::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIServiceAccountKeyWithSecret::fromJsonObject(QJsonObject json) {

    m_key_isValid = ::OpenAPI::fromJsonValue(key, json[QString("key")]);
    m_key_isSet = !json[QString("key")].isNull() && m_key_isValid;

    m_secret_isValid = ::OpenAPI::fromJsonValue(secret, json[QString("secret")]);
    m_secret_isSet = !json[QString("secret")].isNull() && m_secret_isValid;
}

QString OAIServiceAccountKeyWithSecret::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIServiceAccountKeyWithSecret::asJsonObject() const {
    QJsonObject obj;
    if (m_key_isSet) {
        obj.insert(QString("key"), ::OpenAPI::toJsonValue(key));
    }
    if (m_secret_isSet) {
        obj.insert(QString("secret"), ::OpenAPI::toJsonValue(secret));
    }
    return obj;
}

OAIServiceAccountKey OAIServiceAccountKeyWithSecret::getKey() const {
    return key;
}
void OAIServiceAccountKeyWithSecret::setKey(const OAIServiceAccountKey &key) {
    this->key = key;
    this->m_key_isSet = true;
}

QString OAIServiceAccountKeyWithSecret::getSecret() const {
    return secret;
}
void OAIServiceAccountKeyWithSecret::setSecret(const QString &secret) {
    this->secret = secret;
    this->m_secret_isSet = true;
}

bool OAIServiceAccountKeyWithSecret::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_key_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_secret_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIServiceAccountKeyWithSecret::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
