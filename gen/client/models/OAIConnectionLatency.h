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
 * OAIConnectionLatency.h
 *
 * 
 */

#ifndef OAIConnectionLatency_H
#define OAIConnectionLatency_H

#include <QJsonObject>


#include <QDateTime>

#include "OAIObject.h"
#include "OAIEnum.h"

namespace OpenAPI {

class OAIConnectionLatency: public OAIObject {
public:
    OAIConnectionLatency();
    OAIConnectionLatency(QString json);
    ~OAIConnectionLatency() override;

    QString asJson () const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    
    qint32 getAvgLatencyMillis() const;
    void setAvgLatencyMillis(const qint32 &avg_latency_millis);

    
    qint32 getMinLatencyMillis() const;
    void setMinLatencyMillis(const qint32 &min_latency_millis);

    
    qint32 getMaxLatencyMillis() const;
    void setMaxLatencyMillis(const qint32 &max_latency_millis);

    
    QDateTime getUpdateTime() const;
    void setUpdateTime(const QDateTime &update_time);

    
    
    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void init();
    
    qint32 avg_latency_millis;
    bool m_avg_latency_millis_isSet;
    bool m_avg_latency_millis_isValid;
    
    qint32 min_latency_millis;
    bool m_min_latency_millis_isSet;
    bool m_min_latency_millis_isValid;
    
    qint32 max_latency_millis;
    bool m_max_latency_millis_isSet;
    bool m_max_latency_millis_isValid;
    
    QDateTime update_time;
    bool m_update_time_isSet;
    bool m_update_time_isValid;
    
    };

}

Q_DECLARE_METATYPE(OpenAPI::OAIConnectionLatency)

#endif // OAIConnectionLatency_H