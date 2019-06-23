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


#include "OAIInline_response_200_10.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIInline_response_200_10::OAIInline_response_200_10(QString json) {
    this->init();
    this->fromJson(json);
}

OAIInline_response_200_10::OAIInline_response_200_10() {
    this->init();
}

OAIInline_response_200_10::~OAIInline_response_200_10() {

}

void
OAIInline_response_200_10::init() {
    
    m_invite_url_isSet = false;
    m_invite_url_isValid = false;
    }

void
OAIInline_response_200_10::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIInline_response_200_10::fromJsonObject(QJsonObject json) {
    
    m_invite_url_isValid = ::OpenAPI::fromJsonValue(invite_url, json[QString("inviteUrl")]);
    
    
}

QString
OAIInline_response_200_10::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIInline_response_200_10::asJsonObject() const {
    QJsonObject obj;
	if(m_invite_url_isSet){
        obj.insert(QString("inviteUrl"), ::OpenAPI::toJsonValue(invite_url));
    }
    return obj;
}


QString
OAIInline_response_200_10::getInviteUrl() const {
    return invite_url;
}
void
OAIInline_response_200_10::setInviteUrl(const QString &invite_url) {
    this->invite_url = invite_url;
    this->m_invite_url_isSet = true;
}

bool
OAIInline_response_200_10::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(m_invite_url_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIInline_response_200_10::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}
