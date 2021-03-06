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

#include "OAIInline_response_200_2.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIInline_response_200_2::OAIInline_response_200_2(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIInline_response_200_2::OAIInline_response_200_2() {
    this->initializeModel();
}

OAIInline_response_200_2::~OAIInline_response_200_2() {}

void OAIInline_response_200_2::initializeModel() {

    m_events_isSet = false;
    m_events_isValid = false;

    m_next_page_token_isSet = false;
    m_next_page_token_isValid = false;
}

void OAIInline_response_200_2::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIInline_response_200_2::fromJsonObject(QJsonObject json) {

    m_events_isValid = ::OpenAPI::fromJsonValue(events, json[QString("events")]);
    m_events_isSet = !json[QString("events")].isNull() && m_events_isValid;

    m_next_page_token_isValid = ::OpenAPI::fromJsonValue(next_page_token, json[QString("nextPageToken")]);
    m_next_page_token_isSet = !json[QString("nextPageToken")].isNull() && m_next_page_token_isValid;
}

QString OAIInline_response_200_2::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIInline_response_200_2::asJsonObject() const {
    QJsonObject obj;
    if (events.size() > 0) {
        obj.insert(QString("events"), ::OpenAPI::toJsonValue(events));
    }
    if (m_next_page_token_isSet) {
        obj.insert(QString("nextPageToken"), ::OpenAPI::toJsonValue(next_page_token));
    }
    return obj;
}

QList<OAIEvent> OAIInline_response_200_2::getEvents() const {
    return events;
}
void OAIInline_response_200_2::setEvents(const QList<OAIEvent> &events) {
    this->events = events;
    this->m_events_isSet = true;
}

QString OAIInline_response_200_2::getNextPageToken() const {
    return next_page_token;
}
void OAIInline_response_200_2::setNextPageToken(const QString &next_page_token) {
    this->next_page_token = next_page_token;
    this->m_next_page_token_isSet = true;
}

bool OAIInline_response_200_2::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (events.size() > 0) {
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

bool OAIInline_response_200_2::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
