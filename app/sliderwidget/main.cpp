#include "SliderWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SliderWindow w;
	w.show();
	return a.exec();
}
