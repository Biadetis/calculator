#include "CalcMainWindow.h"
#include "..\calc\framework.h"

CalcMainWindow::CalcMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.PotenzExec, &QPushButton::clicked, this, &CalcMainWindow::OnClickPotenzExec);
}

CalcMainWindow::~CalcMainWindow()
{}
void CalcMainWindow::OnClickPotenzExec()
{
    int u;
    int i;
    int result;
    QString UString = ui.PotenzInput1->toPlainText();
    QString IString = ui.PotenzInput2->toPlainText();
    u = UString.toInt();
    i = IString.toInt();
    result = PotenzBerechnen(u, i);
    QString ResultString = QString::number(result);
    ui.PotenzOutput->setPlainText(ResultString);
}