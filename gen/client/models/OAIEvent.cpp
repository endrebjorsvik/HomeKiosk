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


#include "OAIEvent.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIEvent::OAIEvent(QString json) {
    this->init();
    this->fromJson(json);
}

OAIEvent::OAIEvent() {
    this->init();
}

OAIEvent::~OAIEvent() {

}

void
OAIEvent::init() {
    
    m_event_id_isSet = false;
    m_event_id_isValid = false;
    
    m_target_name_isSet = false;
    m_target_name_isValid = false;
    
    m_event_type_isSet = false;
    m_event_type_isValid = false;
    
    m_data_isSet = false;
    m_data_isValid = false;
    
    m_timestamp_isSet = false;
    m_timestamp_isValid = false;
    
    m_labels_isSet = false;
    m_labels_isValid = false;
    }

void
OAIEvent::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIEvent::fromJsonObject(QJsonObject json) {
    
    m_event_id_isValid = ::OpenAPI::fromJsonValue(event_id, json[QString("eventId")]);
    
    
    m_target_name_isValid = ::OpenAPI::fromJsonValue(target_name, json[QString("targetName")]);
    
    
    m_event_type_isValid = ::OpenAPI::fromJsonValue(event_type, json[QString("eventType")]);
    
    
    m_data_isValid = ::OpenAPI::fromJsonValue(data, json[QString("data")]);
    
    
    m_timestamp_isValid = ::OpenAPI::fromJsonValue(timestamp, json[QString("timestamp")]);
    
    
    
    m_labels_isValid = ::OpenAPI::fromJsonValue(labels, json[QString("labels")]);
    
}

QString
OAIEvent::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIEvent::asJsonObject() const {
    QJsonObject obj;
	if(m_event_id_isSet){
        obj.insert(QString("eventId"), ::OpenAPI::toJsonValue(event_id));
    }
	if(m_target_name_isSet){
        obj.insert(QString("targetName"), ::OpenAPI::toJsonValue(target_name));
    }
	if(event_type.isSet()){
        obj.insert(QString("eventType"), ::OpenAPI::toJsonValue(event_type));
    }
	if(data.isSet()){
        obj.insert(QString("data"), ::OpenAPI::toJsonValue(data));
    }
	if(m_timestamp_isSet){
        obj.insert(QString("timestamp"), ::OpenAPI::toJsonValue(timestamp));
    }
	
    if(labels.size() > 0){
        obj.insert(QString("labels"), ::OpenAPI::toJsonValue(labels));
    } 
    return obj;
}


QString
OAIEvent::getEventId() const {
    return event_id;
}
void
OAIEvent::setEventId(const QString &event_id) {
    this->event_id = event_id;
    this->m_event_id_isSet = true;
}


QString
OAIEvent::getTargetName() const {
    return target_name;
}
void
OAIEvent::setTargetName(const QString &target_name) {
    this->target_name = target_name;
    this->m_target_name_isSet = true;
}


OAIEventType
OAIEvent::getEventType() const {
    return event_type;
}
void
OAIEvent::setEventType(const OAIEventType &event_type) {
    this->event_type = event_type;
    this->m_event_type_isSet = true;
}


OAIOneOfTouchEventTemperatureEventObjectPresentEventBatteryStatusEventNetworkStatusEventLabelsChangedEventConnectionStatusEventEthernetStatusEventCellularStatusEventConnectionLatencyEvent
OAIEvent::getData() const {
    return data;
}
void
OAIEvent::setData(const OAIOneOfTouchEventTemperatureEventObjectPresentEventBatteryStatusEventNetworkStatusEventLabelsChangedEventConnectionStatusEventEthernetStatusEventCellularStatusEventConnectionLatencyEvent &data) {
    this->data = data;
    this->m_data_isSet = true;
}


QDateTime
OAIEvent::getTimestamp() const {
    return timestamp;
}
void
OAIEvent::setTimestamp(const QDateTime &timestamp) {
    this->timestamp = timestamp;
    this->m_timestamp_isSet = true;
}


QMap<QString, QString>
OAIEvent::getLabels() const {
    return labels;
}
void
OAIEvent::setLabels(const QMap<QString, QString> &labels) {
    this->labels = labels;
    this->m_labels_isSet = true;
}

bool
OAIEvent::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(m_event_id_isSet){ isObjectUpdated = true; break;}
    
        if(m_target_name_isSet){ isObjectUpdated = true; break;}
    
        if(event_type.isSet()){ isObjectUpdated = true; break;}
    
        if(data.isSet()){ isObjectUpdated = true; break;}
    
        if(m_timestamp_isSet){ isObjectUpdated = true; break;}
    
        if(labels.size() > 0){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIEvent::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}

