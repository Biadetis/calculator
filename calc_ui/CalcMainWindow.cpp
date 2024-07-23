#include "CalcMainWindow.h"
#include "..\calc\framework.h"

CalcMainWindow::CalcMainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.PotenzExec, &QPushButton::clicked, this, &CalcMainWindow::OnClickPotenzExec);
	connect(ui.FakultaetExec, &QPushButton::clicked, this, &CalcMainWindow::OnClickFakultaetExec);
	connect(ui.LogExec, &QPushButton::clicked, this, &CalcMainWindow::OnClickLogExec);

	QPixmap bkgnd(":/CalcMainWindow/AdobeStock_290928080.jpeg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Window, bkgnd);
	this->setPalette(palette);
}

CalcMainWindow::~CalcMainWindow()
{}
void CalcMainWindow::OnClickLogExec()
{
	double u;
	double i;
	double result;
	bool uOK = false;
	bool iOK = false;
	QString LString1 = ui.LogInput1->text();
	QString LString2 = ui.LogInput2->text();
	u = LString1.toDouble(&uOK);
	i = LString2.toDouble(&iOK);
	if (uOK == false ||iOK == false)
	{
		ui.LogOutput->setHtml("<p style=\"color:red;\">Keine Zahl erkannt!</p>");
	}
	else
	{
		result = LogBerechnen(u,i);
		QString ResultString = QString::number(result);
		ui.LogOutput->setHtml("<p>log<sub>" + LString1 + "</sub>(" + LString2 + ") = " + ResultString +  "</p>");
	}
}
void CalcMainWindow::OnClickFakultaetExec()
{
	int u;
	int result;
	bool uOK = false;
	QString UString = ui.FakultaetInput->text();
	u = UString.toInt(&uOK);
	if (uOK == false)
	{
		ui.FakultaetOutput->setHtml("<p style=\"color:red;\">Keine Zahl erkannt!</p>");
	}
	else
	{
		result = FakultaetBerechnen(u);
		QString ResultString = QString::number(result);
		ui.FakultaetOutput->setHtml("<p>" + UString + "!" + " = " + ResultString + "< / p>");
	}

}
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
		ui.PotenzOutput->setHtml("<p>" + UString + "<sup>" + IString + "</sup> = " + ResultString + "</p>");
	}
}