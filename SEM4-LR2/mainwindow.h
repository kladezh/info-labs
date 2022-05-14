#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

    double graphF(double x, double k, double b);

private:
    Ui::MainWindowClass ui;

    const int X_RANGE_FROM = -10;
    const int X_RANGE_TO = 10;
    const int Y_RANGE_FROM = -100;
    const int Y_RANGE_TO = 100;

private slots:
    double getGraphCoefFirst();
    double getGraphCoefSecond();
    void on_drawButton_clicked();
};
