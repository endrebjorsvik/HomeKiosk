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
 * OAIDataConnectorMessage.h
 *
 * 
 */

#ifndef OAIDataConnectorMessage_H
#define OAIDataConnectorMessage_H

#include <QJsonObject>

#include "models/OAIEvent.h"
#include <QList>
#include <QMap>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIDataConnectorMessage : public OAIObject {
public:
    OAIDataConnectorMessage();
    OAIDataConnectorMessage(QString json);
    ~OAIDataConnectorMessage() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    OAIEvent getEvent() const;
    void setEvent(const OAIEvent &event);

    QMap<QString, QString> getLabels() const;
    void setLabels(const QMap<QString, QString> &labels);

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    OAIEvent event;
    bool m_event_isSet;
    bool m_event_isValid;

    QMap<QString, QString> labels;
    bool m_labels_isSet;
    bool m_labels_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIDataConnectorMessage)

#endif // OAIDataConnectorMessage_H
