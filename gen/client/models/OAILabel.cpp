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


#include "OAILabel.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAILabel::OAILabel(QString json) {
    this->init();
    this->fromJson(json);
}

OAILabel::OAILabel() {
    this->init();
}

OAILabel::~OAILabel() {

}

void
OAILabel::init() {
    
    m_name_isSet = false;
    m_name_isValid = false;
    
    m_key_isSet = false;
    m_key_isValid = false;
    
    m_value_isSet = false;
    m_value_isValid = false;
    }

void
OAILabel::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAILabel::fromJsonObject(QJsonObject json) {
    
    m_name_isValid = ::OpenAPI::fromJsonValue(name, json[QString("name")]);
    
    
    m_key_isValid = ::OpenAPI::fromJsonValue(key, json[QString("key")]);
    
    
    m_value_isValid = ::OpenAPI::fromJsonValue(value, json[QString("value")]);
    
    
}

QString
OAILabel::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAILabel::asJsonObject() const {
    QJsonObject obj;
	if(m_name_isSet){
        obj.insert(QString("name"), ::OpenAPI::toJsonValue(name));
    }
	if(m_key_isSet){
        obj.insert(QString("key"), ::OpenAPI::toJsonValue(key));
    }
	if(m_value_isSet){
        obj.insert(QString("value"), ::OpenAPI::toJsonValue(value));
    }
    return obj;
}


QString
OAILabel::getName() const {
    return name;
}
void
OAILabel::setName(const QString &name) {
    this->name = name;
    this->m_name_isSet = true;
}


QString
OAILabel::getKey() const {
    return key;
}
void
OAILabel::setKey(const QString &key) {
    this->key = key;
    this->m_key_isSet = true;
}


QString
OAILabel::getValue() const {
    return value;
}
void
OAILabel::setValue(const QString &value) {
    this->value = value;
    this->m_value_isSet = true;
}

bool
OAILabel::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(m_name_isSet){ isObjectUpdated = true; break;}
    
        if(m_key_isSet){ isObjectUpdated = true; break;}
    
        if(m_value_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAILabel::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}

