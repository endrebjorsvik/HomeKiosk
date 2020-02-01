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
 * OAIInline_response_200_10.h
 *
 * 
 */

#ifndef OAIInline_response_200_10_H
#define OAIInline_response_200_10_H

#include <QJsonObject>

#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIInline_response_200_10 : public OAIObject {
public:
    OAIInline_response_200_10();
    OAIInline_response_200_10(QString json);
    ~OAIInline_response_200_10() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getInviteUrl() const;
    void setInviteUrl(const QString &invite_url);

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString invite_url;
    bool m_invite_url_isSet;
    bool m_invite_url_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIInline_response_200_10)

#endif // OAIInline_response_200_10_H
