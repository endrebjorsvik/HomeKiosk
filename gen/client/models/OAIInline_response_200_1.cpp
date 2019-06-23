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


#include "OAIInline_response_200_1.h"

#include "OAIHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace OpenAPI {

OAIInline_response_200_1::OAIInline_response_200_1(QString json) {
    this->init();
    this->fromJson(json);
}

OAIInline_response_200_1::OAIInline_response_200_1() {
    this->init();
}

OAIInline_response_200_1::~OAIInline_response_200_1() {

}

void
OAIInline_response_200_1::init() {
    
    m_batch_errors_isSet = false;
    m_batch_errors_isValid = false;
    }

void
OAIInline_response_200_1::fromJson(QString jsonString) {
    QByteArray array (jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void
OAIInline_response_200_1::fromJsonObject(QJsonObject json) {
    
    
    m_batch_errors_isValid = ::OpenAPI::fromJsonValue(batch_errors, json[QString("batchErrors")]);
    
}

QString
OAIInline_response_200_1::asJson () const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
OAIInline_response_200_1::asJsonObject() const {
    QJsonObject obj;
	
    if(batch_errors.size() > 0){
        obj.insert(QString("batchErrors"), ::OpenAPI::toJsonValue(batch_errors));
    } 
    return obj;
}


QList<OAIInline_response_200_1_batchErrors>
OAIInline_response_200_1::getBatchErrors() const {
    return batch_errors;
}
void
OAIInline_response_200_1::setBatchErrors(const QList<OAIInline_response_200_1_batchErrors> &batch_errors) {
    this->batch_errors = batch_errors;
    this->m_batch_errors_isSet = true;
}

bool
OAIInline_response_200_1::isSet() const {
    bool isObjectUpdated = false;
    do{ 
        if(batch_errors.size() > 0){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}

bool
OAIInline_response_200_1::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

}
