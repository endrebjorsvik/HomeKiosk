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
 * OAIServiceAccountKeyWithSecret.h
 *
 * A key grants access to act as the service account the key belongs to.  The secret of a service account key is only returned once on creation of the key, and cannot be recreated or downloaded later. 
 */

#ifndef OAIServiceAccountKeyWithSecret_H
#define OAIServiceAccountKeyWithSecret_H

#include <QJsonObject>

#include "models/OAIServiceAccountKey.h"
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIServiceAccountKeyWithSecret : public OAIObject {
public:
    OAIServiceAccountKeyWithSecret();
    OAIServiceAccountKeyWithSecret(QString json);
    ~OAIServiceAccountKeyWithSecret() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    OAIServiceAccountKey getKey() const;
    void setKey(const OAIServiceAccountKey &key);

    QString getSecret() const;
    void setSecret(const QString &secret);

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    OAIServiceAccountKey key;
    bool m_key_isSet;
    bool m_key_isValid;

    QString secret;
    bool m_secret_isSet;
    bool m_secret_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIServiceAccountKeyWithSecret)

#endif // OAIServiceAccountKeyWithSecret_H
