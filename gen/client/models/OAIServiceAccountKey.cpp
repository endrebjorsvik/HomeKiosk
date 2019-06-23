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


#include "OAIServiceAccountKey.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIServiceAccountKey::OAIServiceAccountKey(QString json) {
    this->init();
    this->fromJson(json);
}

OAIServiceAccountKey::OAIServiceAccountKey() {
    this->init();
}

OAIServiceAccountKey::~OAIServiceAccountKey() {

}

void
OAIServiceAccountKey::init() {
    
    m_name_isSet = false;
    m_name_isValid = false;
    
    m_id_isSet = false;
    m_id_isValid = false;
    
    m_create_time_isSet = false;
    m_create_time_isValid = false;
    }

void
OAIServiceAccountKey::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIServiceAccountKey::fromJsonObject(QJsonObject json) {
    
    m_name_isValid = ::OpenAPI::fromJsonValue(name, json[QString("name")]);
    
    
    m_id_isValid = ::OpenAPI::fromJsonValue(id, json[QString("id")]);
    
    
    m_create_time_isValid = ::OpenAPI::fromJsonValue(create_time, json[QString("createTime")]);
    
    
}

QString
OAIServiceAccountKey::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIServiceAccountKey::asJsonObject() const {
    QJsonObject obj;
	if(m_name_isSet){
        obj.insert(QString("name"), ::OpenAPI::toJsonValue(name));
    }
	if(m_id_isSet){
        obj.insert(QString("id"), ::OpenAPI::toJsonValue(id));
    }
	if(m_create_time_isSet){
        obj.insert(QString("createTime"), ::OpenAPI::toJsonValue(create_time));
    }
    return obj;
}


QString
OAIServiceAccountKey::getName() const {
    return name;
}
void
OAIServiceAccountKey::setName(const QString &name) {
    this->name = name;
    this->m_name_isSet = true;
}


QString
OAIServiceAccountKey::getId() const {
    return id;
}
void
OAIServiceAccountKey::setId(const QString &id) {
    this->id = id;
    this->m_id_isSet = true;
}


QDateTime
OAIServiceAccountKey::getCreateTime() const {
    return create_time;
}
void
OAIServiceAccountKey::setCreateTime(const QDateTime &create_time) {
    this->create_time = create_time;
    this->m_create_time_isSet = true;
}

bool
OAIServiceAccountKey::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(m_name_isSet){ isObjectUpdated = true; break;}
    
        if(m_id_isSet){ isObjectUpdated = true; break;}
    
        if(m_create_time_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIServiceAccountKey::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}
