#pragma once

#include <QtWidgets>
#include "ui_mywidget.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = Q_NULLPTR);

    int getEditNumToFind() const;
    int getEditArraySize() const;

public slots:
    void generateArray();
    void findNumInArray();

    void printFoundMessage(int index);
    void printNotFoundMessage();

signals:
    void numWasFound(int index);
    void numWasNotFound();

private:
    Ui::MyWidgetClass ui;

    QList<int> array;
};
