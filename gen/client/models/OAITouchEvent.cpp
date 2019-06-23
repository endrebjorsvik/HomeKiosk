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


#include "OAITouchEvent.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAITouchEvent::OAITouchEvent(QString json) {
    this->init();
    this->fromJson(json);
}

OAITouchEvent::OAITouchEvent() {
    this->init();
}

OAITouchEvent::~OAITouchEvent() {

}

void
OAITouchEvent::init() {
    
    m_touch_isSet = false;
    m_touch_isValid = false;
    }

void
OAITouchEvent::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAITouchEvent::fromJsonObject(QJsonObject json) {
    
    m_touch_isValid = ::OpenAPI::fromJsonValue(touch, json[QString("touch")]);
    
    
}

QString
OAITouchEvent::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAITouchEvent::asJsonObject() const {
    QJsonObject obj;
	if(touch.isSet()){
        obj.insert(QString("touch"), ::OpenAPI::toJsonValue(touch));
    }
    return obj;
}


OAITouch
OAITouchEvent::getTouch() const {
    return touch;
}
void
OAITouchEvent::setTouch(const OAITouch &touch) {
    this->touch = touch;
    this->m_touch_isSet = true;
}

bool
OAITouchEvent::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(touch.isSet()){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAITouchEvent::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}
