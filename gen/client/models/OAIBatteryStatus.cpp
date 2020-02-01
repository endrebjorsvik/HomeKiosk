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

#include "OAIBatteryStatus.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIBatteryStatus::OAIBatteryStatus(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIBatteryStatus::OAIBatteryStatus() {
    this->initializeModel();
}

OAIBatteryStatus::~OAIBatteryStatus() {}

void OAIBatteryStatus::initializeModel() {

    m_percentage_isSet = false;
    m_percentage_isValid = false;

    m_update_time_isSet = false;
    m_update_time_isValid = false;
}

void OAIBatteryStatus::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIBatteryStatus::fromJsonObject(QJsonObject json) {

    m_percentage_isValid = ::OpenAPI::fromJsonValue(percentage, json[QString("percentage")]);
    m_percentage_isSet = !json[QString("percentage")].isNull() && m_percentage_isValid;

    m_update_time_isValid = ::OpenAPI::fromJsonValue(update_time, json[QString("updateTime")]);
    m_update_time_isSet = !json[QString("updateTime")].isNull() && m_update_time_isValid;
}

QString OAIBatteryStatus::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIBatteryStatus::asJsonObject() const {
    QJsonObject obj;
    if (m_percentage_isSet) {
        obj.insert(QString("percentage"), ::OpenAPI::toJsonValue(percentage));
    }
    if (m_update_time_isSet) {
        obj.insert(QString("updateTime"), ::OpenAPI::toJsonValue(update_time));
    }
    return obj;
}

qint32 OAIBatteryStatus::getPercentage() const {
    return percentage;
}
void OAIBatteryStatus::setPercentage(const qint32 &percentage) {
    this->percentage = percentage;
    this->m_percentage_isSet = true;
}

QDateTime OAIBatteryStatus::getUpdateTime() const {
    return update_time;
}
void OAIBatteryStatus::setUpdateTime(const QDateTime &update_time) {
    this->update_time = update_time;
    this->m_update_time_isSet = true;
}

bool OAIBatteryStatus::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_percentage_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_update_time_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIBatteryStatus::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
