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
 * OAINetworkStatus.h
 *
 * 
 */

#ifndef OAINetworkStatus_H
#define OAINetworkStatus_H

#include <QJsonObject>


#include "models/OAINetworkStatusCloudConnector.h"
#include <QDateTime>
#include <QList>
#include <QString>

#include "OAIObject.h"
#include "OAIEnum.h"

namespace OpenAPI {

class OAINetworkStatus: public OAIObject {
public:
    OAINetworkStatus();
    OAINetworkStatus(QString json);
    ~OAINetworkStatus() override;

    QString asJson () const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    
    qint32 getSignalStrength() const;
    void setSignalStrength(const qint32 &signal_strength);

    
    QDateTime getUpdateTime() const;
    void setUpdateTime(const QDateTime &update_time);

    
    QList<OAINetworkStatusCloudConnector> getCloudConnectors() const;
    void setCloudConnectors(const QList<OAINetworkStatusCloudConnector> &cloud_connectors);

    
    QString getTransmissionMode() const;
    void setTransmissionMode(const QString &transmission_mode);

    
    
    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void init();
    
    qint32 signal_strength;
    bool m_signal_strength_isSet;
    bool m_signal_strength_isValid;
    
    QDateTime update_time;
    bool m_update_time_isSet;
    bool m_update_time_isValid;
    
    QList<OAINetworkStatusCloudConnector> cloud_connectors;
    bool m_cloud_connectors_isSet;
    bool m_cloud_connectors_isValid;
    
    QString transmission_mode;
    bool m_transmission_mode_isSet;
    bool m_transmission_mode_isValid;
    
    };

}

Q_DECLARE_METATYPE(OpenAPI::OAINetworkStatus)

#endif // OAINetworkStatus_H
