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

#ifndef OAI_OBJECT_H
#define OAI_OBJECT_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QMetaType>

namespace OpenAPI {

class OAIObject {
  public:
    OAIObject() {

    }
    
    OAIObject(QString jsonString) {
        fromJson(jsonString);
    }

    virtual ~OAIObject(){

    }

    virtual QJsonObject asJsonObject() const {
        return jObj;
    }

    virtual QString asJson() const {
        QJsonDocument doc(jObj);
        return doc.toJson(QJsonDocument::Compact);
    }

    virtual void fromJson(QString jsonString) {
        QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
        jObj = doc.object();
    }

    virtual void fromJsonObject(QJsonObject json) {
        jObj = json;
    }

    virtual bool isSet() const {
        return false;
    }

    virtual bool isValid() const {
        return true;
    }
private :
    QJsonObject jObj;
};

}

Q_DECLARE_METATYPE(OpenAPI::OAIObject)

#endif // OAI_OBJECT_H
