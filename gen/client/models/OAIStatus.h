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
 * OAIStatus.h
 *
 * Status provides the failure status of an operation. 
 */

#ifndef OAIStatus_H
#define OAIStatus_H

#include <QJsonObject>


#include <QString>

#include "OAIObject.h"
#include "OAIEnum.h"

namespace OpenAPI {

class OAIStatus: public OAIObject {
public:
    OAIStatus();
    OAIStatus(QString json);
    ~OAIStatus() override;

    QString asJson () const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    
    QString getCode() const;
    void setCode(const QString &code);

    
    QString getMessage() const;
    void setMessage(const QString &message);

    
    
    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void init();
    
    QString code;
    bool m_code_isSet;
    bool m_code_isValid;
    
    QString message;
    bool m_message_isSet;
    bool m_message_isValid;
    
    };

}

Q_DECLARE_METATYPE(OpenAPI::OAIStatus)

#endif // OAIStatus_H
