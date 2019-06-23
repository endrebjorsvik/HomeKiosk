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
 * OAIEventType.h
 *
 * 
 */

#ifndef OAIEventType_H
#define OAIEventType_H

#include <QJsonObject>



#include "OAIObject.h"
#include "OAIEnum.h"

namespace OpenAPI {

class OAIEventType: public OAIEnum {
public:
    OAIEventType();
    OAIEventType(QString json);
    ~OAIEventType() override;

    QString asJson () const override;
    QJsonValue asJsonValue() const override;
    void fromJsonValue(QJsonValue json) override;
    void fromJson(QString jsonString) override;

    
    enum class eOAIEventType {
        INVALID_VALUE_OPENAPI_GENERATED = 0,
        TOUCH, 
        TEMPERATURE, 
        OBJECTPRESENT, 
        BATTERYSTATUS, 
        NETWORKSTATUS, 
        LABELCHANGED, 
        CONNECTIONSTATUS, 
        ETHERNETSTATUS, 
        CELLULARSTATUS, 
        LATENCYSTATUS
    };

    OAIEventType::eOAIEventType getValue() const;
    void setValue(const OAIEventType::eOAIEventType& value);
    
    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void init();
    
    eOAIEventType m_value;
    bool m_value_isSet;
    bool m_value_isValid;
};

}

Q_DECLARE_METATYPE(OpenAPI::OAIEventType)

#endif // OAIEventType_H