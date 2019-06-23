#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "OAIHelpers.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->indoor->setText("22.4°C");
    ui->outdoor->setText("11.9°C");
    ui->forecast->setText("Sunny, 12°C");
    ui->power->setText("550 W");
}

MainWindow::~MainWindow()
{
    delete ui;
}
