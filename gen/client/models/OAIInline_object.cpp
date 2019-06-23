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


#include "OAIInline_object.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIInline_object::OAIInline_object(QString json) {
    this->init();
    this->fromJson(json);
}

OAIInline_object::OAIInline_object() {
    this->init();
}

OAIInline_object::~OAIInline_object() {

}

void
OAIInline_object::init() {
    
    m_devices_isSet = false;
    m_devices_isValid = false;
    
    m_add_labels_isSet = false;
    m_add_labels_isValid = false;
    
    m_remove_labels_isSet = false;
    m_remove_labels_isValid = false;
    }

void
OAIInline_object::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIInline_object::fromJsonObject(QJsonObject json) {
    
    
    m_devices_isValid = ::OpenAPI::fromJsonValue(devices, json[QString("devices")]);
    
    
    m_add_labels_isValid = ::OpenAPI::fromJsonValue(add_labels, json[QString("addLabels")]);
    
    
    m_remove_labels_isValid = ::OpenAPI::fromJsonValue(remove_labels, json[QString("removeLabels")]);
    
}

QString
OAIInline_object::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIInline_object::asJsonObject() const {
    QJsonObject obj;
	
    if(devices.size() > 0){
        obj.insert(QString("devices"), ::OpenAPI::toJsonValue(devices));
    } 
	
    if(add_labels.size() > 0){
        obj.insert(QString("addLabels"), ::OpenAPI::toJsonValue(add_labels));
    } 
	
    if(remove_labels.size() > 0){
        obj.insert(QString("removeLabels"), ::OpenAPI::toJsonValue(remove_labels));
    } 
    return obj;
}


QList<QString>
OAIInline_object::getDevices() const {
    return devices;
}
void
OAIInline_object::setDevices(const QList<QString> &devices) {
    this->devices = devices;
    this->m_devices_isSet = true;
}


QMap<QString, QString>
OAIInline_object::getAddLabels() const {
    return add_labels;
}
void
OAIInline_object::setAddLabels(const QMap<QString, QString> &add_labels) {
    this->add_labels = add_labels;
    this->m_add_labels_isSet = true;
}


QList<QString>
OAIInline_object::getRemoveLabels() const {
    return remove_labels;
}
void
OAIInline_object::setRemoveLabels(const QList<QString> &remove_labels) {
    this->remove_labels = remove_labels;
    this->m_remove_labels_isSet = true;
}

bool
OAIInline_object::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(devices.size() > 0){ isObjectUpdated = true; break;}
    
        if(add_labels.size() > 0){ isObjectUpdated = true; break;}
    
        if(remove_labels.size() > 0){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIInline_object::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}
