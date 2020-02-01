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

#include "OAICellularStatusEvent.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAICellularStatusEvent::OAICellularStatusEvent(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAICellularStatusEvent::OAICellularStatusEvent() {
    this->initializeModel();
}

OAICellularStatusEvent::~OAICellularStatusEvent() {}

void OAICellularStatusEvent::initializeModel() {

    m_cellular_status_isSet = false;
    m_cellular_status_isValid = false;
}

void OAICellularStatusEvent::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAICellularStatusEvent::fromJsonObject(QJsonObject json) {

    m_cellular_status_isValid = ::OpenAPI::fromJsonValue(cellular_status, json[QString("cellularStatus")]);
    m_cellular_status_isSet = !json[QString("cellularStatus")].isNull() && m_cellular_status_isValid;
}

QString OAICellularStatusEvent::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAICellularStatusEvent::asJsonObject() const {
    QJsonObject obj;
    if (cellular_status.isSet()) {
        obj.insert(QString("cellularStatus"), ::OpenAPI::toJsonValue(cellular_status));
    }
    return obj;
}

OAICellularStatus OAICellularStatusEvent::getCellularStatus() const {
    return cellular_status;
}
void OAICellularStatusEvent::setCellularStatus(const OAICellularStatus &cellular_status) {
    this->cellular_status = cellular_status;
    this->m_cellular_status_isSet = true;
}

bool OAICellularStatusEvent::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (cellular_status.isSet()) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAICellularStatusEvent::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
