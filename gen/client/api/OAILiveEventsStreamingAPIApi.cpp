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

#include "OAILiveEventsStreamingAPIApi.h"
#include "OAIHelpers.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace OpenAPI {

OAILiveEventsStreamingAPIApi::OAILiveEventsStreamingAPIApi() : basePath("/v2"),
    host("api.disruptive-technologies.com"),
    timeout(0){

}

OAILiveEventsStreamingAPIApi::~OAILiveEventsStreamingAPIApi() {

}

OAILiveEventsStreamingAPIApi::OAILiveEventsStreamingAPIApi(const QString& host, const QString& basePath, const int tout) {
    this->host = host;
    this->basePath = basePath;
    this->timeout = tout;
}

void OAILiveEventsStreamingAPIApi::setBasePath(const QString& basePath){
    this->basePath = basePath;
}

void OAILiveEventsStreamingAPIApi::setHost(const QString& host){
    this->host = host;
}

void OAILiveEventsStreamingAPIApi::setApiTimeOutMs(const int tout){
    timeout = tout;
}

void OAILiveEventsStreamingAPIApi::addHeaders(const QString& key, const QString& value){
    defaultHeaders.insert(key, value);
}


void
OAILiveEventsStreamingAPIApi::projectsProjectDevicesDevicestreamGet(const QString& project, const QString& device, const QString& token, const QList<OAIEventType>& event_types) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/projects/{project}/devices/{device}:stream");
    QString projectPathParam("{"); 
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));
    QString devicePathParam("{"); 
    devicePathParam.append("device").append("}");
    fullPath.replace(devicePathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(device)));
    
    if (fullPath.indexOf("?") > 0)
      fullPath.append("&");
    else
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("token"))
        .append("=")
        .append(QUrl::toPercentEncoding(::OpenAPI::toStringValue(token)));
    
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
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    worker->setTimeOut(timeout);    
    OAIHttpRequestInput input(fullPath, "GET");


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAILiveEventsStreamingAPIApi::projectsProjectDevicesDevicestreamGetCallback);

    worker->execute(&input);
}

void
OAILiveEventsStreamingAPIApi::projectsProjectDevicesDevicestreamGetCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    OAIEvent output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDevicesDevicestreamGetSignal(output);
        emit projectsProjectDevicesDevicestreamGetSignalFull(worker, output);
    } else {
        emit projectsProjectDevicesDevicestreamGetSignalE(output, error_type, error_str);
        emit projectsProjectDevicesDevicestreamGetSignalEFull(worker, error_type, error_str);
    }
}

void
OAILiveEventsStreamingAPIApi::projectsProjectDevicesstreamGet(const QString& project, const QString& token, const QList<QString>& device_ids, const QList<QString>& label_filters, const QList<QString>& device_types, const QList<OAIEventType>& event_types) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/projects/{project}/devices:stream");
    QString projectPathParam("{"); 
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));
    
    if (fullPath.indexOf("?") > 0)
      fullPath.append("&");
    else
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("token"))
        .append("=")
        .append(QUrl::toPercentEncoding(::OpenAPI::toStringValue(token)));
    
    if (device_ids.size() > 0) {
      if (QString("multi").indexOf("multi") == 0) {
        foreach(QString t, device_ids) {
          if (fullPath.indexOf("?") > 0)
            fullPath.append("&");
          else
            fullPath.append("?");
          fullPath.append("device_ids=").append(::OpenAPI::toStringValue(t));
        }
      }
      else if (QString("multi").indexOf("ssv") == 0) {
        if (fullPath.indexOf("?") > 0)
          fullPath.append("&");
        else
          fullPath.append("?");
        fullPath.append("device_ids=");
        qint32 count = 0;
        foreach(QString t, device_ids) {
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
        fullPath.append("device_ids=");
        qint32 count = 0;
        foreach(QString t, device_ids) {
          if (count > 0) {
            fullPath.append("\t");
          }
          fullPath.append(::OpenAPI::toStringValue(t));
        }
      }
    }
    
    if (label_filters.size() > 0) {
      if (QString("multi").indexOf("multi") == 0) {
        foreach(QString t, label_filters) {
          if (fullPath.indexOf("?") > 0)
            fullPath.append("&");
          else
            fullPath.append("?");
          fullPath.append("label_filters=").append(::OpenAPI::toStringValue(t));
        }
      }
      else if (QString("multi").indexOf("ssv") == 0) {
        if (fullPath.indexOf("?") > 0)
          fullPath.append("&");
        else
          fullPath.append("?");
        fullPath.append("label_filters=");
        qint32 count = 0;
        foreach(QString t, label_filters) {
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
        fullPath.append("label_filters=");
        qint32 count = 0;
        foreach(QString t, label_filters) {
          if (count > 0) {
            fullPath.append("\t");
          }
          fullPath.append(::OpenAPI::toStringValue(t));
        }
      }
    }
    
    if (device_types.size() > 0) {
      if (QString("multi").indexOf("multi") == 0) {
        foreach(QString t, device_types) {
          if (fullPath.indexOf("?") > 0)
            fullPath.append("&");
          else
            fullPath.append("?");
          fullPath.append("device_types=").append(::OpenAPI::toStringValue(t));
        }
      }
      else if (QString("multi").indexOf("ssv") == 0) {
        if (fullPath.indexOf("?") > 0)
          fullPath.append("&");
        else
          fullPath.append("?");
        fullPath.append("device_types=");
        qint32 count = 0;
        foreach(QString t, device_types) {
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
        fullPath.append("device_types=");
        qint32 count = 0;
        foreach(QString t, device_types) {
          if (count > 0) {
            fullPath.append("\t");
          }
          fullPath.append(::OpenAPI::toStringValue(t));
        }
      }
    }
    
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
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    worker->setTimeOut(timeout);    
    OAIHttpRequestInput input(fullPath, "GET");


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAILiveEventsStreamingAPIApi::projectsProjectDevicesstreamGetCallback);

    worker->execute(&input);
}

void
OAILiveEventsStreamingAPIApi::projectsProjectDevicesstreamGetCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    OAIEvent output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDevicesstreamGetSignal(output);
        emit projectsProjectDevicesstreamGetSignalFull(worker, output);
    } else {
        emit projectsProjectDevicesstreamGetSignalE(output, error_type, error_str);
        emit projectsProjectDevicesstreamGetSignalEFull(worker, error_type, error_str);
    }
}


}