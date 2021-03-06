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
 * OAIInline_response_200_3.h
 *
 * 
 */

#ifndef OAIInline_response_200_3_H
#define OAIInline_response_200_3_H

#include <QJsonObject>

#include "models/OAIInline_response_200_1_batchErrors.h"
#include <QList>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIInline_response_200_3 : public OAIObject {
public:
    OAIInline_response_200_3();
    OAIInline_response_200_3(QString json);
    ~OAIInline_response_200_3() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QList<QString> getTransferredDevices() const;
    void setTransferredDevices(const QList<QString> &transferred_devices);

    QList<OAIInline_response_200_1_batchErrors> getTransferErrors() const;
    void setTransferErrors(const QList<OAIInline_response_200_1_batchErrors> &transfer_errors);

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QList<QString> transferred_devices;
    bool m_transferred_devices_isSet;
    bool m_transferred_devices_isValid;

    QList<OAIInline_response_200_1_batchErrors> transfer_errors;
    bool m_transfer_errors_isSet;
    bool m_transfer_errors_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIInline_response_200_3)

#endif // OAIInline_response_200_3_H
