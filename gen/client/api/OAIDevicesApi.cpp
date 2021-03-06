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

#include "OAIDevicesApi.h"
#include "OAIHelpers.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace OpenAPI {

OAIDevicesApi::OAIDevicesApi(const QString &scheme, const QString &host, int port, const QString &basePath, const int timeOut)
    : _scheme(scheme),
      _host(host),
      _port(port),
      _basePath(basePath),
      _timeOut(timeOut),
      isResponseCompressionEnabled(false),
      isRequestCompressionEnabled(false) {}

OAIDevicesApi::~OAIDevicesApi() {
}

void OAIDevicesApi::setScheme(const QString &scheme) {
    _scheme = scheme;
}

void OAIDevicesApi::setHost(const QString &host) {
    _host = host;
}

void OAIDevicesApi::setPort(int port) {
    _port = port;
}

void OAIDevicesApi::setBasePath(const QString &basePath) {
    _basePath = basePath;
}

void OAIDevicesApi::setTimeOut(const int timeOut) {
    _timeOut = timeOut;
}

void OAIDevicesApi::setWorkingDirectory(const QString &path) {
    _workingDirectory = path;
}

void OAIDevicesApi::addHeaders(const QString &key, const QString &value) {
    defaultHeaders.insert(key, value);
}

void OAIDevicesApi::enableRequestCompression() {
    isRequestCompressionEnabled = true;
}

void OAIDevicesApi::enableResponseCompression() {
    isResponseCompressionEnabled = true;
}

void OAIDevicesApi::abortRequests(){
    emit abortRequestsSignal();
}

void OAIDevicesApi::projectsProjectDevicesDeviceGet(const QString &project, const QString &device) {
    QString fullPath = QString("%1://%2%3%4%5")
                           .arg(_scheme)
                           .arg(_host)
                           .arg(_port ? ":" + QString::number(_port) : "")
                           .arg(_basePath)
                           .arg("/projects/{project}/devices/{device}");
    QString projectPathParam("{");
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));
    QString devicePathParam("{");
    devicePathParam.append("device").append("}");
    fullPath.replace(devicePathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(device)));

    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker(this);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    OAIHttpRequestInput input(fullPath, "GET");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &OAIHttpRequestWorker::on_execution_finished, this, &OAIDevicesApi::projectsProjectDevicesDeviceGetCallback);
    connect(this, &OAIDevicesApi::abortRequestsSignal, worker, &QObject::deleteLater);
    worker->execute(&input);
}

void OAIDevicesApi::projectsProjectDevicesDeviceGetCallback(OAIHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    OAIDevice output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDevicesDeviceGetSignal(output);
        emit projectsProjectDevicesDeviceGetSignalFull(worker, output);
    } else {
        emit projectsProjectDevicesDeviceGetSignalE(output, error_type, error_str);
        emit projectsProjectDevicesDeviceGetSignalEFull(worker, error_type, error_str);
    }
}

void OAIDevicesApi::projectsProjectDevicesDeviceLabelsLabelDelete(const QString &project, const QString &device, const QString &label) {
    QString fullPath = QString("%1://%2%3%4%5")
                           .arg(_scheme)
                           .arg(_host)
                           .arg(_port ? ":" + QString::number(_port) : "")
                           .arg(_basePath)
                           .arg("/projects/{project}/devices/{device}/labels/{label}");
    QString projectPathParam("{");
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));
    QString devicePathParam("{");
    devicePathParam.append("device").append("}");
    fullPath.replace(devicePathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(device)));
    QString labelPathParam("{");
    labelPathParam.append("label").append("}");
    fullPath.replace(labelPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(label)));

    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker(this);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    OAIHttpRequestInput input(fullPath, "DELETE");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &OAIHttpRequestWorker::on_execution_finished, this, &OAIDevicesApi::projectsProjectDevicesDeviceLabelsLabelDeleteCallback);
    connect(this, &OAIDevicesApi::abortRequestsSignal, worker, &QObject::deleteLater);
    worker->execute(&input);
}

void OAIDevicesApi::projectsProjectDevicesDeviceLabelsLabelDeleteCallback(OAIHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDevicesDeviceLabelsLabelDeleteSignal();
        emit projectsProjectDevicesDeviceLabelsLabelDeleteSignalFull(worker);
    } else {
        emit projectsProjectDevicesDeviceLabelsLabelDeleteSignalE(error_type, error_str);
        emit projectsProjectDevicesDeviceLabelsLabelDeleteSignalEFull(worker, error_type, error_str);
    }
}

void OAIDevicesApi::projectsProjectDevicesDeviceLabelsLabelPatchCallback(OAIHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    OAILabel output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDevicesDeviceLabelsLabelPatchSignal(output);
        emit projectsProjectDevicesDeviceLabelsLabelPatchSignalFull(worker, output);
    } else {
        emit projectsProjectDevicesDeviceLabelsLabelPatchSignalE(output, error_type, error_str);
        emit projectsProjectDevicesDeviceLabelsLabelPatchSignalEFull(worker, error_type, error_str);
    }
}

void OAIDevicesApi::projectsProjectDevicesDeviceLabelsPostCallback(OAIHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    OAILabel output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDevicesDeviceLabelsPostSignal(output);
        emit projectsProjectDevicesDeviceLabelsPostSignalFull(worker, output);
    } else {
        emit projectsProjectDevicesDeviceLabelsPostSignalE(output, error_type, error_str);
        emit projectsProjectDevicesDeviceLabelsPostSignalEFull(worker, error_type, error_str);
    }
}

void OAIDevicesApi::projectsProjectDevicesGet(const QString &project, const QString &query, const QList<QString> &device_ids, const QList<QString> &device_types, const QList<QString> &label_filters, const QString &order_by, const QString &page_size, const QString &page_token) {
    QString fullPath = QString("%1://%2%3%4%5")
                           .arg(_scheme)
                           .arg(_host)
                           .arg(_port ? ":" + QString::number(_port) : "")
                           .arg(_basePath)
                           .arg("/projects/{project}/devices");
    QString projectPathParam("{");
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));

    if (fullPath.indexOf("?") > 0)
        fullPath.append("&");
    else
        fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("query")).append("=").append(QUrl::toPercentEncoding(::OpenAPI::toStringValue(query)));

    if (device_ids.size() > 0) {
        if (QString("multi").indexOf("multi") == 0) {
            foreach (QString t, device_ids) {
                if (fullPath.indexOf("?") > 0)
                    fullPath.append("&");
                else
                    fullPath.append("?");
                fullPath.append("device_ids=").append(::OpenAPI::toStringValue(t));
            }
        } else if (QString("multi").indexOf("ssv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?");
            fullPath.append("device_ids=");
            qint32 count = 0;
            foreach (QString t, device_ids) {
                if (count > 0) {
                    fullPath.append(" ");
                }
                fullPath.append(::OpenAPI::toStringValue(t));
            }
        } else if (QString("multi").indexOf("tsv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?");
            fullPath.append("device_ids=");
            qint32 count = 0;
            foreach (QString t, device_ids) {
                if (count > 0) {
                    fullPath.append("\t");
                }
                fullPath.append(::OpenAPI::toStringValue(t));
            }
        }
    }

    if (device_types.size() > 0) {
        if (QString("multi").indexOf("multi") == 0) {
            foreach (QString t, device_types) {
                if (fullPath.indexOf("?") > 0)
                    fullPath.append("&");
                else
                    fullPath.append("?");
                fullPath.append("device_types=").append(::OpenAPI::toStringValue(t));
            }
        } else if (QString("multi").indexOf("ssv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?");
            fullPath.append("device_types=");
            qint32 count = 0;
            foreach (QString t, device_types) {
                if (count > 0) {
                    fullPath.append(" ");
                }
                fullPath.append(::OpenAPI::toStringValue(t));
            }
        } else if (QString("multi").indexOf("tsv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?");
            fullPath.append("device_types=");
            qint32 count = 0;
            foreach (QString t, device_types) {
                if (count > 0) {
                    fullPath.append("\t");
                }
                fullPath.append(::OpenAPI::toStringValue(t));
            }
        }
    }

    if (label_filters.size() > 0) {
        if (QString("multi").indexOf("multi") == 0) {
            foreach (QString t, label_filters) {
                if (fullPath.indexOf("?") > 0)
                    fullPath.append("&");
                else
                    fullPath.append("?");
                fullPath.append("label_filters=").append(::OpenAPI::toStringValue(t));
            }
        } else if (QString("multi").indexOf("ssv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?");
            fullPath.append("label_filters=");
            qint32 count = 0;
            foreach (QString t, label_filters) {
                if (count > 0) {
                    fullPath.append(" ");
                }
                fullPath.append(::OpenAPI::toStringValue(t));
            }
        } else if (QString("multi").indexOf("tsv") == 0) {
            if (fullPath.indexOf("?") > 0)
                fullPath.append("&");
            else
                fullPath.append("?");
            fullPath.append("label_filters=");
            qint32 count = 0;
            foreach (QString t, label_filters) {
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
    fullPath.append(QUrl::toPercentEncoding("order_by")).append("=").append(QUrl::toPercentEncoding(::OpenAPI::toStringValue(order_by)));

    if (fullPath.indexOf("?") > 0)
        fullPath.append("&");
    else
        fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("page_size")).append("=").append(QUrl::toPercentEncoding(::OpenAPI::toStringValue(page_size)));

    if (fullPath.indexOf("?") > 0)
        fullPath.append("&");
    else
        fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("page_token")).append("=").append(QUrl::toPercentEncoding(::OpenAPI::toStringValue(page_token)));

    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker(this);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    OAIHttpRequestInput input(fullPath, "GET");

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &OAIHttpRequestWorker::on_execution_finished, this, &OAIDevicesApi::projectsProjectDevicesGetCallback);
    connect(this, &OAIDevicesApi::abortRequestsSignal, worker, &QObject::deleteLater);
    worker->execute(&input);
}

void OAIDevicesApi::projectsProjectDevicesGetCallback(OAIHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    OAIInline_response_200 output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDevicesGetSignal(output);
        emit projectsProjectDevicesGetSignalFull(worker, output);
    } else {
        emit projectsProjectDevicesGetSignalE(output, error_type, error_str);
        emit projectsProjectDevicesGetSignalEFull(worker, error_type, error_str);
    }
}

void OAIDevicesApi::projectsProjectDevicesbatchUpdatePost(const QString &project, const OAIInline_object &oai_inline_object) {
    QString fullPath = QString("%1://%2%3%4%5")
                           .arg(_scheme)
                           .arg(_host)
                           .arg(_port ? ":" + QString::number(_port) : "")
                           .arg(_basePath)
                           .arg("/projects/{project}/devices:batchUpdate");
    QString projectPathParam("{");
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));

    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker(this);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    OAIHttpRequestInput input(fullPath, "POST");

    QString output = oai_inline_object.asJson();
    input.request_body.append(output);

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &OAIHttpRequestWorker::on_execution_finished, this, &OAIDevicesApi::projectsProjectDevicesbatchUpdatePostCallback);
    connect(this, &OAIDevicesApi::abortRequestsSignal, worker, &QObject::deleteLater);
    worker->execute(&input);
}

void OAIDevicesApi::projectsProjectDevicesbatchUpdatePostCallback(OAIHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    OAIInline_response_200_1 output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDevicesbatchUpdatePostSignal(output);
        emit projectsProjectDevicesbatchUpdatePostSignalFull(worker, output);
    } else {
        emit projectsProjectDevicesbatchUpdatePostSignalE(output, error_type, error_str);
        emit projectsProjectDevicesbatchUpdatePostSignalEFull(worker, error_type, error_str);
    }
}

void OAIDevicesApi::projectsProjectDevicestransferPost(const QString &project, const OAIInline_object_1 &oai_inline_object_1) {
    QString fullPath = QString("%1://%2%3%4%5")
                           .arg(_scheme)
                           .arg(_host)
                           .arg(_port ? ":" + QString::number(_port) : "")
                           .arg(_basePath)
                           .arg("/projects/{project}/devices:transfer");
    QString projectPathParam("{");
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));

    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker(this);
    worker->setTimeOut(_timeOut);
    worker->setWorkingDirectory(_workingDirectory);
    OAIHttpRequestInput input(fullPath, "POST");

    QString output = oai_inline_object_1.asJson();
    input.request_body.append(output);

    foreach (QString key, this->defaultHeaders.keys()) { input.headers.insert(key, this->defaultHeaders.value(key)); }

    connect(worker, &OAIHttpRequestWorker::on_execution_finished, this, &OAIDevicesApi::projectsProjectDevicestransferPostCallback);
    connect(this, &OAIDevicesApi::abortRequestsSignal, worker, &QObject::deleteLater);
    worker->execute(&input);
}

void OAIDevicesApi::projectsProjectDevicestransferPostCallback(OAIHttpRequestWorker *worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    } else {
        msg = "Error: " + worker->error_str;
        error_str = QString("%1, %2").arg(worker->error_str).arg(QString(worker->response));
    }
    OAIInline_response_200_3 output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDevicestransferPostSignal(output);
        emit projectsProjectDevicestransferPostSignalFull(worker, output);
    } else {
        emit projectsProjectDevicestransferPostSignalE(output, error_type, error_str);
        emit projectsProjectDevicestransferPostSignalEFull(worker, error_type, error_str);
    }
}

} // namespace OpenAPI
