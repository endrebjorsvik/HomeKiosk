#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "yrforecast.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    YrForecast forecast;
    QFile f("/home/endre/Programmering/Qt/DTKiosk/data/varsel.xml");
    forecast.readXmlFile(f);
    ui->indoor->setText("24.3°C");
    ui->outdoor->setText("11.4°C");
    ui->forecast->setText(forecast.current()->shortSummary());
    ui->power->setText("5600 W");
}

MainWindow::~MainWindow()
{
    delete ui;
}
