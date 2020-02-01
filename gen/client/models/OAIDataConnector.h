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
 * OAIDataConnector.h
 *
 * 
 */

#ifndef OAIDataConnector_H
#define OAIDataConnector_H

#include <QJsonObject>

#include "models/OAIDataConnector_httpConfig.h"
#include "models/OAIEventType.h"
#include <QList>
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIDataConnector : public OAIObject {
public:
    OAIDataConnector();
    OAIDataConnector(QString json);
    ~OAIDataConnector() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getName() const;
    void setName(const QString &name);

    QString getDisplayName() const;
    void setDisplayName(const QString &display_name);

    QString getType() const;
    void setType(const QString &type);

    QString getStatus() const;
    void setStatus(const QString &status);

    QList<OAIEventType> getEvents() const;
    void setEvents(const QList<OAIEventType> &events);

    QList<QString> getLabels() const;
    void setLabels(const QList<QString> &labels);

    OAIDataConnector_httpConfig getHttpConfig() const;
    void setHttpConfig(const OAIDataConnector_httpConfig &http_config);

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString name;
    bool m_name_isSet;
    bool m_name_isValid;

    QString display_name;
    bool m_display_name_isSet;
    bool m_display_name_isValid;

    QString type;
    bool m_type_isSet;
    bool m_type_isValid;

    QString status;
    bool m_status_isSet;
    bool m_status_isValid;

    QList<OAIEventType> events;
    bool m_events_isSet;
    bool m_events_isValid;

    QList<QString> labels;
    bool m_labels_isSet;
    bool m_labels_isValid;

    OAIDataConnector_httpConfig http_config;
    bool m_http_config_isSet;
    bool m_http_config_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIDataConnector)

#endif // OAIDataConnector_H
