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

/**
 * Based on http://www.creativepulse.gr/en/blog/2014/restful-api-requests-using-qt-cpp-for-linux-mac-osx-ms-windows
 * By Alex Stylianos
 *
 **/

#ifndef OAI_HTTPREQUESTWORKER_H
#define OAI_HTTPREQUESTWORKER_H

#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QString>

#include "OAIHttpFileElement.h"

namespace OpenAPI {

enum OAIHttpRequestVarLayout {
    NOT_SET,
    ADDRESS,
    URL_ENCODED,
    MULTIPART
};

class OAIHttpRequestInput {

public:
    QString url_str;
    QString http_method;
    OAIHttpRequestVarLayout var_layout;
    QMap<QString, QString> vars;
    QMap<QString, QString> headers;
    QList<OAIHttpFileElement> files;
    QByteArray request_body;

    OAIHttpRequestInput();
    OAIHttpRequestInput(QString v_url_str, QString v_http_method);
    void initialize();
    void add_var(QString key, QString value);
    void add_file(QString variable_name, QString local_filename, QString request_filename, QString mime_type);
};

class OAIHttpRequestWorker : public QObject {
    Q_OBJECT

public:
    QByteArray response;
    QNetworkReply::NetworkError error_type;
    QString error_str;
    explicit OAIHttpRequestWorker(QObject *parent = nullptr);
    virtual ~OAIHttpRequestWorker();

    QMap<QString, QString> getResponseHeaders() const;
    QString http_attribute_encode(QString attribute_name, QString input);
    void execute(OAIHttpRequestInput *input);
    static QSslConfiguration *sslDefaultConfiguration;
    void setTimeOut(int tout);
    void setWorkingDirectory(const QString &path);
    OAIHttpFileElement getHttpFileElement(const QString &fieldname = QString());
    QByteArray *getMultiPartField(const QString &fieldname = QString());
    void setResponseCompressionEnabled(bool enable);
    void setRequestCompressionEnabled(bool enable);
signals:
    void on_execution_finished(OAIHttpRequestWorker *worker);

private:
    enum OAICompressionType{
        Zlib,
        Gzip
    };
    QNetworkAccessManager *manager;
    QMap<QString, QString> headers;
    QMap<QString, OAIHttpFileElement> files;
    QMap<QString, QByteArray *> multiPartFields;
    QString workingDirectory;
    int _timeOut;
    bool isResponseCompressionEnabled;
    bool isRequestCompressionEnabled;
    void on_manager_timeout(QNetworkReply *reply);
    void process_response(QNetworkReply *reply);
    QByteArray decompress(const QByteArray& data);
    QByteArray compress(const QByteArray& input, int level, OAICompressionType compressType); 
private slots:
    void on_manager_finished(QNetworkReply *reply);
};

} // namespace OpenAPI

#endif // OAI_HTTPREQUESTWORKER_H
