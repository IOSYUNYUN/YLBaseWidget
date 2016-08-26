#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QtWidgets/QMainWindow>
//#include "ui_basewidget.h"
#include "../YLBaseWidget/YLBaseWidget.h"

class BaseWidget : public YLBaseWidget
{
	Q_OBJECT

public:
	BaseWidget(QWidget *parent = 0);
	~BaseWidget();

private:
	//Ui::BaseWidgetClass ui;
};

#endif // BASEWIDGET_H
