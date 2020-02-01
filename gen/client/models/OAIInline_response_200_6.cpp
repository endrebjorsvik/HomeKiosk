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

#include "OAIInline_response_200_6.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIInline_response_200_6::OAIInline_response_200_6(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIInline_response_200_6::OAIInline_response_200_6() {
    this->initializeModel();
}

OAIInline_response_200_6::~OAIInline_response_200_6() {}

void OAIInline_response_200_6::initializeModel() {

    m_organizations_isSet = false;
    m_organizations_isValid = false;

    m_next_page_token_isSet = false;
    m_next_page_token_isValid = false;
}

void OAIInline_response_200_6::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIInline_response_200_6::fromJsonObject(QJsonObject json) {

    m_organizations_isValid = ::OpenAPI::fromJsonValue(organizations, json[QString("organizations")]);
    m_organizations_isSet = !json[QString("organizations")].isNull() && m_organizations_isValid;

    m_next_page_token_isValid = ::OpenAPI::fromJsonValue(next_page_token, json[QString("nextPageToken")]);
    m_next_page_token_isSet = !json[QString("nextPageToken")].isNull() && m_next_page_token_isValid;
}

QString OAIInline_response_200_6::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIInline_response_200_6::asJsonObject() const {
    QJsonObject obj;
    if (organizations.size() > 0) {
        obj.insert(QString("organizations"), ::OpenAPI::toJsonValue(organizations));
    }
    if (m_next_page_token_isSet) {
        obj.insert(QString("nextPageToken"), ::OpenAPI::toJsonValue(next_page_token));
    }
    return obj;
}

QList<OAIRole> OAIInline_response_200_6::getOrganizations() const {
    return organizations;
}
void OAIInline_response_200_6::setOrganizations(const QList<OAIRole> &organizations) {
    this->organizations = organizations;
    this->m_organizations_isSet = true;
}

QString OAIInline_response_200_6::getNextPageToken() const {
    return next_page_token;
}
void OAIInline_response_200_6::setNextPageToken(const QString &next_page_token) {
    this->next_page_token = next_page_token;
    this->m_next_page_token_isSet = true;
}

bool OAIInline_response_200_6::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (organizations.size() > 0) {
            isObjectUpdated = true;
            break;
        }

        if (m_next_page_token_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIInline_response_200_6::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
