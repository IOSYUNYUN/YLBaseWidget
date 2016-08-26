#include "basewidget.h"

BaseWidget::BaseWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

BaseWidget::~BaseWidget()
{

}
