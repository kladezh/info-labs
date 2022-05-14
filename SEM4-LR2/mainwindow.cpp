#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.plotWidget->xAxis->setLabel("x");
    ui.plotWidget->xAxis->setLabel("y");

    ui.plotWidget->xAxis->setRange(X_RANGE_FROM, X_RANGE_TO);
    ui.plotWidget->yAxis->setRange(Y_RANGE_FROM, Y_RANGE_TO);
}

double MainWindow::graphF(double x, double k, double b)
{
    return k * sin(x + b);
}

double MainWindow::getGraphCoefFirst()
{
    return ui.firstCoefEdit->text().toDouble();
}

double MainWindow::getGraphCoefSecond()
{
    return ui.secondCoefEdit->text().toDouble();
}


void MainWindow::on_drawButton_clicked()
{
    double k = getGraphCoefFirst();
    double b = getGraphCoefSecond();

    int pointCount = (X_RANGE_TO - X_RANGE_FROM) * 10 + 1;

    QVector<double> x(pointCount), y(pointCount);

    for (int i = 0; i < pointCount; ++i)
    {
        x[i] = i / 10.0 + X_RANGE_FROM;
        y[i] = graphF(x[i], k, b);

        qDebug() << "x:" << x[i] << "   y:" << y[i];
    }

    ui.plotWidget->clearGraphs();

    ui.plotWidget->addGraph();
    ui.plotWidget->graph(0)->setData(x, y);
    ui.plotWidget->replot();
}