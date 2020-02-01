#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto url = QUrl("https://www.yr.no/stad/Noreg/Vestland/Bergen/Nesttun/varsel.xml");
    this->forecast = new YrForecast(url, &this->networkmanager, this);
    ui->indoor->setText("24.3°C");
    ui->outdoor->setText("11.4°C");
    ui->power->setText("5600 W");
    connect(this->forecast, &YrForecast::forecastUpdated,
            this, &MainWindow::updateForecast);
    connect(this->forecast, &YrForecast::symbolUpdated,
            this, &MainWindow::updateForecastSymbol);
    this->forecast->startTimer();
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

