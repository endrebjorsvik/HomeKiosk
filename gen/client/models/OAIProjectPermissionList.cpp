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

#include "OAIProjectPermissionList.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIProjectPermissionList::OAIProjectPermissionList(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIProjectPermissionList::OAIProjectPermissionList() {
    this->initializeModel();
}

OAIProjectPermissionList::~OAIProjectPermissionList() {}

void OAIProjectPermissionList::initializeModel() {

    m_permissions_isSet = false;
    m_permissions_isValid = false;
}

void OAIProjectPermissionList::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIProjectPermissionList::fromJsonObject(QJsonObject json) {

    m_permissions_isValid = ::OpenAPI::fromJsonValue(permissions, json[QString("permissions")]);
    m_permissions_isSet = !json[QString("permissions")].isNull() && m_permissions_isValid;
}

QString OAIProjectPermissionList::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIProjectPermissionList::asJsonObject() const {
    QJsonObject obj;
    if (permissions.size() > 0) {
        obj.insert(QString("permissions"), ::OpenAPI::toJsonValue(permissions));
    }
    return obj;
}

QList<QString> OAIProjectPermissionList::getPermissions() const {
    return permissions;
}
void OAIProjectPermissionList::setPermissions(const QList<QString> &permissions) {
    this->permissions = permissions;
    this->m_permissions_isSet = true;
}

bool OAIProjectPermissionList::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (permissions.size() > 0) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIProjectPermissionList::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
