#include "CalcGraph.h"
#include <qpainter.h>
#include "..\calc\framework.h"

CalcGraph::CalcGraph(QWidget *parent)
	: QWidget(parent)
{
	for (int index = 0; index < 10; index++)
	{
		Werte[0][index] = 0;
		Werte[1][index] = 0;
	}
}

CalcGraph::~CalcGraph()
{}
void CalcGraph::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 3));
	QRect rect = this->rect();
	painter.drawRect(rect);
	double f1 = (double)rect.width() / (double) Werte[0][9];
	double f2 = (double)rect.height() / (double)Werte[1][9];
	double f = f1 < f2 ? f1 : f2;

	QPoint start((int) Werte[0][0]*f1, rect.height()-(int)Werte[1][0]*f2);
	for (int index = 0; index < 9; index++)
	{
		QPoint end((int)Werte[0][index + 1]*f1, rect.height()-(int)Werte[1][index + 1]*f2);
		painter.drawLine(start, end);
		start = end;
	}
}
QSize CalcGraph::minimumSizeHint() const
{
	return QSize(100, 100);
}
QSize CalcGraph::sizeHint() const
{
	return QSize(200, 200);
}
double CalcGraph::Schrittweite(int u)
{
	return (double)u / 10.0;
}
void CalcGraph::YBerechnen(int u, int i)
{
	double s = Schrittweite(u);
	for (int index = 0; index < 10; index++)
	{
		PotenzBerechnenDouble(index * s, u);
		Werte[0][index] = index * s;
		Werte[1][index] = PotenzBerechnenDouble(index * s, i);
	}
	update();
}
void CalcGraph::YBerechnenLog(double u, double i)
{
	double s = Schrittweite(u);
	for (int index = 0; index < 10; index++)
	{
		LogBerechnen(index * s, u);
		Werte[0][index] = index * s;
		Werte[1][index] = LogBerechnen(index * s, i);
	}
	update();
}