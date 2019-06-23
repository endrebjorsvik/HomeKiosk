/**
 * API, Disruptive Technologies
 * This api provides access to management, configuration and access to streams of data from Disruptive Technologies sensor solutions. 
 *
 * The version of the OpenAPI document: v2
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */


#include "OAIServiceAccountKeyWithSecret.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIServiceAccountKeyWithSecret::OAIServiceAccountKeyWithSecret(QString json) {
    this->init();
    this->fromJson(json);
}

OAIServiceAccountKeyWithSecret::OAIServiceAccountKeyWithSecret() {
    this->init();
}

OAIServiceAccountKeyWithSecret::~OAIServiceAccountKeyWithSecret() {

}

void
OAIServiceAccountKeyWithSecret::init() {
    
    m_key_isSet = false;
    m_key_isValid = false;
    
    m_secret_isSet = false;
    m_secret_isValid = false;
    }

void
OAIServiceAccountKeyWithSecret::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIServiceAccountKeyWithSecret::fromJsonObject(QJsonObject json) {
    
    m_key_isValid = ::OpenAPI::fromJsonValue(key, json[QString("key")]);
    
    
    m_secret_isValid = ::OpenAPI::fromJsonValue(secret, json[QString("secret")]);
    
    
}

QString
OAIServiceAccountKeyWithSecret::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIServiceAccountKeyWithSecret::asJsonObject() const {
    QJsonObject obj;
	if(m_key_isSet){
        obj.insert(QString("key"), ::OpenAPI::toJsonValue(key));
    }
	if(m_secret_isSet){
        obj.insert(QString("secret"), ::OpenAPI::toJsonValue(secret));
    }
    return obj;
}


OAIServiceAccountKey
OAIServiceAccountKeyWithSecret::getKey() const {
    return key;
}
void
OAIServiceAccountKeyWithSecret::setKey(const OAIServiceAccountKey &key) {
    this->key = key;
    this->m_key_isSet = true;
}


QString
OAIServiceAccountKeyWithSecret::getSecret() const {
    return secret;
}
void
OAIServiceAccountKeyWithSecret::setSecret(const QString &secret) {
    this->secret = secret;
    this->m_secret_isSet = true;
}

bool
OAIServiceAccountKeyWithSecret::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(m_key_isSet){ isObjectUpdated = true; break;}
    
        if(m_secret_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIServiceAccountKeyWithSecret::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}
