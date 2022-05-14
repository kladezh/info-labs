#pragma once

#include <QtWidgets/QMainWindow>
#include <QFile>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

public slots:
    void initTable();
    void saveToFile();

private:
    Ui::MainWindowClass ui;

    QString dataFile;
};
