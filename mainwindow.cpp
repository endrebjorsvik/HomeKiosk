#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto url = QUrl("https://www.yr.no/stad/Noreg/Vestland/Bergen/Nesttun/varsel.xml");
    this->forecast = new YrForecast(url, &this->networkmanager, this);
    ui->indoor->setText("24.3°C");
    ui->outdoor->setText("11.4°C");
    ui->forecast->setText("");
    ui->power->setText("5600 W");
    connect(this->forecast, &YrForecast::forecastUpdated,
            this, &MainWindow::updateForecast);
    this->forecast->fetchForecast();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete forecast;
}

void MainWindow::updateForecast(QString summary, QUrl symbol)
{
    ui->forecast->setText(summary);
}
