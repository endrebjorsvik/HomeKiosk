#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "yrforecast.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->indoor->setText("22.4°C");
    ui->outdoor->setText("11.9°C");
    ui->forecast->setText("Sunny, 12°C");
    ui->power->setText("5600 W");
    YrForecast forecast;
    forecast.readXml("/home/endre/Programmering/Qt/DTKiosk/data/varsel.xml");
    forecast.print();
}

MainWindow::~MainWindow()
{
    delete ui;
}
