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

#ifndef OAI_OAIDevicesApi_H
#define OAI_OAIDevicesApi_H

#include "OAIHttpRequest.h"

#include "models/OAIDevice.h"
#include "models/OAIInline_object.h"
#include "models/OAIInline_object_1.h"
#include "models/OAIInline_response_200.h"
#include "models/OAIInline_response_200_1.h"
#include "models/OAIInline_response_200_3.h"
#include "models/OAILabel.h"
#include "OAIObject.h"
#include <QString>
#include "models/UNKNOWN_BASE_TYPE.h"

#include <QObject>

namespace OpenAPI {

class OAIDevicesApi: public QObject {
    Q_OBJECT

public:
    OAIDevicesApi();
    OAIDevicesApi(const QString& host, const QString& basePath, const int toutMs = 0);
    ~OAIDevicesApi();

    void setBasePath(const QString& basePath);
    void setHost(const QString& host);
    void setApiTimeOutMs(const int tout);
    void addHeaders(const QString& key, const QString& value);
    
    void projectsProjectDevicesDeviceGet(const QString& project, const QString& device);
    void projectsProjectDevicesDeviceLabelsLabelDelete(const QString& project, const QString& device, const QString& label);
    void projectsProjectDevicesDeviceLabelsLabelPatch(const QString& project, const QString& device, const QString& label, const UNKNOWN_BASE_TYPE& unknown_base_type);
    void projectsProjectDevicesDeviceLabelsPost(const QString& project, const QString& device, const UNKNOWN_BASE_TYPE& unknown_base_type);
    void projectsProjectDevicesGet(const QString& project, const QString& query, const QList<QString>& device_ids, const QList<QString>& device_types, const QList<QString>& label_filters, const QString& order_by, const QString& page_size, const QString& page_token);
    void projectsProjectDevicesbatchUpdatePost(const QString& project, const OAIInline_object& oai_inline_object);
    void projectsProjectDevicestransferPost(const QString& project, const OAIInline_object_1& oai_inline_object_1);
    
private:
    QString basePath;
    QString host;
    int timeout;
    QMap<QString, QString> defaultHeaders;
    void projectsProjectDevicesDeviceGetCallback (OAIHttpRequestWorker * worker);
    void projectsProjectDevicesDeviceLabelsLabelDeleteCallback (OAIHttpRequestWorker * worker);
    void projectsProjectDevicesDeviceLabelsLabelPatchCallback (OAIHttpRequestWorker * worker);
    void projectsProjectDevicesDeviceLabelsPostCallback (OAIHttpRequestWorker * worker);
    void projectsProjectDevicesGetCallback (OAIHttpRequestWorker * worker);
    void projectsProjectDevicesbatchUpdatePostCallback (OAIHttpRequestWorker * worker);
    void projectsProjectDevicestransferPostCallback (OAIHttpRequestWorker * worker);
    
signals:
    void projectsProjectDevicesDeviceGetSignal(OAIDevice summary);
    void projectsProjectDevicesDeviceLabelsLabelDeleteSignal();
    void projectsProjectDevicesDeviceLabelsLabelPatchSignal(OAILabel summary);
    void projectsProjectDevicesDeviceLabelsPostSignal(OAILabel summary);
    void projectsProjectDevicesGetSignal(OAIInline_response_200 summary);
    void projectsProjectDevicesbatchUpdatePostSignal(OAIInline_response_200_1 summary);
    void projectsProjectDevicestransferPostSignal(OAIInline_response_200_3 summary);
    
    void projectsProjectDevicesDeviceGetSignalFull(OAIHttpRequestWorker* worker, OAIDevice summary);
    void projectsProjectDevicesDeviceLabelsLabelDeleteSignalFull(OAIHttpRequestWorker* worker);
    void projectsProjectDevicesDeviceLabelsLabelPatchSignalFull(OAIHttpRequestWorker* worker, OAILabel summary);
    void projectsProjectDevicesDeviceLabelsPostSignalFull(OAIHttpRequestWorker* worker, OAILabel summary);
    void projectsProjectDevicesGetSignalFull(OAIHttpRequestWorker* worker, OAIInline_response_200 summary);
    void projectsProjectDevicesbatchUpdatePostSignalFull(OAIHttpRequestWorker* worker, OAIInline_response_200_1 summary);
    void projectsProjectDevicestransferPostSignalFull(OAIHttpRequestWorker* worker, OAIInline_response_200_3 summary);
    
    void projectsProjectDevicesDeviceGetSignalE(OAIDevice summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicesDeviceLabelsLabelDeleteSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicesDeviceLabelsLabelPatchSignalE(OAILabel summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicesDeviceLabelsPostSignalE(OAILabel summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicesGetSignalE(OAIInline_response_200 summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicesbatchUpdatePostSignalE(OAIInline_response_200_1 summary, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicestransferPostSignalE(OAIInline_response_200_3 summary, QNetworkReply::NetworkError error_type, QString error_str);
    
    void projectsProjectDevicesDeviceGetSignalEFull(OAIHttpRequestWorker* worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicesDeviceLabelsLabelDeleteSignalEFull(OAIHttpRequestWorker* worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicesDeviceLabelsLabelPatchSignalEFull(OAIHttpRequestWorker* worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicesDeviceLabelsPostSignalEFull(OAIHttpRequestWorker* worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicesGetSignalEFull(OAIHttpRequestWorker* worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicesbatchUpdatePostSignalEFull(OAIHttpRequestWorker* worker, QNetworkReply::NetworkError error_type, QString error_str);
    void projectsProjectDevicestransferPostSignalEFull(OAIHttpRequestWorker* worker, QNetworkReply::NetworkError error_type, QString error_str);
    
};

}
#endif
