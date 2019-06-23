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
 * OAIInline_response_200_8.h
 *
 * 
 */

#ifndef OAIInline_response_200_8_H
#define OAIInline_response_200_8_H

#include <QJsonObject>


#include "models/OAIOrganization.h"
#include <QList>
#include <QString>

#include "OAIObject.h"
#include "OAIEnum.h"

namespace OpenAPI {

class OAIInline_response_200_8: public OAIObject {
public:
    OAIInline_response_200_8();
    OAIInline_response_200_8(QString json);
    ~OAIInline_response_200_8() override;

    QString asJson () const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    
    QList<OAIOrganization> getOrganizations() const;
    void setOrganizations(const QList<OAIOrganization> &organizations);

    
    QString getNextPageToken() const;
    void setNextPageToken(const QString &next_page_token);

    
    
    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void init();
    
    QList<OAIOrganization> organizations;
    bool m_organizations_isSet;
    bool m_organizations_isValid;
    
    QString next_page_token;
    bool m_next_page_token_isSet;
    bool m_next_page_token_isValid;
    
    };

}

Q_DECLARE_METATYPE(OpenAPI::OAIInline_response_200_8)

#endif // OAIInline_response_200_8_H