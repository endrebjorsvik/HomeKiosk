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


#include "OAIOrganizationPermissionList.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIOrganizationPermissionList::OAIOrganizationPermissionList(QString json) {
    this->init();
    this->fromJson(json);
}

OAIOrganizationPermissionList::OAIOrganizationPermissionList() {
    this->init();
}

OAIOrganizationPermissionList::~OAIOrganizationPermissionList() {

}

void
OAIOrganizationPermissionList::init() {
    
    m_permissions_isSet = false;
    m_permissions_isValid = false;
    }

void
OAIOrganizationPermissionList::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIOrganizationPermissionList::fromJsonObject(QJsonObject json) {
    
    
    m_permissions_isValid = ::OpenAPI::fromJsonValue(permissions, json[QString("permissions")]);
    
}

QString
OAIOrganizationPermissionList::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIOrganizationPermissionList::asJsonObject() const {
    QJsonObject obj;
	
    if(permissions.size() > 0){
        obj.insert(QString("permissions"), ::OpenAPI::toJsonValue(permissions));
    } 
    return obj;
}


QList<QString>
OAIOrganizationPermissionList::getPermissions() const {
    return permissions;
}
void
OAIOrganizationPermissionList::setPermissions(const QList<QString> &permissions) {
    this->permissions = permissions;
    this->m_permissions_isSet = true;
}

bool
OAIOrganizationPermissionList::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(permissions.size() > 0){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIOrganizationPermissionList::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}
