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


#include "OAIInline_response_200_3.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIInline_response_200_3::OAIInline_response_200_3(QString json) {
    this->init();
    this->fromJson(json);
}

OAIInline_response_200_3::OAIInline_response_200_3() {
    this->init();
}

OAIInline_response_200_3::~OAIInline_response_200_3() {

}

void
OAIInline_response_200_3::init() {
    
    m_transferred_devices_isSet = false;
    m_transferred_devices_isValid = false;
    
    m_transfer_errors_isSet = false;
    m_transfer_errors_isValid = false;
    }

void
OAIInline_response_200_3::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIInline_response_200_3::fromJsonObject(QJsonObject json) {
    
    
    m_transferred_devices_isValid = ::OpenAPI::fromJsonValue(transferred_devices, json[QString("transferredDevices")]);
    
    
    m_transfer_errors_isValid = ::OpenAPI::fromJsonValue(transfer_errors, json[QString("transferErrors")]);
    
}

QString
OAIInline_response_200_3::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIInline_response_200_3::asJsonObject() const {
    QJsonObject obj;
	
    if(transferred_devices.size() > 0){
        obj.insert(QString("transferredDevices"), ::OpenAPI::toJsonValue(transferred_devices));
    } 
	
    if(transfer_errors.size() > 0){
        obj.insert(QString("transferErrors"), ::OpenAPI::toJsonValue(transfer_errors));
    } 
    return obj;
}


QList<QString>
OAIInline_response_200_3::getTransferredDevices() const {
    return transferred_devices;
}
void
OAIInline_response_200_3::setTransferredDevices(const QList<QString> &transferred_devices) {
    this->transferred_devices = transferred_devices;
    this->m_transferred_devices_isSet = true;
}


QList<OAIInline_response_200_1_batchErrors>
OAIInline_response_200_3::getTransferErrors() const {
    return transfer_errors;
}
void
OAIInline_response_200_3::setTransferErrors(const QList<OAIInline_response_200_1_batchErrors> &transfer_errors) {
    this->transfer_errors = transfer_errors;
    this->m_transfer_errors_isSet = true;
}

bool
OAIInline_response_200_3::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(transferred_devices.size() > 0){ isObjectUpdated = true; break;}
    
        if(transfer_errors.size() > 0){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIInline_response_200_3::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}

