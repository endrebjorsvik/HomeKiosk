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

#include "OAIDataConnectorsApi.h"
#include "OAIHelpers.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace OpenAPI {

OAIDataConnectorsApi::OAIDataConnectorsApi() : basePath("/v2"),
    host("api.disruptive-technologies.com"),
    timeout(0){

}

OAIDataConnectorsApi::~OAIDataConnectorsApi() {

}

OAIDataConnectorsApi::OAIDataConnectorsApi(const QString& host, const QString& basePath, const int tout) {
    this->host = host;
    this->basePath = basePath;
    this->timeout = tout;
}

void OAIDataConnectorsApi::setBasePath(const QString& basePath){
    this->basePath = basePath;
}

void OAIDataConnectorsApi::setHost(const QString& host){
    this->host = host;
}

void OAIDataConnectorsApi::setApiTimeOutMs(const int tout){
    timeout = tout;
}

void OAIDataConnectorsApi::addHeaders(const QString& key, const QString& value){
    defaultHeaders.insert(key, value);
}


void
OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectorDelete(const QString& project, const QString& dataconnector) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/projects/{project}/dataconnectors/{dataconnector}");
    QString projectPathParam("{"); 
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));
    QString dataconnectorPathParam("{"); 
    dataconnectorPathParam.append("dataconnector").append("}");
    fullPath.replace(dataconnectorPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(dataconnector)));
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    worker->setTimeOut(timeout);    
    OAIHttpRequestInput input(fullPath, "DELETE");


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectorDeleteCallback);

    worker->execute(&input);
}

void
OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectorDeleteCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDataconnectorsDataconnectorDeleteSignal();
        emit projectsProjectDataconnectorsDataconnectorDeleteSignalFull(worker);
    } else {
        emit projectsProjectDataconnectorsDataconnectorDeleteSignalE(error_type, error_str);
        emit projectsProjectDataconnectorsDataconnectorDeleteSignalEFull(worker, error_type, error_str);
    }
}

void
OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectorGet(const QString& project, const QString& dataconnector) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/projects/{project}/dataconnectors/{dataconnector}");
    QString projectPathParam("{"); 
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));
    QString dataconnectorPathParam("{"); 
    dataconnectorPathParam.append("dataconnector").append("}");
    fullPath.replace(dataconnectorPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(dataconnector)));
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    worker->setTimeOut(timeout);    
    OAIHttpRequestInput input(fullPath, "GET");


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectorGetCallback);

    worker->execute(&input);
}

void
OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectorGetCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    OAIDataConnector output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDataconnectorsDataconnectorGetSignal(output);
        emit projectsProjectDataconnectorsDataconnectorGetSignalFull(worker, output);
    } else {
        emit projectsProjectDataconnectorsDataconnectorGetSignalE(output, error_type, error_str);
        emit projectsProjectDataconnectorsDataconnectorGetSignalEFull(worker, error_type, error_str);
    }
}

void
OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectorPatch(const QString& project, const QString& dataconnector, const QString& update_mask, const OAIDataConnector& oai_data_connector) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/projects/{project}/dataconnectors/{dataconnector}");
    QString projectPathParam("{"); 
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));
    QString dataconnectorPathParam("{"); 
    dataconnectorPathParam.append("dataconnector").append("}");
    fullPath.replace(dataconnectorPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(dataconnector)));
    
    if (fullPath.indexOf("?") > 0)
      fullPath.append("&");
    else
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("update_mask"))
        .append("=")
        .append(QUrl::toPercentEncoding(::OpenAPI::toStringValue(update_mask)));
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    worker->setTimeOut(timeout);    
    OAIHttpRequestInput input(fullPath, "PATCH");

    
    QString output = oai_data_connector.asJson();
    input.request_body.append(output);
    

    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectorPatchCallback);

    worker->execute(&input);
}

void
OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectorPatchCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    OAIDataConnector output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDataconnectorsDataconnectorPatchSignal(output);
        emit projectsProjectDataconnectorsDataconnectorPatchSignalFull(worker, output);
    } else {
        emit projectsProjectDataconnectorsDataconnectorPatchSignalE(output, error_type, error_str);
        emit projectsProjectDataconnectorsDataconnectorPatchSignalEFull(worker, error_type, error_str);
    }
}

void
OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectormetricsGet(const QString& project, const QString& dataconnector) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/projects/{project}/dataconnectors/{dataconnector}:metrics");
    QString projectPathParam("{"); 
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));
    QString dataconnectorPathParam("{"); 
    dataconnectorPathParam.append("dataconnector").append("}");
    fullPath.replace(dataconnectorPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(dataconnector)));
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    worker->setTimeOut(timeout);    
    OAIHttpRequestInput input(fullPath, "GET");


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectormetricsGetCallback);

    worker->execute(&input);
}

void
OAIDataConnectorsApi::projectsProjectDataconnectorsDataconnectormetricsGetCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    OAIInline_response_200_5 output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDataconnectorsDataconnectormetricsGetSignal(output);
        emit projectsProjectDataconnectorsDataconnectormetricsGetSignalFull(worker, output);
    } else {
        emit projectsProjectDataconnectorsDataconnectormetricsGetSignalE(output, error_type, error_str);
        emit projectsProjectDataconnectorsDataconnectormetricsGetSignalEFull(worker, error_type, error_str);
    }
}

void
OAIDataConnectorsApi::projectsProjectDataconnectorsGet(const QString& project, const QString& page_size, const QString& page_token) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/projects/{project}/dataconnectors");
    QString projectPathParam("{"); 
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));
    
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
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    worker->setTimeOut(timeout);    
    OAIHttpRequestInput input(fullPath, "GET");


    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIDataConnectorsApi::projectsProjectDataconnectorsGetCallback);

    worker->execute(&input);
}

void
OAIDataConnectorsApi::projectsProjectDataconnectorsGetCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    OAIInline_response_200_4 output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDataconnectorsGetSignal(output);
        emit projectsProjectDataconnectorsGetSignalFull(worker, output);
    } else {
        emit projectsProjectDataconnectorsGetSignalE(output, error_type, error_str);
        emit projectsProjectDataconnectorsGetSignalEFull(worker, error_type, error_str);
    }
}

void
OAIDataConnectorsApi::projectsProjectDataconnectorsPost(const QString& project, const OAIDataConnector& oai_data_connector) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/projects/{project}/dataconnectors");
    QString projectPathParam("{"); 
    projectPathParam.append("project").append("}");
    fullPath.replace(projectPathParam, QUrl::toPercentEncoding(::OpenAPI::toStringValue(project)));
    
    OAIHttpRequestWorker *worker = new OAIHttpRequestWorker();
    worker->setTimeOut(timeout);    
    OAIHttpRequestInput input(fullPath, "POST");

    
    QString output = oai_data_connector.asJson();
    input.request_body.append(output);
    

    foreach(QString key, this->defaultHeaders.keys()) {
        input.headers.insert(key, this->defaultHeaders.value(key));
    }

    connect(worker,
            &OAIHttpRequestWorker::on_execution_finished,
            this,
            &OAIDataConnectorsApi::projectsProjectDataconnectorsPostCallback);

    worker->execute(&input);
}

void
OAIDataConnectorsApi::projectsProjectDataconnectorsPostCallback(OAIHttpRequestWorker * worker) {
    QString msg;
    QString error_str = worker->error_str;
    QNetworkReply::NetworkError error_type = worker->error_type;

    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }
    OAIDataConnector output(QString(worker->response));
    worker->deleteLater();

    if (worker->error_type == QNetworkReply::NoError) {
        emit projectsProjectDataconnectorsPostSignal(output);
        emit projectsProjectDataconnectorsPostSignalFull(worker, output);
    } else {
        emit projectsProjectDataconnectorsPostSignalE(output, error_type, error_str);
        emit projectsProjectDataconnectorsPostSignalEFull(worker, error_type, error_str);
    }
}


}
