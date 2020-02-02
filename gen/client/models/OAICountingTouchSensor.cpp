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

#include "OAICountingTouchSensor.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAICountingTouchSensor::OAICountingTouchSensor(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAICountingTouchSensor::OAICountingTouchSensor() {
    this->initializeModel();
}

OAICountingTouchSensor::~OAICountingTouchSensor() {}

void OAICountingTouchSensor::initializeModel() {

    m_name_isSet = false;
    m_name_isValid = false;

    m_type_isSet = false;
    m_type_isValid = false;

    m_labels_isSet = false;
    m_labels_isValid = false;

    m_reported_isSet = false;
    m_reported_isValid = false;
}

void OAICountingTouchSensor::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAICountingTouchSensor::fromJsonObject(QJsonObject json) {

    m_name_isValid = ::OpenAPI::fromJsonValue(name, json[QString("name")]);
    m_name_isSet = !json[QString("name")].isNull() && m_name_isValid;

    m_type_isValid = ::OpenAPI::fromJsonValue(type, json[QString("type")]);
    m_type_isSet = !json[QString("type")].isNull() && m_type_isValid;

    m_labels_isValid = ::OpenAPI::fromJsonValue(labels, json[QString("labels")]);
    m_labels_isSet = !json[QString("labels")].isNull() && m_labels_isValid;

    m_reported_isValid = ::OpenAPI::fromJsonValue(reported, json[QString("reported")]);
    m_reported_isSet = !json[QString("reported")].isNull() && m_reported_isValid;
}

QString OAICountingTouchSensor::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAICountingTouchSensor::asJsonObject() const {
    QJsonObject obj;
    if (m_name_isSet) {
        obj.insert(QString("name"), ::OpenAPI::toJsonValue(name));
    }
    if (m_type_isSet) {
        obj.insert(QString("type"), ::OpenAPI::toJsonValue(type));
    }
    if (labels.size() > 0) {
        obj.insert(QString("labels"), ::OpenAPI::toJsonValue(labels));
    }
    if (!reported.isEmpty()) {
        obj.insert(QString("reported"), ::OpenAPI::toJsonValue(reported));
    }
    return obj;
}

QString OAICountingTouchSensor::getName() const {
    return name;
}
void OAICountingTouchSensor::setName(const QString &name) {
    this->name = name;
    this->m_name_isSet = true;
}

QString OAICountingTouchSensor::getType() const {
    return type;
}
void OAICountingTouchSensor::setType(const QString &type) {
    this->type = type;
    this->m_type_isSet = true;
}

QMap<QString, QString> OAICountingTouchSensor::getLabels() const {
    return labels;
}
void OAICountingTouchSensor::setLabels(const QMap<QString, QString> &labels) {
    this->labels = labels;
    this->m_labels_isSet = true;
}

bool OAICountingTouchSensor::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_name_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_type_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (labels.size() > 0) {
            isObjectUpdated = true;
            break;
        }

        if (!reported.isEmpty()) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAICountingTouchSensor::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
