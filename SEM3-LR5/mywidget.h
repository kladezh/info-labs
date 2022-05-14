#pragma once

#include <QtWidgets>
#include "ui_mywidget.h"

#include "stringreplacestrategy.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = Q_NULLPTR);

    StringReplaceStrategy* getStringReplaceStrategy() const;

    QString getEditSearchString() const;
    QString getEditSubjectString() const;
    QString getEditReplaceString() const;

public slots:
    void replaceOccurrences();

private:
    Ui::MyWidgetClass ui;

    QButtonGroup* btnGroup;
    StringReplaceStrategy* strStrategy;
};
