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
 * OAIConnectionStatusEvent.h
 *
 * 
 */

#ifndef OAIConnectionStatusEvent_H
#define OAIConnectionStatusEvent_H

#include <QJsonObject>

#include "models/OAIConnectionStatus.h"

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIConnectionStatusEvent : public OAIObject {
public:
    OAIConnectionStatusEvent();
    OAIConnectionStatusEvent(QString json);
    ~OAIConnectionStatusEvent() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    OAIConnectionStatus getConnectionStatus() const;
    void setConnectionStatus(const OAIConnectionStatus &connection_status);

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    OAIConnectionStatus connection_status;
    bool m_connection_status_isSet;
    bool m_connection_status_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIConnectionStatusEvent)

#endif // OAIConnectionStatusEvent_H
