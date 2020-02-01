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

#include "OAITouchCount.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAITouchCount::OAITouchCount(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAITouchCount::OAITouchCount() {
    this->initializeModel();
}

OAITouchCount::~OAITouchCount() {}

void OAITouchCount::initializeModel() {

    m_total_isSet = false;
    m_total_isValid = false;

    m_update_time_isSet = false;
    m_update_time_isValid = false;
}

void OAITouchCount::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAITouchCount::fromJsonObject(QJsonObject json) {

    m_total_isValid = ::OpenAPI::fromJsonValue(total, json[QString("total")]);
    m_total_isSet = !json[QString("total")].isNull() && m_total_isValid;

    m_update_time_isValid = ::OpenAPI::fromJsonValue(update_time, json[QString("updateTime")]);
    m_update_time_isSet = !json[QString("updateTime")].isNull() && m_update_time_isValid;
}

QString OAITouchCount::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAITouchCount::asJsonObject() const {
    QJsonObject obj;
    if (m_total_isSet) {
        obj.insert(QString("total"), ::OpenAPI::toJsonValue(total));
    }
    if (m_update_time_isSet) {
        obj.insert(QString("updateTime"), ::OpenAPI::toJsonValue(update_time));
    }
    return obj;
}

qint32 OAITouchCount::getTotal() const {
    return total;
}
void OAITouchCount::setTotal(const qint32 &total) {
    this->total = total;
    this->m_total_isSet = true;
}

QDateTime OAITouchCount::getUpdateTime() const {
    return update_time;
}
void OAITouchCount::setUpdateTime(const QDateTime &update_time) {
    this->update_time = update_time;
    this->m_update_time_isSet = true;
}

bool OAITouchCount::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_total_isSet) {
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

bool OAITouchCount::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
