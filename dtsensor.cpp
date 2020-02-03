#include "dtsensor.h"
#include <QDebug>
#include <QNetworkRequest>
#include <iostream>


DTSensor::DTSensor(const QString &sensorId, const QString &projectId, DTAuth *auth, QNetworkAccessManager *nm, QObject *parent) : QObject(parent), networkManager(nm), auth(auth)
{
    this->sensorId = sensorId;
    this->projectId = projectId;
    connect(this->networkManager, &QNetworkAccessManager::finished,
            this, &DTSensor::dataDownloaded);
}

void DTSensor::downloadData(const QString &accessToken)
{
    // curl
    //   -X GET
    //   "https://api.disruptive-technologies.com/v2/projects/bfn87ac77eqnkh13caf0/devices/bchoq157rihkdo9k64r0"
    //   "https://api.disruptive-technologies.com/v2/projects/{project}/devices/{device}"
    //   -H  "accept: application/json"
    //   -H  "Authorization: Bearer dd7ef67e13f143229c5a0e3b4a0dfc52"

    QUrl url(QString("https://api.disruptive-technologies.com/v2/projects/%1/devices/%2").arg(this->projectId).arg(this->sensorId));
    QNetworkRequest req(url);
    req.setRawHeader("accept", "application/json");
    req.setRawHeader("Authorization", "Bearer " + accessToken.toUtf8());
    networkManager->get(req);
}

void DTSensor::dataDownloaded(QNetworkReply *reply)
{
    if (reply->url().host() == "api.disruptive-technologies.com") {
        auto err = reply->error();
        if (err != QNetworkReply::NoError) {
            qCritical() << "Failed requesting sensor data:" << err;
        }
        reply->deleteLater();

        std::cout << "Sensor data:" << reply->readAll().toStdString() << std::endl;
    }

    // Response
    /*
    {
      "name": "projects/bfn87ac77eqnkh13caf0/devices/bchoq157rihkdo9k64r0",
      "type": "temperature",
      "labels": {
        "name": "Iskaldt!"
      },
      "reported": {
        "networkStatus": {
          "signalStrength": 73,
          "updateTime": "2020-02-02T10:41:40.500000Z",
          "cloudConnectors": [
            {
              "id": "bc22bqqv0000jh5dp3t0",
              "signalStrength": 41
            },
            {
              "id": "bmi7glsc0001n77v5qkg",
              "signalStrength": 73
            }
          ],
          "transmissionMode": "LOW_POWER_STANDARD_MODE"
        },
        "batteryStatus": {
          "percentage": 75,
          "updateTime": "2020-02-02T02:50:53.435000Z"
        },
        "temperature": {
          "value": -18.6,
          "updateTime": "2020-02-02T10:41:40.503000Z"
        },
        "touch": {
          "updateTime": "2019-12-03T20:55:15.701000Z"
        }
      }
    }
    */
    /*
    {
      "name": "projects/bfn87ac77eqnkh13caf0/devices/bbldhpl7rihhgba7vnr0",
      "type": "proximity",
      "labels": {
        "description": "Inni",
        "name": "Ytterdal"
      },
      "reported": {
        "networkStatus": {
          "signalStrength": 85,
          "updateTime": "2020-02-02T10:39:42.485000Z",
          "cloudConnectors": [
            {
              "id": "bmi7glsc0001n77v5qkg",
              "signalStrength": 30
            },
            {
              "id": "bc22bqqv0000jh5dp3t0",
              "signalStrength": 85
            }
          ],
          "transmissionMode": "LOW_POWER_STANDARD_MODE"
        },
        "batteryStatus": {
          "percentage": 100,
          "updateTime": "2020-02-01T10:29:02.843000Z"
        },
        "objectPresent": {
          "state": "PRESENT",
          "updateTime": "2020-02-02T01:59:43.309000Z"
        },
        "touch": {
          "updateTime": "2018-09-11T18:18:34.858996Z"
        }
      }
    } */
}
