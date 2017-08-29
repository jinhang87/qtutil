#ifndef WIDGETD_H
#define WIDGETD_H

#include <QWidget>

namespace Ui {
class WidgetD;
}

class WidgetD : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetD(QWidget *parent = 0);
    ~WidgetD();

private:
    Ui::WidgetD *ui;
};

#endif // WIDGETD_H
