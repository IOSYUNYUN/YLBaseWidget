#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QtWidgets/QMainWindow>
#include "ui_basewidget.h"

class BaseWidget : public QMainWindow
{
	Q_OBJECT

public:
	BaseWidget(QWidget *parent = 0);
	~BaseWidget();

private:
	Ui::BaseWidgetClass ui;
};

#endif // BASEWIDGET_H
