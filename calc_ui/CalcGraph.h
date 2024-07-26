#pragma once

#include <QWidget>

class CalcGraph : public QWidget
{
	Q_OBJECT

public:
	CalcGraph(QWidget *parent = nullptr);
	~CalcGraph();
	QSize minimumSizeHint() const override;
	QSize sizeHint() const override;
	double Schrittweite(int u);
	void YBerechnen(int u, int i);
	void YBerechnenLog(double u, double i);
protected:
	void paintEvent(QPaintEvent* event) override;
	double Werte[2][10];
};
