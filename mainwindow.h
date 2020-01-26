#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include "yrforecast.h"

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
    void updateForecast(QString summary, QUrl icon);

protected:
    QNetworkAccessManager networkmanager;

private:
    Ui::MainWindow *ui;
    YrForecast *forecast;

};

#endif // MAINWINDOW_H
