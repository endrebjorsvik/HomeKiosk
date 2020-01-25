#ifndef YRFORECAST_H
#define YRFORECAST_H

#include <QObject>
#include <QtCore>
#include <QGeoLocation>
#include <QXmlStreamReader>

class ForecastPoint : public QObject
{
public:
    QDateTime from;
    QDateTime to;
    int period;

    QString condition;
    QUrl symbol;
    double temperature;
    QString temperatureUnit;
    double precipitation;
    double precipitationMin;
    double precipitationMax;
    double windDirection;
    double windSpeed;
    double pressure;
    QString pressureUnit;
};


class YrForecast : public QObject
{
    Q_OBJECT
public:
    explicit YrForecast(QObject *parent = nullptr);
    bool readXml(QString);
    void print();

signals:

public slots:

private:
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
