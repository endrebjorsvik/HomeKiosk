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


#include "OAIObjectPresentEvent.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIObjectPresentEvent::OAIObjectPresentEvent(QString json) {
    this->init();
    this->fromJson(json);
}

OAIObjectPresentEvent::OAIObjectPresentEvent() {
    this->init();
}

OAIObjectPresentEvent::~OAIObjectPresentEvent() {

}

void
OAIObjectPresentEvent::init() {
    
    m_object_present_isSet = false;
    m_object_present_isValid = false;
    }

void
OAIObjectPresentEvent::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIObjectPresentEvent::fromJsonObject(QJsonObject json) {
    
    m_object_present_isValid = ::OpenAPI::fromJsonValue(object_present, json[QString("objectPresent")]);
    
    
}

QString
OAIObjectPresentEvent::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIObjectPresentEvent::asJsonObject() const {
    QJsonObject obj;
	if(object_present.isSet()){
        obj.insert(QString("objectPresent"), ::OpenAPI::toJsonValue(object_present));
    }
    return obj;
}


OAIObjectPresent
OAIObjectPresentEvent::getObjectPresent() const {
    return object_present;
}
void
OAIObjectPresentEvent::setObjectPresent(const OAIObjectPresent &object_present) {
    this->object_present = object_present;
    this->m_object_present_isSet = true;
}

bool
OAIObjectPresentEvent::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(object_present.isSet()){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIObjectPresentEvent::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}
