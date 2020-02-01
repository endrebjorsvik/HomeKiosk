#include "yrforecast.h"
#include <iostream>
#include <QGeoAddress>
#include <QGeoCoordinate>
#include <QFile>
#include <QNetworkRequest>
#include <QDebug>
#include <QTextStream>

YrForecast::YrForecast(QUrl url, QNetworkAccessManager* manager, QObject *parent) : QObject(parent)
{
    // Ensure minimum one forecast in the list
    this->forecasts.append(new ForecastPoint());

    // Setup download stuff
    this->xmlUrl = url;
    this->networkmanager = manager;
    connect(this->networkmanager, &QNetworkAccessManager::finished,
            this, &YrForecast::forecastDownloaded);
    connect(this->networkmanager, &QNetworkAccessManager::finished,
            this, &YrForecast::symbolDownloaded);

    this->timer = new QTimer(this);
    connect(this->timer, &QTimer::timeout,
            this, &YrForecast::fetchForecast);
    this->timer->setInterval(std::chrono::minutes(15));
}

YrForecast::~YrForecast()
{
    qDeleteAll(this->forecasts);
    this->forecasts.clear();
}

void YrForecast::startTimer()
{
    this->fetchForecast();
    this->timer->start();
}

void YrForecast::fetchForecast()
{
    auto req = QNetworkRequest(this->xmlUrl);
    this->networkmanager->get(req);
}

void YrForecast::forecastDownloaded(QNetworkReply* reply)
{
    if (reply->url() == this->xmlUrl) {
        auto err = reply->error();
        if (err != QNetworkReply::NoError) {
            qCritical() << "Failed downloading symbol:" << err;
        }
        this->readXml(reply->readAll());
        reply->deleteLater();
    }
}

bool YrForecast::readXmlFile(QString filename)
{
    QFile f(filename);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        qCritical() << "Cannot read file: " << f.errorString();
        exit(1);
    }
    return this->readXml(f.readAll());
}

bool YrForecast::readXml(QByteArray stream)
{
    qDeleteAll(this->forecasts);
    this->forecasts.clear();

    this->xml.addData(stream);
    if (this->xml.readNextStartElement()) {
        if (this->xml.name() != "weatherdata") {
            this->xml.raiseError("Unexpected file format. Expected <weatherdata> start tag");
        }
        else {
            this->readWeatherData();
        }
    }
    if (this->xml.hasError()) {
        qCritical() << "XML parse error: " << this->xml.errorString();
        return false;
    }
    this->xml.clear();
    auto current = this->current();
    emit this->forecastUpdated(current->temperature(),
                               current->precipitation(),
                               current->time());
    this->fetchSymbol(current->symbolUrl());
    return true;
}

void YrForecast::readWeatherData()
{
    while (this->xml.readNextStartElement()) {
        auto name = this->xml.name().toString();
        if (name == "location") {
            this->readLocation();
        } else if (name == "credit") {
            this->readCredits();
        } else if (name == "links") {
            this->readLinks();
        } else if (name == "meta") {
            this->readMeta();
        } else if (name == "sun") {
            this->readSun();
        } else if (name == "forecast") {
            this->readForecast();
        } else if (name == "weatherstation") {
            this->readObservation();
        }
    }
}

void YrForecast::readLocation()
{
    QGeoAddress address;
    QGeoCoordinate coord;
    while (this->xml.readNextStartElement()) {
        auto name = this->xml.name().toString();
        if (name == "name") {
            address.setCity(this->xml.readElementText());
        } else if (name == "type") {
            this->xml.skipCurrentElement();  // Skipping
        } else if (name == "country") {
            address.setCountry(this->xml.readElementText());
        } else if (name == "timezone") {
            this->xml.skipCurrentElement();  // Skipping
        } else if (name == "location") {
            auto attrs = this->xml.attributes();
            coord.setAltitude(attrs.value("altitude").toString().toDouble());
            coord.setLatitude(attrs.value("latitude").toString().toDouble());
            coord.setLongitude(attrs.value("longitude").toString().toDouble());
            this->xml.skipCurrentElement();
        } else {
            // Unknown tags. Should not really appear. Perhaps a warning?
            this->xml.skipCurrentElement();
        }
    }
    this->location.setAddress(address);
    this->location.setCoordinate(coord);
}

void YrForecast::readCredits()
{
    while (this->xml.readNextStartElement()) {
        auto name = this->xml.name().toString();
        if (name == "link") {
            auto attrs = this->xml.attributes();
            this->credit = attrs.value("text").toString();
            this->creditUrl.setUrl(attrs.value("url").toString());
            this->xml.skipCurrentElement();
        } else {
            // Unknown tags. Should not really appear. Perhaps a warning?
            this->xml.skipCurrentElement();
        }
    }
}

void YrForecast::readLinks()
{
    qInfo() << "Skipping link data";
    this->xml.skipCurrentElement();
}

void YrForecast::readMeta()
{
    while (this->xml.readNextStartElement()) {
        auto name = this->xml.name().toString();
        if (name == "lastupdate") {
            this->lastUpdate = QDateTime::fromString(xml.readElementText(), Qt::ISODate);
        } else if (name == "nextupdate") {
            this->nextUpdate= QDateTime::fromString(xml.readElementText(), Qt::ISODate);
        } else {
            // Unknown tags. Should not really appear. Perhaps a warning?
            this->xml.skipCurrentElement();
        }
    }
}

void YrForecast::readSun()
{
    auto attrs = this->xml.attributes();
    this->sunrise = QDateTime::fromString(attrs.value("rise").toString(), Qt::ISODate);
    this->sunset = QDateTime::fromString(attrs.value("set").toString(), Qt::ISODate);
    this->xml.skipCurrentElement();
}

void YrForecast::readForecast()
{
    while (this->xml.readNextStartElement()) {
        auto name = this->xml.name().toString();
        if (name == "text") {
            this->xml.skipCurrentElement();
        } else if (name == "tabular") {
            this->readForecastTabular();
        } else {
            // Unknown tags. Should not really appear. Perhaps a warning?
            qInfo() << "Skipping: " << name;
            this->xml.skipCurrentElement();
        }
    }
}

void YrForecast::readObservation()
{
    qInfo() << "Skipping weatherstation data";
    this->xml.skipCurrentElement();
}

void YrForecast::readForecastTabular()
{
    while (this->xml.readNextStartElement()) {
        auto name = this->xml.name().toString();
        if (name == "time") {
            auto attrs = this->xml.attributes();
            auto from = QDateTime::fromString(attrs.value("from").toString(), Qt::ISODate);
            auto to = QDateTime::fromString(attrs.value("to").toString(), Qt::ISODate);
            auto period = attrs.value("from").toInt();
            ForecastPoint* point = new ForecastPoint(from, to, period);
            point->readXml(&this->xml);
            forecasts.append(point);
        } else {
            // Unknown tags. Should not really appear. Perhaps a warning?
            this->xml.skipCurrentElement();
        }
    }
}

ForecastPoint::ForecastPoint(QDateTime from, QDateTime to, int period): from(from), to(to), period(period) {}

ForecastPoint::ForecastPoint() {}

void ForecastPoint::readXml(QXmlStreamReader* xml)
{
    while (xml->readNextStartElement()) {
        auto name = xml->name().toString();
        auto attrs = xml->attributes();
        if (name == "symbol") {
            // The SVG format used by Yr is not supported by Qt, which
            // only supports SVG Tiny (1.2).
            // // https://symbol.yr.no/grafikk/sym/svg/{var}.svg
            // // Eg. https://symbol.yr.no/grafikk/sym/svg/34.svg (for var = '34')
            // Using PNG instead
            // https://www.yr.no/grafikk/sym/v2017/png/200/{var}.png
            // (Deprecated? https://symbol.yr.no/grafikk/sym/b200/{var}.png)
            this->condition = attrs.value("name").toString();
            auto symId = attrs.value("var").toString();
            this->symbol = QUrl(QString("https://www.yr.no/grafikk/sym/v2017/png/200/%1.png").arg(symId));
            xml->skipCurrentElement();
        } else if (name == "precipitation") {
            this->precip= attrs.value("value").toDouble();
            this->precipMin = attrs.value("minvalue").toDouble();
            this->precipMax = attrs.value("maxvalue").toDouble();
            xml->skipCurrentElement();
        } else if (name == "windDirection") {
            this->windDir= attrs.value("deg").toDouble();
            xml->skipCurrentElement();
        } else if (name == "windSpeed") {
            this->_windSpeed = attrs.value("mps").toDouble();
            xml->skipCurrentElement();
        } else if (name == "temperature") {
            this->temp= attrs.value("value").toDouble();
            this->tempUnit = attrs.value("unit").toString();
            xml->skipCurrentElement();
        } else if (name == "pressure") {
            this->_pressure = attrs.value("value").toDouble();
            this->_pressureUnit = attrs.value("unit").toString();
            xml->skipCurrentElement();
        } else {
            // Unknown tags. Should not really appear. Perhaps a warning?
            xml->skipCurrentElement();
        }
    }
}

QString YrForecast::toString() const
{
    QString s;
    QTextStream out(&s);
    out << "Location: " << this->location.address().text() << endl;
    out << "Coordinate: " << this->location.coordinate().toString() << endl;
    out << "Credit: " << this->credit << endl;
    out << "Credit URL: " << this->creditUrl.toString() << endl;
    out << "Last update: " << this->lastUpdate.toString() << endl;
    out << "Next update: " << this->nextUpdate.toString() << endl;
    out << "Sunrise: " << this->sunrise.toString() << endl;
    out << "Sunset: " << this->sunset.toString() << endl;
    for (auto forecast : this->forecasts) {
        out << forecast->toString();
    }
    return s;
}

void YrForecast::print()
{
    std::cout << this->toString().toStdString();
}

ForecastPoint* YrForecast::current()
{
    return forecasts.first();
}

void YrForecast::fetchSymbol(QUrl url)
{
    qInfo() << "Fetching symbol: " << url.toString();
    auto req = QNetworkRequest(url);
    this->networkmanager->get(req);
}

void YrForecast::symbolDownloaded(QNetworkReply* reply)
{
    auto url = reply->url();
    if (url.host() == "www.yr.no" && url.path().startsWith("/grafikk/sym")) {
        auto err = reply->error();
        if (err != QNetworkReply::NoError) {
            qCritical() << "Failed downloading symbol:" << err;
        }
        emit symbolUpdated(reply->readAll());
        reply->deleteLater();
    }
}


/////////////////////////////////////////
/// ForecastPoint stuff
/////////////////////////////////////////

QString ForecastPoint::toString() const
{
    QString s;
    QTextStream out(&s);
    out << from.toString() << " to " << to.toString() << " (" << period << "):" << endl;
    out << condition << ", " << temp << " " << tempUnit << ", "
        << precip << " mm (" << precipMin << "-" << precipMax << " mm), "
        << _windSpeed << " m/s " << windDir<< " degrees, " << endl;
    return s;
}

void ForecastPoint::print()
{
    std::cout << this->toString().toStdString();
}


QString ForecastPoint::temperature() const
{
    QString unit;
    if (this->tempUnit == "celsius") {
        unit = "°C";
    } else if (this->tempUnit == "fahrenheit") {
        unit = "°F";
    }
    return QString("%1").arg(this->temp) + unit;
}
QString ForecastPoint::precipitation() const
{
    return QString("%1").arg(this->precipMin) + " - "
            + QString("%1").arg(this->precipMax) + " mm";
}

QString ForecastPoint::time() const
{
    QString ret;
    QTextStream s(&ret);
    s << "" << this->from.toString(Qt::SystemLocaleShortDate) << endl
      << QString::fromUtf8("\u2192 ") << this->to.toString(Qt::SystemLocaleShortDate);
    return ret;
}

QUrl ForecastPoint::symbolUrl() const
{
    return this->symbol;
}
