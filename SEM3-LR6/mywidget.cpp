#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    connect(ui.btnGenerate, SIGNAL(clicked()), this, SLOT(generateArray()));

    connect(ui.btnFindNum, SIGNAL(clicked()), this, SLOT(findNumInArray()));
    connect(this, SIGNAL(numWasFound(int)), this, SLOT(printFoundMessage(int)));
    connect(this, SIGNAL(numWasNotFound()), this, SLOT(printNotFoundMessage()));

    array.resize(0);
}

int MyWidget::getEditArraySize() const
{
    return ui.editArraySize->value();
}
int MyWidget::getEditNumToFind() const
{
    return ui.editNumToFind->text().toInt();
}

void MyWidget::generateArray()
{
    QString out;
    int size = getEditArraySize();

    array.resize(size);
    out += "QList<int>: size = " + QString::number(size) + "\n\n";

    QRandomGenerator* rand = new QRandomGenerator((quint32)QDateTime::currentDateTime().time().msec());
    for (int i = 0; i < size; i++) {
        array[i] = rand->bounded(-100, 100);
        out += QString::number(i) + "=> " + QString::number(array[i]) + "\n";
    }

    ui.lblArray->setText(out);
}

void MyWidget::findNumInArray()
{
    int num = getEditNumToFind();
    int index = array.indexOf(num);

    if (index == -1) {
        emit numWasNotFound();
    }
    else {
        emit numWasFound(index);
    }
}

void MyWidget::printFoundMessage(int index)
{
    QString out;
    out += "Число найдено по индексу = " + QString::number(index);

    ui.lblOutput->setText(out);
}

void MyWidget::printNotFoundMessage()
{
    QString out;
    out += "Число не найдено...";

    ui.lblOutput->setText(out);
}
