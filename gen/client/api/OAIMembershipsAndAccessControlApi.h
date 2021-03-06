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

#ifndef OAI_OAIMembershipsAndAccessControlApi_H
#define OAI_OAIMembershipsAndAccessControlApi_H

#include "OAIHttpRequest.h"

#include "models/OAIErrorMessage.h"
#include "models/OAIInline_object_2.h"
#include "models/OAIInline_object_3.h"
#include "models/OAIInline_response_200_10.h"
#include "models/OAIInline_response_200_6.h"
#include "models/OAIInline_response_200_7.h"
#include "models/OAIInline_response_200_9.h"
#include "models/OAIMember.h"
#include "models/OAIOrganizationPermissionList.h"
#include "models/OAIProjectPermissionList.h"
#include <QString>

#include <QObject>

namespace OpenAPI {

class OAIMembershipsAndAccessControlApi : public QObject {
    Q_OBJECT

public:
    OAIMembershipsAndAccessControlApi(const QString &scheme = "https", const QString &host = "api.disruptive-technologies.com", int port = 0, const QString &basePath = "/v2", const int timeOut = 0);
    ~OAIMembershipsAndAccessControlApi();

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

    void organizationsOrganizationMembersGet(const QString &organization, const QString &page_size, const QString &page_token);
    void organizationsOrganizationMembersMemberDelete(const QString &organization, const QString &member);
    void organizationsOrganizationMembersMemberGet(const QString &organization, const QString &member);
    void organizationsOrganizationMembersMemberPatch(const QString &organization, const QString &member, const QString &update_mask, const OAIMember &oai_member);
    void organizationsOrganizationMembersMembergetInviteUrlGet(const QString &organization, const QString &member);
    void organizationsOrganizationMembersPost(const QString &organization, const OAIInline_object_2 &oai_inline_object_2);
    void organizationsOrganizationPermissionsGet(const QString &organization, const QString &page_size, const QString &page_token);
    void projectsProjectMembersGet(const QString &project, const QString &page_size, const QString &page_token);
    void projectsProjectMembersMemberDelete(const QString &project, const QString &member);
    void projectsProjectMembersMemberGet(const QString &project, const QString &member);
    void projectsProjectMembersMemberPatch(const QString &project, const QString &member, const QString &update_mask, const OAIMember &oai_member);
    void projectsProjectMembersMembergetInviteUrlGet(const QString &project, const QString &member);
    void projectsProjectMembersPost(const QString &project, const OAIInline_object_3 &oai_inline_object_3);
    void projectsProjectPermissionsGet(const QString &project, const QString &page_size, const QString &page_token);
    void rolesGet(const QString &page_size, const QString &page_token);
    void rolesRoleGet(const QString &role);

private:
    QString _scheme, _host;
    int _port;
    QString _basePath;
    int _timeOut;
    QString _workingDirectory;
    QMap<QString, QString> defaultHeaders;
    bool isResponseCompressionEnabled;
    bool isRequestCompressionEnabled;

    void organizationsOrganizationMembersGetCallback(OAIHttpRequestWorker *worker);
    void organizationsOrganizationMembersMemberDeleteCallback(OAIHttpRequestWorker *worker);
    void organizationsOrganizationMembersMemberGetCallback(OAIHttpRequestWorker *worker);
    void organizationsOrganizationMembersMemberPatchCallback(OAIHttpRequestWorker *worker);
    void organizationsOrganizationMembersMembergetInviteUrlGetCallback(OAIHttpRequestWorker *worker);
    void organizationsOrganizationMembersPostCallback(OAIHttpRequestWorker *worker);
    void organizationsOrganizationPermissionsGetCallback(OAIHttpRequestWorker *worker);
    void projectsProjectMembersGetCallback(OAIHttpRequestWorker *worker);
    void projectsProjectMembersMemberDeleteCallback(OAIHttpRequestWorker *worker);
    void projectsProjectMembersMemberGetCallback(OAIHttpRequestWorker *worker);
    void projectsProjectMembersMemberPatchCallback(OAIHttpRequestWorker *worker);
    void projectsProjectMembersMembergetInviteUrlGetCallback(OAIHttpRequestWorker *worker);
    void projectsProjectMembersPostCallback(OAIHttpRequestWorker *worker);
    void projectsProjectPermissionsGetCallback(OAIHttpRequestWorker *worker);
    void rolesGetCallback(OAIHttpRequestWorker *worker);
    void rolesRoleGetCallback(OAIHttpRequestWorker *worker);

signals:

    void organizationsOrganizationMembersGetSignal(OAIInline_response_200_9 summary);
    void organizationsOrganizationMembersMemberDeleteSignal();
    void organizationsOrganizationMembersMemberGetSignal(OAIMember summary);
    void organizationsOrganizationMembersMemberPatchSignal(OAIMember summary);
    void organizationsOrganizationMembersMembergetInviteUrlGetSignal(OAIInline_response_200_10 summary);
    void organizationsOrganizationMembersPostSignal(OAIMember summary);
    void organizationsOrganizationPermissionsGetSignal(OAIOrganizationPermissionList summary);
    void projectsProjectMembersGetSignal(OAIInline_response_200_9 summary);
    void projectsProjectMembersMemberDeleteSignal();
    void projectsProjectMembersMemberGetSignal(OAIMember summary);
    void projectsProjectMembersMemberPatchSignal(OAIMember summary);
    void projectsProjectMembersMembergetInviteUrlGetSignal(OAIInline_response_200_10 summary);
    void projectsProjectMembersPostSignal(OAIMember summary);
    void projectsProjectPermissionsGetSignal(OAIProjectPermissionList summary);
    void rolesGetSignal(OAIInline_response_200_6 summary);
    void rolesRoleGetSignal(OAIInline_response_200_7 summary);

    void organizationsOrganizationMembersGetSignalFull(OAIHttpRequestWorker *worker, OAIInline_response_200_9 summary);
    void organizationsOrganizationMembersMemberDeleteSignalFull(OAIHttpRequestWorker *worker);
    void organizationsOrganizationMembersMemberGetSignalFull(OAIHttpRequestWorker *worker, OAIMember summary);
    void organizationsOrganizationMembersMemberPatchSignalFull(OAIHttpRequestWorker *worker, OAIMember summary);
    void organizationsOrganizationMembersMembergetInviteUrlGetSignalFull(OAIHttpRequestWorker *worker, OAIInline_response_200_10 summary);
    void organizationsOrganizationMembersPostSignalFull(OAIHttpRequestWorker *worker, OAIMember summary);
    void organizationsOrganizationPermissionsGetSignalFull(OAIHttpRequestWorker *worker, OAIOrganizationPermissionList summary);
    void projectsProjectMembersGetSignalFull(OAIHttpRequestWorker *worker, OAIInline_response_200_9 summary);
    void projectsProjectMembersMemberDeleteSignalFull(OAIHttpRequestWorker *worker);
    void projectsProjectMembersMemberGetSignalFull(OAIHttpRequestWorker *worker, OAIMember summary);
    void projectsProjectMembersMemberPatchSignalFull(OAIHttpRequestWorker *worker, OAIMember summary);
    void projectsProjectMembersMembergetInviteUrlGetSignalFull(OAIHttpRequestWorker *worker, OAIInline_response_200_10 summary);
    void projectsProjectMembersPostSignalFull(OAIHttpRequestWorker *worker, OAIMember summary);
    void projectsProjectPermissionsGetSignalFull(OAIHttpRequestWorker *worker, OAIProjectPermissionList summary);
    void rolesGetSignalFull(OAIHttpRequestWorker *worker, OAIInline_response_200_6 summary);
    void rolesRoleGetSignalFull(OAIHttpRequestWorker *worker, OAIInline_response_200_7 summary);

    void organizationsOrganizationMembersGetSignalE(OAIInline_response_200_9 summary, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationMembersMemberDeleteSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationMembersMemberGetSignalE(OAIMember summary, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationMembersMemberPatchSignalE(OAIMember summary, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationMembersMembergetInviteUrlGetSignalE(OAIInline_response_200_10 summary, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationMembersPostSignalE(OAIMember summary, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationPermissionsGetSignalE(OAIOrganizationPermissionList summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersGetSignalE(OAIInline_response_200_9 summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersMemberDeleteSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersMemberGetSignalE(OAIMember summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersMemberPatchSignalE(OAIMember summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersMembergetInviteUrlGetSignalE(OAIInline_response_200_10 summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersPostSignalE(OAIMember summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectPermissionsGetSignalE(OAIProjectPermissionList summary, QNetworkReply::NetworkError error_type, QString error_str);
    void rolesGetSignalE(OAIInline_response_200_6 summary, QNetworkReply::NetworkError error_type, QString error_str);
    void rolesRoleGetSignalE(OAIInline_response_200_7 summary, QNetworkReply::NetworkError error_type, QString error_str);

    void organizationsOrganizationMembersGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationMembersMemberDeleteSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationMembersMemberGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationMembersMemberPatchSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationMembersMembergetInviteUrlGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationMembersPostSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void organizationsOrganizationPermissionsGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersMemberDeleteSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersMemberGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersMemberPatchSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersMembergetInviteUrlGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectMembersPostSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectPermissionsGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void rolesGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void rolesRoleGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);

    void abortRequestsSignal(); 
};

} // namespace OpenAPI
#endif
