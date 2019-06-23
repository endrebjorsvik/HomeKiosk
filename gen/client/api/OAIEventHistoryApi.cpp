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

#include "OAIEventHistoryApi.h"
#include "OAIHelpers.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace OpenAPI {

OAIEventHistoryApi::OAIEventHistoryApi() : basePath("/v2"),
    host("api.disruptive-technologies.com"),
    timeout(0){

}

OAIEventHistoryApi::~OAIEventHistoryApi() {

}

OAIEventHistoryApi::OAIEventHistoryApi(const QString& host, const QString& basePath, const int tout) {
    this->host = host;
    this->basePath = basePath;
    this->timeout = tout;
}

void OAIEventHistoryApi::setBasePath(const QString& basePath){
    this->basePath = basePath;
}

void OAIEventHistoryApi::setHost(const QString& host){
    this->host = host;
}

void OAIEventHistoryApi::setApiTimeOutMs(const int tout){
    timeout = tout;
}

void OAIEventHistoryApi::addHeaders(const QString& key, const QString& value){
    defaultHeaders.insert(key, value);
}


void
OAIEventHistoryApi::projectsProjectDevicesDeviceEventsGet(const QString& project, const QString& device, const QList<OAIEventType>& event_types, const QString& page_size, const QString& page_token, const QDateTime& start_time, const QDateTime& end_time) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/projects/{project}/devices/{device}/events");
    QString projectPathParam("{"); 
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));
    QString devicePathParam("{"); 
    devicePathParam.append("device").append("}");
    fullPath.replace(devicePathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(device)));
    
    if (event_types.size() > 0) {
      if (QString("multi").indexOf("multi") == 0) {
        foreach(OAIEventType t, event_types) {
          if (fullPath.indexOf("?") > 0)
            fullPath.append("&");
          else
            fullPath.append("?");
          fullPath.append("event_types=").append(::OpenAPI::toStringValue(t));
        }
      }
      else if (QString("multi").indexOf("ssv") == 0) {
        if (fullPath.indexOf("?") > 0)
          fullPath.append("&");
        else
          fullPath.append("?");
        fullPath.append("event_types=");
        qint32 count = 0;
        foreach(OAIEventType t, event_types) {
          if (count > 0) {
            fullPath.append(" ");
          }
          fullPath.append(::OpenAPI::toStringValue(t));
        }
      }
      else if (QString("multi").indexOf("tsv") == 0) {
        if (fullPath.indexOf("?") > 0)
          fullPath.append("&");
        else
          fullPath.append("?");
        fullPath.append("event_types=");
        qint32 count = 0;
        foreach(OAIEventType t, event_types) {
          if (count > 0) {
            fullPath.append("\t");
          }
          fullPath.append(::OpenAPI::toStringValue(t));
        }
      }
    }
    
    if (fullPath.indexOf("?") > 0)
      fullPath.append("&");
    else
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("page_size"))
        .append("=")
        .append(QUrl::toPercentEncoding(::OpenAPI::toStringValue(page_size)));
    
    if (fullPath.indexOf("?") > 0)
      fullPath.append("&");
    else
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("page_token"))
        .append("=")
        .append(QUrl::toPercentEncoding(::OpenAPI::toStringValue(page_token)));
    
    if (fullPath.indexOf("?") > 0)
      fullPath.append("&");
    else
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("start_time"))
        .append("=")
        .append(QUrl::toPercentEncoding(::OpenAPI::toStringValue(start_time)));
    
    if (fullPath.indexOf("?") > 0)
      fullPath.append("&");
    else
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("end_time"))
        .append("=")
        .append(QUrl::toPercentEncoding(::OpenAPI::toStringValue(end_time)));
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    worker->setTimeOut(timeout);    
    OAIHttpRequestInput input(fullPath, "GET");


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIEventHistoryApi::projectsProjectDevicesDeviceEventsGetCallback);

    worker->execute(&input);
}

void
OAIEventHistoryApi::projectsProjectDevicesDeviceEventsGetCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    OAIInline_response_200_2 output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDevicesDeviceEventsGetSignal(output);
        emit projectsProjectDevicesDeviceEventsGetSignalFull(worker, output);
    } else {
        emit projectsProjectDevicesDeviceEventsGetSignalE(output, error_type, error_str);
        emit projectsProjectDevicesDeviceEventsGetSignalEFull(worker, error_type, error_str);
    }
}


}
