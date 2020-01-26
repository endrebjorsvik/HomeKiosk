#include "yrforecast.h"
#include <iostream>
#include <QGeoAddress>
#include <QGeoCoordinate>
#include <QFile>

YrForecast::YrForecast(QObject *parent) : QObject(parent)
{

}

bool YrForecast::readXmlFile(QFile &f)
{

    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        std::cout << "Cannot read file: " << f.errorString().toStdString() << std::endl;
        exit(1);
    }
    auto res = this->readXml(f.readAll());
    f.close();
    return res;
}

bool YrForecast::readXml(QByteArray stream)
{
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
        std::cout << "XML parse error: " << this->xml.errorString().toStdString() << std::endl;
        return false;
    }
    this->xml.clear();
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

void YrForecast::readObservation()
{
    std::cout << "Skipping weatherstation data" << std::endl;
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

void ForecastPoint::readXml(QXmlStreamReader* xml)
{
    while (xml->readNextStartElement()) {
        auto name = xml->name().toString();
        auto attrs = xml->attributes();
        if (name == "symbol") {
            // https://symbol.yr.no/grafikk/sym/svg/{var}.svg
            // Eg. https://symbol.yr.no/grafikk/sym/svg/34.svg (for var = '34')
            this->condition = attrs.value("name").toString();
            auto symId = attrs.value("var").toString();
            this->symbol = QUrl(QString("https://symbol.yr.no/grafikk/sym/svg/%1.svg").arg(symId));
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
        forecast->print();
    }
}

ForecastPoint* YrForecast::current()
{
    return forecasts[0];
}

void ForecastPoint::print()
{
    std::cout << from.toString().toStdString() << " to " << to.toString().toStdString()
              << " (" << period << "):" << std::endl;
    std::cout << condition.toStdString() << ", " << temp<< " " << tempUnit.toStdString()
              << ", " << precip << " mm (" << precipMin << "-" << precipMax << " mm), "
              << _windSpeed << " m/s " << windDir<< " degrees, " << std::endl;
}

QString ForecastPoint::shortSummary()
{
    QString unit;
    if (this->tempUnit == "celsius") {
        unit = "°C";
    } else if (this->tempUnit == "fahrenheit") {
        unit = "°F";
    }
    return this->condition + ", " + QString("%1").arg(this->temp) + unit + ",\n"
            + QString("%1").arg(this->precipMin) + "-"
            + QString("%1").arg(this->precipMax) + " mm";
}
