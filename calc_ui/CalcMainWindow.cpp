#include "CalcMainWindow.h"
#include "..\calc\framework.h"

CalcMainWindow::CalcMainWindow(QWidget* parent)
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
	bool uOK = false;
	bool iOK = false;

	QString UString = ui.PotenzInput1->text();
	QString IString = ui.PotenzInput2->text();
	u = UString.toInt(&uOK);
	i = IString.toInt(&iOK);
	if (uOK == false || iOK == false)
	{
		ui.PotenzOutput->setHtml("<p style=\"color:red;\">Keine Zahl erkannt!</p>");
	}
	else
	{
		result = PotenzBerechnen(u, i);
		QString ResultString = QString::number(result);
		ui.PotenzOutput->setPlainText(ResultString);
	}
}