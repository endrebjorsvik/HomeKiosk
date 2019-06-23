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

/*
 * OAIConnectionLatencyEvent.h
 *
 * 
 */

#ifndef OAIConnectionLatencyEvent_H
#define OAIConnectionLatencyEvent_H

#include <QJsonObject>


#include "models/OAIConnectionLatency.h"

#include "OAIObject.h"
#include "OAIEnum.h"

namespace OpenAPI {

class OAIConnectionLatencyEvent: public OAIObject {
public:
    OAIConnectionLatencyEvent();
    OAIConnectionLatencyEvent(QString json);
    ~OAIConnectionLatencyEvent() override;

    QString asJson () const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    
    OAIConnectionLatency getLatencyStatus() const;
    void setLatencyStatus(const OAIConnectionLatency &latency_status);

    
    
    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void init();
    
    OAIConnectionLatency latency_status;
    bool m_latency_status_isSet;
    bool m_latency_status_isValid;
    
    };

}

Q_DECLARE_METATYPE(OpenAPI::OAIConnectionLatencyEvent)

#endif // OAIConnectionLatencyEvent_H