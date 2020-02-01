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
 * OAIObjectPresent.h
 *
 * 
 */

#ifndef OAIObjectPresent_H
#define OAIObjectPresent_H

#include <QJsonObject>

#include <QDateTime>
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIObjectPresent : public OAIObject {
public:
    OAIObjectPresent();
    OAIObjectPresent(QString json);
    ~OAIObjectPresent() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getState() const;
    void setState(const QString &state);

    QDateTime getUpdateTime() const;
    void setUpdateTime(const QDateTime &update_time);

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString state;
    bool m_state_isSet;
    bool m_state_isValid;

    QDateTime update_time;
    bool m_update_time_isSet;
    bool m_update_time_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIObjectPresent)

#endif // OAIObjectPresent_H
