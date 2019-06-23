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
 * OAIObjectPresentEvent.h
 *
 * 
 */

#ifndef OAIObjectPresentEvent_H
#define OAIObjectPresentEvent_H

#include <QJsonObject>


#include "models/OAIObjectPresent.h"

#include "OAIObject.h"
#include "OAIEnum.h"

namespace OpenAPI {

class OAIObjectPresentEvent: public OAIObject {
public:
    OAIObjectPresentEvent();
    OAIObjectPresentEvent(QString json);
    ~OAIObjectPresentEvent() override;

    QString asJson () const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    
    OAIObjectPresent getObjectPresent() const;
    void setObjectPresent(const OAIObjectPresent &object_present);

    
    
    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void init();
    
    OAIObjectPresent object_present;
    bool m_object_present_isSet;
    bool m_object_present_isValid;
    
    };

}

Q_DECLARE_METATYPE(OpenAPI::OAIObjectPresentEvent)

#endif // OAIObjectPresentEvent_H