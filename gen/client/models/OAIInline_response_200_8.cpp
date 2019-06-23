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


#include "OAIInline_response_200_8.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIInline_response_200_8::OAIInline_response_200_8(QString json) {
    this->init();
    this->fromJson(json);
}

OAIInline_response_200_8::OAIInline_response_200_8() {
    this->init();
}

OAIInline_response_200_8::~OAIInline_response_200_8() {

}

void
OAIInline_response_200_8::init() {
    
    m_organizations_isSet = false;
    m_organizations_isValid = false;
    
    m_next_page_token_isSet = false;
    m_next_page_token_isValid = false;
    }

void
OAIInline_response_200_8::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIInline_response_200_8::fromJsonObject(QJsonObject json) {
    
    
    m_organizations_isValid = ::OpenAPI::fromJsonValue(organizations, json[QString("organizations")]);
    
    m_next_page_token_isValid = ::OpenAPI::fromJsonValue(next_page_token, json[QString("nextPageToken")]);
    
    
}

QString
OAIInline_response_200_8::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIInline_response_200_8::asJsonObject() const {
    QJsonObject obj;
	
    if(organizations.size() > 0){
        obj.insert(QString("organizations"), ::OpenAPI::toJsonValue(organizations));
    } 
	if(m_next_page_token_isSet){
        obj.insert(QString("nextPageToken"), ::OpenAPI::toJsonValue(next_page_token));
    }
    return obj;
}


QList<OAIOrganization>
OAIInline_response_200_8::getOrganizations() const {
    return organizations;
}
void
OAIInline_response_200_8::setOrganizations(const QList<OAIOrganization> &organizations) {
    this->organizations = organizations;
    this->m_organizations_isSet = true;
}


QString
OAIInline_response_200_8::getNextPageToken() const {
    return next_page_token;
}
void
OAIInline_response_200_8::setNextPageToken(const QString &next_page_token) {
    this->next_page_token = next_page_token;
    this->m_next_page_token_isSet = true;
}

bool
OAIInline_response_200_8::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(organizations.size() > 0){ isObjectUpdated = true; break;}
    
        if(m_next_page_token_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIInline_response_200_8::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}

