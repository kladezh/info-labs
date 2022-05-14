#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    dataFile = "data.csv";

    ui.tableWidget->setColumnCount(5);
    ui.tableWidget->setHorizontalHeaderLabels(QStringList() << "id" << "fullname" << "passport" << "tel" << "department");

    initTable();

    // on Create click
    connect(ui.btnCreate, &QPushButton::clicked, [=]() {
        ui.tableWidget->insertRow(ui.tableWidget->rowCount());
        });

    // on Delete click
    connect(ui.btnDelete, &QPushButton::clicked, [=]() {
        auto table = ui.tableWidget;
        for (const QModelIndex& index : table->selectionModel()->selectedRows()) {
            table->removeRow(index.row());
        }
        });

    // on Update click
    connect(ui.btnUpdate, SIGNAL(clicked()), this, SLOT(saveToFile()));

    connect(ui.btnLoad, SIGNAL(clicked()), this, SLOT(initTable()));
}

void MainWindow::initTable()
{
    QFile file(this->dataFile);

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "file cannot be opened...\n";
        return;
    }

    QTextStream fin(&file);

    ui.tableWidget->setRowCount(0);
    while (!fin.atEnd()) {
        int column = 0;
        int row = ui.tableWidget->rowCount();
        ui.tableWidget->insertRow(row);

        QString line = fin.readLine();
        for (const QString& item : line.split(",")) {
            ui.tableWidget->setItem(row, column, new QTableWidgetItem(item));
            column++;
        }
    }

    file.close();
}

void MainWindow::saveToFile()
{
    QFile file(this->dataFile);

    if (!file.open(QFile::WriteOnly | QFile::Truncate | QFile::Text)) {
        qDebug() << "file cannot be opened...\n";
        return;
    }

    QString out;
    for (int row = 0; row < ui.tableWidget->rowCount(); row++) {
        for (int column = 0; column < ui.tableWidget->columnCount(); column++) {
            QString record = ui.tableWidget->item(row, column)->data(Qt::EditRole).toString();
            out += record + ",";
        }
        out += '\n';
    }
    out.replace(",\n", "\n");

    QTextStream fout(&file);
    fout << out;

    file.close();
}