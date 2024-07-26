#pragma once
#include <CalcGraph.h>
#include <QtWidgets/QMainWindow>
#include "ui_CalcMainWindow.h"

class CalcMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalcMainWindow(QWidget *parent = nullptr);
    ~CalcMainWindow();

private:
    Ui::CalcMainWindowClass ui;
    void OnClickPotenzExec();
    void OnClickFakultaetExec();
    void OnClickLogExec();
    void resizeEvent(QResizeEvent*);
    CalcGraph* Graph;
};
