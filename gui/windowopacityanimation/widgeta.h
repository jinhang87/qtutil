#ifndef WIDGETA_H
#define WIDGETA_H

#include <QWidget>

namespace Ui {
class WidgetA;
}

class WidgetA : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetA(QWidget *parent = 0);
    ~WidgetA();

private:
    Ui::WidgetA *ui;
};

#endif // WIDGETA_H
