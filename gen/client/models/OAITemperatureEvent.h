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
 * OAITemperatureEvent.h
 *
 * 
 */

#ifndef OAITemperatureEvent_H
#define OAITemperatureEvent_H

#include <QJsonObject>


#include "models/OAITemperature.h"

#include "OAIObject.h"
#include "OAIEnum.h"

namespace OpenAPI {

class OAITemperatureEvent: public OAIObject {
public:
    OAITemperatureEvent();
    OAITemperatureEvent(QString json);
    ~OAITemperatureEvent() override;

    QString asJson () const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    
    OAITemperature getTemperature() const;
    void setTemperature(const OAITemperature &temperature);

    
    
    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void init();
    
    OAITemperature temperature;
    bool m_temperature_isSet;
    bool m_temperature_isValid;
    
    };

}

Q_DECLARE_METATYPE(OpenAPI::OAITemperatureEvent)

#endif // OAITemperatureEvent_H
