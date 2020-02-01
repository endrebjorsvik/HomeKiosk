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
 * OAIInline_response_200_1.h
 *
 * 
 */

#ifndef OAIInline_response_200_1_H
#define OAIInline_response_200_1_H

#include <QJsonObject>

#include "models/OAIInline_response_200_1_batchErrors.h"
#include <QList>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIInline_response_200_1 : public OAIObject {
public:
    OAIInline_response_200_1();
    OAIInline_response_200_1(QString json);
    ~OAIInline_response_200_1() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QList<OAIInline_response_200_1_batchErrors> getBatchErrors() const;
    void setBatchErrors(const QList<OAIInline_response_200_1_batchErrors> &batch_errors);

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QList<OAIInline_response_200_1_batchErrors> batch_errors;
    bool m_batch_errors_isSet;
    bool m_batch_errors_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIInline_response_200_1)

#endif // OAIInline_response_200_1_H
