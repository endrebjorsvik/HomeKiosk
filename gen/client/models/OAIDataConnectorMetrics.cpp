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


#include "OAIDataConnectorMetrics.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIDataConnectorMetrics::OAIDataConnectorMetrics(QString json) {
    this->init();
    this->fromJson(json);
}

OAIDataConnectorMetrics::OAIDataConnectorMetrics() {
    this->init();
}

OAIDataConnectorMetrics::~OAIDataConnectorMetrics() {

}

void
OAIDataConnectorMetrics::init() {
    
    m_success_count_isSet = false;
    m_success_count_isValid = false;
    
    m_error_count_isSet = false;
    m_error_count_isValid = false;
    
    m_latency99p_isSet = false;
    m_latency99p_isValid = false;
    }

void
OAIDataConnectorMetrics::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIDataConnectorMetrics::fromJsonObject(QJsonObject json) {
    
    m_success_count_isValid = ::OpenAPI::fromJsonValue(success_count, json[QString("successCount")]);
    
    
    m_error_count_isValid = ::OpenAPI::fromJsonValue(error_count, json[QString("errorCount")]);
    
    
    m_latency99p_isValid = ::OpenAPI::fromJsonValue(latency99p, json[QString("latency99p")]);
    
    
}

QString
OAIDataConnectorMetrics::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIDataConnectorMetrics::asJsonObject() const {
    QJsonObject obj;
	if(m_success_count_isSet){
        obj.insert(QString("successCount"), ::OpenAPI::toJsonValue(success_count));
    }
	if(m_error_count_isSet){
        obj.insert(QString("errorCount"), ::OpenAPI::toJsonValue(error_count));
    }
	if(m_latency99p_isSet){
        obj.insert(QString("latency99p"), ::OpenAPI::toJsonValue(latency99p));
    }
    return obj;
}


qint32
OAIDataConnectorMetrics::getSuccessCount() const {
    return success_count;
}
void
OAIDataConnectorMetrics::setSuccessCount(const qint32 &success_count) {
    this->success_count = success_count;
    this->m_success_count_isSet = true;
}


qint32
OAIDataConnectorMetrics::getErrorCount() const {
    return error_count;
}
void
OAIDataConnectorMetrics::setErrorCount(const qint32 &error_count) {
    this->error_count = error_count;
    this->m_error_count_isSet = true;
}


QString
OAIDataConnectorMetrics::getLatency99p() const {
    return latency99p;
}
void
OAIDataConnectorMetrics::setLatency99p(const QString &latency99p) {
    this->latency99p = latency99p;
    this->m_latency99p_isSet = true;
}

bool
OAIDataConnectorMetrics::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(m_success_count_isSet){ isObjectUpdated = true; break;}
    
        if(m_error_count_isSet){ isObjectUpdated = true; break;}
    
        if(m_latency99p_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIDataConnectorMetrics::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}
