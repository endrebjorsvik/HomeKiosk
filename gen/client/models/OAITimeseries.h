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
 * OAITimeseries.h
 *
 * 
 */

#ifndef OAITimeseries_H
#define OAITimeseries_H

#include <QJsonObject>


#include <QList>

#include "OAIObject.h"
#include "OAIEnum.h"

namespace OpenAPI {

class OAITimeseries: public OAIObject {
public:
    OAITimeseries();
    OAITimeseries(QString json);
    ~OAITimeseries() override;

    QString asJson () const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    
    QList<QString> getColumns() const;
    void setColumns(const QList<QString> &columns);

    
    QList<QString> getValues() const;
    void setValues(const QList<QString> &values);

    
    
    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void init();
    
    QList<QString> columns;
    bool m_columns_isSet;
    bool m_columns_isValid;
    
    QList<QString> values;
    bool m_values_isSet;
    bool m_values_isValid;
    
    };

}

Q_DECLARE_METATYPE(OpenAPI::OAITimeseries)

#endif // OAITimeseries_H
