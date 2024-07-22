#include "CalcMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalcMainWindow w;
    w.show();
    return a.exec();
}
