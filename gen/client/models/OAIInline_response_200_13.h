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
 * OAIInline_response_200_13.h
 *
 * 
 */

#ifndef OAIInline_response_200_13_H
#define OAIInline_response_200_13_H

#include <QJsonObject>

#include "models/OAIServiceAccountKey.h"
#include <QList>
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIInline_response_200_13 : public OAIObject {
public:
    OAIInline_response_200_13();
    OAIInline_response_200_13(QString json);
    ~OAIInline_response_200_13() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QList<OAIServiceAccountKey> getKeys() const;
    void setKeys(const QList<OAIServiceAccountKey> &keys);

    QString getNextPageToken() const;
    void setNextPageToken(const QString &next_page_token);

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QList<OAIServiceAccountKey> keys;
    bool m_keys_isSet;
    bool m_keys_isValid;

    QString next_page_token;
    bool m_next_page_token_isSet;
    bool m_next_page_token_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIInline_response_200_13)

#endif // OAIInline_response_200_13_H
