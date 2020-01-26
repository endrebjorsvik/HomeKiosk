#ifndef YRFORECAST_H
#define YRFORECAST_H

#include <QObject>
#include <QtCore>
#include <QGeoLocation>
#include <QXmlStreamReader>

class ForecastPoint : public QObject
{
public:
    ForecastPoint(QDateTime from, QDateTime to, int period);
    void readXml(QXmlStreamReader*);
    QString shortSummary();

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
    explicit YrForecast(QObject *parent = nullptr);
    bool readXmlFile(QFile&);
    bool readXml(QByteArray);
    void print();
    ForecastPoint* current();

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
