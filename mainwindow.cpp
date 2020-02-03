#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>
#include <chrono>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configure weather forecast stuff
    auto url = QUrl("https://www.yr.no/stad/Noreg/Vestland/Bergen/Nesttun/varsel.xml");
    this->forecast = new YrForecast(url, &this->networkmanager, this);
    connect(this->forecast, &YrForecast::forecastUpdated,
            this, &MainWindow::updateForecast);
    connect(this->forecast, &YrForecast::symbolUpdated,
            this, &MainWindow::updateForecastSymbol);
    this->forecast->startTimer();

    // Configure sensor API
    QString secretsFile("/home/endre/Programmering/Qt/DTKiosk/auth.json");
    this->dtAuth = new DTAuth(secretsFile, &this->networkmanager, this);

    this->sensor = new DTSensor("bdoktet7rihjbm0413a0", "bfn87ac77eqnkh13caf0",
                                this->dtAuth, &this->networkmanager, this);
    connect(this->dtAuth, &DTAuth::authenticated,
            this->sensor, &DTSensor::downloadData);
    ui->indoor->setText("24.3°C");
    ui->outdoor->setText("11.4°C");

    // Configure power consumption stuff
    ui->power->setText("5600 W");

    this->dtAuth->authenticate();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete forecast;
}

void MainWindow::updateForecast(QString temp, QString precip, QString time)
{
    ui->forecastTemp->setText(temp);
    ui->forecastPrecip->setText(precip);
    ui->forecastTime->setText(time);
}

void MainWindow::updateForecastSymbol(QByteArray data)
{
    auto pix = QPixmap();
    pix.loadFromData(data, "PNG");
    ui->forecastSymbol->setPixmap(pix);
}

