#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include "yrforecast.h"
#include "dtauth.h"
#include "dtsensor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateForecast(QString temp, QString precip, QString time);
    void updateForecastSymbol(QByteArray data);

protected:
    QNetworkAccessManager networkmanager;

private:
    Ui::MainWindow *ui;
    YrForecast *forecast;
    DTAuth *dtAuth;
    DTSensor *sensor;
};

#endif // MAINWINDOW_H
