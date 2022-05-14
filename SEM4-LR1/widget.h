#pragma once

#include <QtWidgets>
#include "ui_widget.h"

#include "tablemodel.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = Q_NULLPTR);

public slots:
    void randomFillModel();
    void itemDumpInfo(const QModelIndex& index);

private:
    Ui::WidgetClass ui;

    QAbstractTableModel* tableModel;
};
