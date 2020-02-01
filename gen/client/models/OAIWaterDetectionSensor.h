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
 * OAIWaterDetectionSensor.h
 *
 * An water detector sensor. 
 */

#ifndef OAIWaterDetectionSensor_H
#define OAIWaterDetectionSensor_H

#include <QJsonObject>

#include "models/OAIAnyOfNetworkStatusEventBatteryStatusEventWaterPresentEventTouchEvent.h"
#include <QList>
#include <QMap>
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIWaterDetectionSensor : public OAIObject {
public:
    OAIWaterDetectionSensor();
    OAIWaterDetectionSensor(QString json);
    ~OAIWaterDetectionSensor() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getName() const;
    void setName(const QString &name);

    QString getType() const;
    void setType(const QString &type);

    QMap<QString, QString> getLabels() const;
    void setLabels(const QMap<QString, QString> &labels);

    OAIAnyOfNetworkStatusEventBatteryStatusEventWaterPresentEventTouchEvent getReported() const;
    void setReported(const OAIAnyOfNetworkStatusEventBatteryStatusEventWaterPresentEventTouchEvent &reported);

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString name;
    bool m_name_isSet;
    bool m_name_isValid;

    QString type;
    bool m_type_isSet;
    bool m_type_isValid;

    QMap<QString, QString> labels;
    bool m_labels_isSet;
    bool m_labels_isValid;

    OAIAnyOfNetworkStatusEventBatteryStatusEventWaterPresentEventTouchEvent reported;
    bool m_reported_isSet;
    bool m_reported_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIWaterDetectionSensor)

#endif // OAIWaterDetectionSensor_H
