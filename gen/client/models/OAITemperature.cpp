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


#include "OAITemperature.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAITemperature::OAITemperature(QString json) {
    this->init();
    this->fromJson(json);
}

OAITemperature::OAITemperature() {
    this->init();
}

OAITemperature::~OAITemperature() {

}

void
OAITemperature::init() {
    
    m_value_isSet = false;
    m_value_isValid = false;
    
    m_update_time_isSet = false;
    m_update_time_isValid = false;
    }

void
OAITemperature::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAITemperature::fromJsonObject(QJsonObject json) {
    
    m_value_isValid = ::OpenAPI::fromJsonValue(value, json[QString("value")]);
    
    
    m_update_time_isValid = ::OpenAPI::fromJsonValue(update_time, json[QString("updateTime")]);
    
    
}

QString
OAITemperature::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAITemperature::asJsonObject() const {
    QJsonObject obj;
	if(m_value_isSet){
        obj.insert(QString("value"), ::OpenAPI::toJsonValue(value));
    }
	if(m_update_time_isSet){
        obj.insert(QString("updateTime"), ::OpenAPI::toJsonValue(update_time));
    }
    return obj;
}


float
OAITemperature::getValue() const {
    return value;
}
void
OAITemperature::setValue(const float &value) {
    this->value = value;
    this->m_value_isSet = true;
}


QDateTime
OAITemperature::getUpdateTime() const {
    return update_time;
}
void
OAITemperature::setUpdateTime(const QDateTime &update_time) {
    this->update_time = update_time;
    this->m_update_time_isSet = true;
}

bool
OAITemperature::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(m_value_isSet){ isObjectUpdated = true; break;}
    
        if(m_update_time_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAITemperature::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}

