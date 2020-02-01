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

#include "OAINetworkStatus.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAINetworkStatus::OAINetworkStatus(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAINetworkStatus::OAINetworkStatus() {
    this->initializeModel();
}

OAINetworkStatus::~OAINetworkStatus() {}

void OAINetworkStatus::initializeModel() {

    m_signal_strength_isSet = false;
    m_signal_strength_isValid = false;

    m_update_time_isSet = false;
    m_update_time_isValid = false;

    m_cloud_connectors_isSet = false;
    m_cloud_connectors_isValid = false;

    m_transmission_mode_isSet = false;
    m_transmission_mode_isValid = false;
}

void OAINetworkStatus::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAINetworkStatus::fromJsonObject(QJsonObject json) {

    m_signal_strength_isValid = ::OpenAPI::fromJsonValue(signal_strength, json[QString("signalStrength")]);
    m_signal_strength_isSet = !json[QString("signalStrength")].isNull() && m_signal_strength_isValid;

    m_update_time_isValid = ::OpenAPI::fromJsonValue(update_time, json[QString("updateTime")]);
    m_update_time_isSet = !json[QString("updateTime")].isNull() && m_update_time_isValid;

    m_cloud_connectors_isValid = ::OpenAPI::fromJsonValue(cloud_connectors, json[QString("cloudConnectors")]);
    m_cloud_connectors_isSet = !json[QString("cloudConnectors")].isNull() && m_cloud_connectors_isValid;

    m_transmission_mode_isValid = ::OpenAPI::fromJsonValue(transmission_mode, json[QString("transmissionMode")]);
    m_transmission_mode_isSet = !json[QString("transmissionMode")].isNull() && m_transmission_mode_isValid;
}

QString OAINetworkStatus::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAINetworkStatus::asJsonObject() const {
    QJsonObject obj;
    if (m_signal_strength_isSet) {
        obj.insert(QString("signalStrength"), ::OpenAPI::toJsonValue(signal_strength));
    }
    if (m_update_time_isSet) {
        obj.insert(QString("updateTime"), ::OpenAPI::toJsonValue(update_time));
    }
    if (cloud_connectors.size() > 0) {
        obj.insert(QString("cloudConnectors"), ::OpenAPI::toJsonValue(cloud_connectors));
    }
    if (m_transmission_mode_isSet) {
        obj.insert(QString("transmissionMode"), ::OpenAPI::toJsonValue(transmission_mode));
    }
    return obj;
}

qint32 OAINetworkStatus::getSignalStrength() const {
    return signal_strength;
}
void OAINetworkStatus::setSignalStrength(const qint32 &signal_strength) {
    this->signal_strength = signal_strength;
    this->m_signal_strength_isSet = true;
}

QDateTime OAINetworkStatus::getUpdateTime() const {
    return update_time;
}
void OAINetworkStatus::setUpdateTime(const QDateTime &update_time) {
    this->update_time = update_time;
    this->m_update_time_isSet = true;
}

QList<OAINetworkStatusCloudConnector> OAINetworkStatus::getCloudConnectors() const {
    return cloud_connectors;
}
void OAINetworkStatus::setCloudConnectors(const QList<OAINetworkStatusCloudConnector> &cloud_connectors) {
    this->cloud_connectors = cloud_connectors;
    this->m_cloud_connectors_isSet = true;
}

QString OAINetworkStatus::getTransmissionMode() const {
    return transmission_mode;
}
void OAINetworkStatus::setTransmissionMode(const QString &transmission_mode) {
    this->transmission_mode = transmission_mode;
    this->m_transmission_mode_isSet = true;
}

bool OAINetworkStatus::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_signal_strength_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_update_time_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (cloud_connectors.size() > 0) {
            isObjectUpdated = true;
            break;
        }

        if (m_transmission_mode_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAINetworkStatus::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
