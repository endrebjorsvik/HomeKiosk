#ifndef YRFORECAST_H
#define YRFORECAST_H

#include <QObject>
#include <QtCore>
#include <QGeoLocation>
#include <QXmlStreamReader>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>

class ForecastPoint : public QObject
{
public:
    ForecastPoint(QDateTime from, QDateTime to, int period);
    ForecastPoint();
    void readXml(QXmlStreamReader*);
    QString temperature() const;
    QString precipitation() const;
    QString time() const;
    QUrl symbolUrl() const;
    QString toString() const;
    void print();

private:
    QDateTime from;
    QDateTime to;
    int period;

    QString condition;
    QUrl symbol;
    double temp;
    QString tempUnit;
    double precip;
    double precipMin;
    double precipMax;
    double _windSpeed;
    double windDir;
    double _pressure;
    QString _pressureUnit;
};


class YrForecast : public QObject
{
    Q_OBJECT
public:
    explicit YrForecast(QUrl url, QNetworkAccessManager* manager, QObject *parent = nullptr);
    ~YrForecast();
    bool readXmlFile(QString);
    bool readXml(QByteArray);
    QString toString() const;
    void print();
    void startTimer();
    ForecastPoint* current();

signals:
    void forecastUpdated(QString temp, QString precip, QString time);
    void symbolUpdated(QByteArray data);

public slots:
    void fetchForecast();

private slots:
    void forecastDownloaded(QNetworkReply* reply);
    void symbolDownloaded(QNetworkReply* reply);

private:
    void fetchSymbol(QUrl url);

    QUrl xmlUrl;
    QNetworkAccessManager *networkmanager;
    QTimer *timer;

    // From XML file
    QGeoLocation location;
    QString credit;
    QUrl creditUrl;
    QList<ForecastPoint*> forecasts;
    QDateTime lastUpdate;
    QDateTime nextUpdate;
    QDateTime sunrise;
    QDateTime sunset;

    // XML parsing stuff
    QXmlStreamReader xml;
    void readWeatherData();
    void readLocation();
    void readCredits();
    void readLinks();
    void readMeta();
    void readSun();
    void readForecast();
    void readForecastTabular();
    void readForecastPoint(ForecastPoint*);
    void readObservation();

};

#endif // YRFORECAST_H
