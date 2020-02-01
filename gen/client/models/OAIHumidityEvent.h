/**
 * API, Disruptive Technologies
 * This api provides access to management, configuration and access to streams of data from Disruptive Technologies sensor solutions. 
 *
 * The version of the OpenAPI document: v2
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

/*
 * OAIHumidityEvent.h
 *
 * 
 */

#ifndef OAIHumidityEvent_H
#define OAIHumidityEvent_H

#include <QJsonObject>

#include "models/OAIHumidity.h"

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIHumidityEvent : public OAIObject {
public:
    OAIHumidityEvent();
    OAIHumidityEvent(QString json);
    ~OAIHumidityEvent() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    OAIHumidity getHumidity() const;
    void setHumidity(const OAIHumidity &humidity);

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    OAIHumidity humidity;
    bool m_humidity_isSet;
    bool m_humidity_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIHumidityEvent)

#endif // OAIHumidityEvent_H
