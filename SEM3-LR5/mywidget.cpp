#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui.radioFirstOccur);
    btnGroup->addButton(ui.radioLastOccur);
    btnGroup->addButton(ui.radioAllOccur);

    connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(replaceOccurrences()));
}

StringReplaceStrategy* MyWidget::getStringReplaceStrategy() const
{
    QString btnName = this->btnGroup->checkedButton()->objectName();

    if (btnName == "radioFirstOccur") {
        return new StringReplaceFirstStrategy();
    }

    if (btnName == "radioLastOccur") {
        return new StringReplaceLastStrategy();
    }

    if (btnName == "radioAllOccur") {
        return new StringReplaceAllStrategy();
    }

    return new StringReplaceAllStrategy();
}

QString MyWidget::getEditSearchString() const
{
    return ui.editSearch->text();
}
QString MyWidget::getEditSubjectString() const
{
    return ui.editSubject->text();
}
QString MyWidget::getEditReplaceString() const
{
    return ui.editReplace->text();
}

void MyWidget::replaceOccurrences()
{
    QString search = getEditSearchString();
    QString subject = getEditSubjectString();
    QString replace = getEditReplaceString();

    this->strStrategy = getStringReplaceStrategy();

    QString result = strStrategy->replace(search, subject, replace);

    ui.lblOutput->setText(result);
}
