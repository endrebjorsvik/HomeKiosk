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


#include "OAILabelsChangedEvent.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAILabelsChangedEvent::OAILabelsChangedEvent(QString json) {
    this->init();
    this->fromJson(json);
}

OAILabelsChangedEvent::OAILabelsChangedEvent() {
    this->init();
}

OAILabelsChangedEvent::~OAILabelsChangedEvent() {

}

void
OAILabelsChangedEvent::init() {
    
    m_added_isSet = false;
    m_added_isValid = false;
    
    m_modified_isSet = false;
    m_modified_isValid = false;
    
    m_removed_isSet = false;
    m_removed_isValid = false;
    }

void
OAILabelsChangedEvent::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAILabelsChangedEvent::fromJsonObject(QJsonObject json) {
    
    
    m_added_isValid = ::OpenAPI::fromJsonValue(added, json[QString("added")]);
    
    
    m_modified_isValid = ::OpenAPI::fromJsonValue(modified, json[QString("modified")]);
    
    
    m_removed_isValid = ::OpenAPI::fromJsonValue(removed, json[QString("removed")]);
    
}

QString
OAILabelsChangedEvent::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAILabelsChangedEvent::asJsonObject() const {
    QJsonObject obj;
	
    if(added.size() > 0){
        obj.insert(QString("added"), ::OpenAPI::toJsonValue(added));
    } 
	
    if(modified.size() > 0){
        obj.insert(QString("modified"), ::OpenAPI::toJsonValue(modified));
    } 
	
    if(removed.size() > 0){
        obj.insert(QString("removed"), ::OpenAPI::toJsonValue(removed));
    } 
    return obj;
}


QMap<QString, QString>
OAILabelsChangedEvent::getAdded() const {
    return added;
}
void
OAILabelsChangedEvent::setAdded(const QMap<QString, QString> &added) {
    this->added = added;
    this->m_added_isSet = true;
}


QMap<QString, QString>
OAILabelsChangedEvent::getModified() const {
    return modified;
}
void
OAILabelsChangedEvent::setModified(const QMap<QString, QString> &modified) {
    this->modified = modified;
    this->m_modified_isSet = true;
}


QList<QString>
OAILabelsChangedEvent::getRemoved() const {
    return removed;
}
void
OAILabelsChangedEvent::setRemoved(const QList<QString> &removed) {
    this->removed = removed;
    this->m_removed_isSet = true;
}

bool
OAILabelsChangedEvent::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(added.size() > 0){ isObjectUpdated = true; break;}
    
        if(modified.size() > 0){ isObjectUpdated = true; break;}
    
        if(removed.size() > 0){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAILabelsChangedEvent::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}

