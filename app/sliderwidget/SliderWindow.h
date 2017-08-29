#ifndef SLIDERWINDOW_H
#define SLIDERWINDOW_H

#include <QMainWindow>
#include "ui_SliderWindow.h"

class SliderWindow : public QMainWindow
{
	Q_OBJECT

public:
	SliderWindow(QWidget *parent = 0);
	~SliderWindow();

private:
	Ui::SliderWindowClass ui;
};

#endif // SLIDERWINDOW_H
