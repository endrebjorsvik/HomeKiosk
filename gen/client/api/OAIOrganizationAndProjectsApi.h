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

#ifndef OAI_OAIOrganizationAndProjectsApi_H
#define OAI_OAIOrganizationAndProjectsApi_H

#include "OAIHttpRequest.h"

#include "models/OAIInline_response_200_11.h"
#include "models/OAIInline_response_200_8.h"
#include "models/OAIObject.h"
#include "models/OAIOrganization.h"
#include "models/OAIProject.h"
#include "models/UNKNOWN_BASE_TYPE.h"
#include <QString>

#include <QObject>

namespace OpenAPI {

class OAIOrganizationAndProjectsApi : public QObject {
    Q_OBJECT

public:
    OAIOrganizationAndProjectsApi(const QString &scheme = "https", const QString &host = "api.disruptive-technologies.com", int port = 0, const QString &basePath = "/v2", const int timeOut = 0);
    ~OAIOrganizationAndProjectsApi();

    void setScheme(const QString &scheme);
    void setHost(const QString &host);
    void setPort(int port);
    void setBasePath(const QString &basePath);
    void setTimeOut(const int timeOut);
    void setWorkingDirectory(const QString &path);
    void addHeaders(const QString &key, const QString &value);
    void enableRequestCompression();
    void enableResponseCompression();
    void abortRequests();

    void organizationsGet(const QString &page_size, const QString &page_token);
    void organizationsOrganizationGet(const QString &organization);
    void projectsGet(const QString &page_size, const QString &page_token, const QString &organization, const QString &query);
    void projectsPost(const UNKNOWN_BASE_TYPE &unknown_base_type);
    void projectsProjectDelete(const QString &project);
    void projectsProjectGet(const QString &project);
    void projectsProjectPatch(const QString &project, const UNKNOWN_BASE_TYPE &unknown_base_type);

private:
    QString _scheme, _host;
    int _port;
    QString _basePath;
    int _timeOut;
    QString _workingDirectory;
    QMap<QString, QString> defaultHeaders;
    bool isResponseCompressionEnabled;
    bool isRequestCompressionEnabled;

    void organizationsGetCallback(OAIHttpRequestWorker *worker);
    void organizationsOrganizationGetCallback(OAIHttpRequestWorker *worker);
    void projectsGetCallback(OAIHttpRequestWorker *worker);
    void projectsPostCallback(OAIHttpRequestWorker *worker);
    void projectsProjectDeleteCallback(OAIHttpRequestWorker *worker);
    void projectsProjectGetCallback(OAIHttpRequestWorker *worker);
    void projectsProjectPatchCallback(OAIHttpRequestWorker *worker);

signals:

    void organizationsGetSignal(OAIInline_response_200_8 summary);
    void organizationsOrganizationGetSignal(OAIOrganization summary);
    void projectsGetSignal(OAIInline_response_200_11 summary);
    void projectsPostSignal(OAIProject summary);
    void projectsProjectDeleteSignal();
    void projectsProjectGetSignal(OAIProject summary);
    void projectsProjectPatchSignal(OAIProject summary);

    void organizationsGetSignalFull(OAIHttpRequestWorker *worker, OAIInline_response_200_8 summary);
    void organizationsOrganizationGetSignalFull(OAIHttpRequestWorker *worker, OAIOrganization summary);
    void projectsGetSignalFull(OAIHttpRequestWorker *worker, OAIInline_response_200_11 summary);
    void projectsPostSignalFull(OAIHttpRequestWorker *worker, OAIProject summary);
    void projectsProjectDeleteSignalFull(OAIHttpRequestWorker *worker);
    void projectsProjectGetSignalFull(OAIHttpRequestWorker *worker, OAIProject summary);
    void projectsProjectPatchSignalFull(OAIHttpRequestWorker *worker, OAIProject summary);

    void organizationsGetSignalE(OAIInline_response_200_8 summary, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationGetSignalE(OAIOrganization summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsGetSignalE(OAIInline_response_200_11 summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsPostSignalE(OAIProject summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDeleteSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectGetSignalE(OAIProject summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectPatchSignalE(OAIProject summary, QNetworkReply::NetworkError error_type, QString error_str);

    void organizationsGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsPostSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDeleteSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectPatchSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);

    void abortRequestsSignal(); 
};

} // namespace OpenAPI
#endif
