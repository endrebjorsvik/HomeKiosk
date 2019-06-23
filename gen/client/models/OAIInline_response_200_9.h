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
 * OAIInline_response_200_9.h
 *
 * 
 */

#ifndef OAIInline_response_200_9_H
#define OAIInline_response_200_9_H

#include <QJsonObject>


#include "models/OAIMember.h"
#include <QList>
#include <QString>

#include "OAIObject.h"
#include "OAIEnum.h"

namespace OpenAPI {

class OAIInline_response_200_9: public OAIObject {
public:
    OAIInline_response_200_9();
    OAIInline_response_200_9(QString json);
    ~OAIInline_response_200_9() override;

    QString asJson () const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    
    QList<OAIMember> getOrganizations() const;
    void setOrganizations(const QList<OAIMember> &organizations);

    
    QString getNextPageToken() const;
    void setNextPageToken(const QString &next_page_token);

    
    
    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void init();
    
    QList<OAIMember> organizations;
    bool m_organizations_isSet;
    bool m_organizations_isValid;
    
    QString next_page_token;
    bool m_next_page_token_isSet;
    bool m_next_page_token_isValid;
    
    };

}

Q_DECLARE_METATYPE(OpenAPI::OAIInline_response_200_9)

#endif // OAIInline_response_200_9_H
