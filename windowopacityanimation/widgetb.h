#ifndef WIDGETB_H
#define WIDGETB_H

#include <QWidget>

namespace Ui {
class WidgetB;
}

class WidgetB : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetB(QWidget *parent = 0);
    ~WidgetB();

private:
    Ui::WidgetB *ui;
};

#endif // WIDGETB_H
