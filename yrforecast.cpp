#include "yrforecast.h"
#include <iostream>
#include <QGeoAddress>
#include <QGeoCoordinate>
#include <QFile>

YrForecast::YrForecast(QObject *parent) : QObject(parent)
{

}

bool YrForecast::readXml(QString filename)
{
    QFile f(filename);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        std::cout << "Cannot read file: " << f.errorString().toStdString() << std::endl;
        exit(1);
    }

    this->xml.setDevice(&f);
    if (this->xml.readNextStartElement()) {
        if (this->xml.name() != "weatherdata") {
            this->xml.raiseError("Unexpected file format. Expected <weatherdata> start tag");
        }
        else {
            this->readWeatherData();
        }
    }
    if (this->xml.hasError()) {
        std::cout << "XML parse error: " << this->xml.errorString().toStdString() << std::endl;
        return false;
    }
    this->xml.clear();
    f.close();
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
    std::cout << "Skipping link data" << std::endl;
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
            std::cout << "Skipping: " << name.toStdString() << std::endl;
            this->xml.skipCurrentElement();
        }
    }
}

void YrForecast::readForecastTabular()
{
    while (this->xml.readNextStartElement()) {
        auto name = this->xml.name().toString();
        if (name == "time") {
            ForecastPoint* point = new ForecastPoint;
            auto attrs = this->xml.attributes();
            point->from = QDateTime::fromString(attrs.value("from").toString(), Qt::ISODate);
            point->to = QDateTime::fromString(attrs.value("to").toString(), Qt::ISODate);
            point->period = attrs.value("from").toInt();
            forecasts.append(point);
            this->readForecastPoint(point);
        } else {
            // Unknown tags. Should not really appear. Perhaps a warning?
            this->xml.skipCurrentElement();
        }
    }
}

void YrForecast::readForecastPoint(ForecastPoint* point)
{
    while (this->xml.readNextStartElement()) {
        auto name = this->xml.name().toString();
        auto attrs = this->xml.attributes();
        if (name == "symbol") {
            // https://symbol.yr.no/grafikk/sym/svg/{var}.svg
            // Eg. https://symbol.yr.no/grafikk/sym/svg/34.svg (for var = '34')
            point->condition = attrs.value("name").toString();
            auto symId = attrs.value("var").toString();
            point->symbol = QUrl(QString("https://symbol.yr.no/grafikk/sym/svg/%1.svg").arg(symId));
            this->xml.skipCurrentElement();
        } else if (name == "precipitation") {
            point->precipitation = attrs.value("value").toDouble();
            point->precipitationMin = attrs.value("minvalue").toDouble();
            point->precipitationMax = attrs.value("maxvalue").toDouble();
            this->xml.skipCurrentElement();
        } else if (name == "windDirection") {
            point->windDirection = attrs.value("deg").toDouble();
            this->xml.skipCurrentElement();
        } else if (name == "windSpeed") {
            point->windSpeed = attrs.value("mps").toDouble();
            this->xml.skipCurrentElement();
        } else if (name == "temperature") {
            point->temperature = attrs.value("value").toDouble();
            point->temperatureUnit = attrs.value("unit").toString();
            this->xml.skipCurrentElement();
        } else if (name == "pressure") {
            point->pressure = attrs.value("value").toDouble();
            point->pressureUnit = attrs.value("unit").toString();
            this->xml.skipCurrentElement();
        } else {
            // Unknown tags. Should not really appear. Perhaps a warning?
            this->xml.skipCurrentElement();
        }
    }
}

void YrForecast::readObservation()
{
    std::cout << "Skipping weatherstation data" << std::endl;
    this->xml.skipCurrentElement();
}

void YrForecast::print()
{
    std::cout << "Location: " << this->location.address().text().toStdString() << std::endl;
    std::cout << "Coordinate: " << this->location.coordinate().toString().toStdString() << std::endl;
    std::cout << "Credit: " << this->credit.toStdString() << std::endl;
    std::cout << "Credit URL: " << this->creditUrl.toString().toStdString() << std::endl;
    std::cout << "Last update: " << this->lastUpdate.toString().toStdString() << std::endl;
    std::cout << "Next update: " << this->nextUpdate.toString().toStdString() << std::endl;
    std::cout << "Sunrise: " << this->sunrise.toString().toStdString() << std::endl;
    std::cout << "Sunset: " << this->sunset.toString().toStdString() << std::endl;
    for (auto forecast : this->forecasts) {
        std::cout << forecast->from.toString().toStdString() << " to "
                  << forecast->to.toString().toStdString() << " ("
                  << forecast->period << "):" << std::endl;
        std::cout << forecast->condition.toStdString() << ", " << forecast->temperature << " "
                  << forecast->temperatureUnit.toStdString() << ", " << forecast->precipitation
                  << " mm (" << forecast->precipitationMin << "-" << forecast->precipitationMax << " mm), "
                  << forecast->windSpeed << " m/s " << forecast->windDirection << " degrees, "
                  << std::endl;
    }
}
