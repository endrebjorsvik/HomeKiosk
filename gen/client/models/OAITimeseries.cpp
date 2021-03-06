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

#include "OAITimeseries.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAITimeseries::OAITimeseries(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAITimeseries::OAITimeseries() {
    this->initializeModel();
}

OAITimeseries::~OAITimeseries() {}

void OAITimeseries::initializeModel() {

    m_columns_isSet = false;
    m_columns_isValid = false;

    m_values_isSet = false;
    m_values_isValid = false;
}

void OAITimeseries::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAITimeseries::fromJsonObject(QJsonObject json) {

    m_columns_isValid = ::OpenAPI::fromJsonValue(columns, json[QString("columns")]);
    m_columns_isSet = !json[QString("columns")].isNull() && m_columns_isValid;

    m_values_isValid = ::OpenAPI::fromJsonValue(values, json[QString("values")]);
    m_values_isSet = !json[QString("values")].isNull() && m_values_isValid;
}

QString OAITimeseries::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAITimeseries::asJsonObject() const {
    QJsonObject obj;
    if (columns.size() > 0) {
        obj.insert(QString("columns"), ::OpenAPI::toJsonValue(columns));
    }
    if (values.size() > 0) {
        obj.insert(QString("values"), ::OpenAPI::toJsonValue(values));
    }
    return obj;
}

QList<QString> OAITimeseries::getColumns() const {
    return columns;
}
void OAITimeseries::setColumns(const QList<QString> &columns) {
    this->columns = columns;
    this->m_columns_isSet = true;
}

QList<QString> OAITimeseries::getValues() const {
    return values;
}
void OAITimeseries::setValues(const QList<QString> &values) {
    this->values = values;
    this->m_values_isSet = true;
}

bool OAITimeseries::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (columns.size() > 0) {
            isObjectUpdated = true;
            break;
        }

        if (values.size() > 0) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAITimeseries::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
