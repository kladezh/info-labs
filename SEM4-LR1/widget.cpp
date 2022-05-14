#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // model
    tableModel = new TableModel(this);

    //ui
    ui.setupUi(this);

    //view
    ui.tableView->setModel(tableModel);
    ui.tableView->show();

    QObject::connect(ui.pushButtonGenerate, SIGNAL(clicked()),
        this, SLOT(randomFillModel()));

    QObject::connect(ui.tableView->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
        this, SLOT(itemDumpInfo(const QModelIndex&)));
}


void Widget::randomFillModel()
{
    for (int row = 0; row < tableModel->rowCount(); row++) {
        for (int column = 0; column < tableModel->columnCount(); column++) {
            int randNumber = rand() % 100;
            QModelIndex index = tableModel->index(row, column, QModelIndex());

            tableModel->setData(index, randNumber);
        }
    }
}

void Widget::itemDumpInfo(const QModelIndex& index)
{
    QMap<QString, int> item;

    item["x"] = index.row() + 1;
    item["y"] = index.column() + 1;
    item["number"] = item["y"] + tableModel->columnCount() * index.row();

    item["value"] = index.data().toInt();

    ui.labelInfo->setText(
        "X: " + QString::number(item["x"]) + "\n" +
        "Y: " + QString::number(item["y"]) + "\n" +
        "SEQUENCE NUMBER: " + QString::number(item["number"]) + "\n" +
        "VALUE: " + QString::number(item["value"]) + "\n" +
        "VALUE^2: " + QString::number(qPow(item["value"], 2)) + "\n" +
        "VALUE^3: " + QString::number(qPow(item["value"], 3))
    );
}
