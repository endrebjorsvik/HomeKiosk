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


#include "OAIMember.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIMember::OAIMember(QString json) {
    this->init();
    this->fromJson(json);
}

OAIMember::OAIMember() {
    this->init();
}

OAIMember::~OAIMember() {

}

void
OAIMember::init() {
    
    m_name_isSet = false;
    m_name_isValid = false;
    
    m_display_name_isSet = false;
    m_display_name_isValid = false;
    
    m_roles_isSet = false;
    m_roles_isValid = false;
    
    m_membership_status_isSet = false;
    m_membership_status_isValid = false;
    
    m_email_isSet = false;
    m_email_isValid = false;
    
    m_account_type_isSet = false;
    m_account_type_isValid = false;
    }

void
OAIMember::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIMember::fromJsonObject(QJsonObject json) {
    
    m_name_isValid = ::OpenAPI::fromJsonValue(name, json[QString("name")]);
    
    
    m_display_name_isValid = ::OpenAPI::fromJsonValue(display_name, json[QString("displayName")]);
    
    
    
    m_roles_isValid = ::OpenAPI::fromJsonValue(roles, json[QString("roles")]);
    
    m_membership_status_isValid = ::OpenAPI::fromJsonValue(membership_status, json[QString("membershipStatus")]);
    
    
    m_email_isValid = ::OpenAPI::fromJsonValue(email, json[QString("email")]);
    
    
    m_account_type_isValid = ::OpenAPI::fromJsonValue(account_type, json[QString("accountType")]);
    
    
}

QString
OAIMember::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIMember::asJsonObject() const {
    QJsonObject obj;
	if(m_name_isSet){
        obj.insert(QString("name"), ::OpenAPI::toJsonValue(name));
    }
	if(m_display_name_isSet){
        obj.insert(QString("displayName"), ::OpenAPI::toJsonValue(display_name));
    }
	
    if(roles.size() > 0){
        obj.insert(QString("roles"), ::OpenAPI::toJsonValue(roles));
    } 
	if(m_membership_status_isSet){
        obj.insert(QString("membershipStatus"), ::OpenAPI::toJsonValue(membership_status));
    }
	if(m_email_isSet){
        obj.insert(QString("email"), ::OpenAPI::toJsonValue(email));
    }
	if(m_account_type_isSet){
        obj.insert(QString("accountType"), ::OpenAPI::toJsonValue(account_type));
    }
    return obj;
}


QString
OAIMember::getName() const {
    return name;
}
void
OAIMember::setName(const QString &name) {
    this->name = name;
    this->m_name_isSet = true;
}


QString
OAIMember::getDisplayName() const {
    return display_name;
}
void
OAIMember::setDisplayName(const QString &display_name) {
    this->display_name = display_name;
    this->m_display_name_isSet = true;
}


QList<OAIRole>
OAIMember::getRoles() const {
    return roles;
}
void
OAIMember::setRoles(const QList<OAIRole> &roles) {
    this->roles = roles;
    this->m_roles_isSet = true;
}


QString
OAIMember::getMembershipStatus() const {
    return membership_status;
}
void
OAIMember::setMembershipStatus(const QString &membership_status) {
    this->membership_status = membership_status;
    this->m_membership_status_isSet = true;
}


QString
OAIMember::getEmail() const {
    return email;
}
void
OAIMember::setEmail(const QString &email) {
    this->email = email;
    this->m_email_isSet = true;
}


QString
OAIMember::getAccountType() const {
    return account_type;
}
void
OAIMember::setAccountType(const QString &account_type) {
    this->account_type = account_type;
    this->m_account_type_isSet = true;
}

bool
OAIMember::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(m_name_isSet){ isObjectUpdated = true; break;}
    
        if(m_display_name_isSet){ isObjectUpdated = true; break;}
    
        if(roles.size() > 0){ isObjectUpdated = true; break;}
    
        if(m_membership_status_isSet){ isObjectUpdated = true; break;}
    
        if(m_email_isSet){ isObjectUpdated = true; break;}
    
        if(m_account_type_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIMember::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}
