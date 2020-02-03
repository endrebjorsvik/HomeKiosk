#ifndef DTSENSOR_H
#define DTSENSOR_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "dtauth.h"

class DTSensor : public QObject
{
    Q_OBJECT
public:
    explicit DTSensor(const QString &sensorId, const QString &projectId, DTAuth *auth, QNetworkAccessManager *nm, QObject *parent = nullptr);
    enum SensorType { UnknownType, Temperature, Proximity, Touch };
    Q_ENUM(SensorType)
    enum ProximityState { UnknownState, Present , NotPresent };
    Q_ENUM(ProximityState)


signals:

public slots:
    void downloadData(const QString &accessToken);
    void dataDownloaded(QNetworkReply *reply);

private:
    QString sensorId;
    QString projectId;

    SensorType type;
    QString name;
    QString description;
    QDateTime updated;

    double temperatureCelcius;
    QDateTime touchTime;
    ProximityState proximityState;

    int batteryPercentage;
    QMap<QString, int> cloudConnectors;

    QNetworkAccessManager *networkManager;
    DTAuth *auth;
};

#endif // DTSENSOR_H
