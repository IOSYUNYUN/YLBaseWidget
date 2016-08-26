#include "basewidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BaseWidget w;
	w.show();
	return a.exec();
}
