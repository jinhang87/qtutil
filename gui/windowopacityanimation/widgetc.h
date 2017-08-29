#ifndef WIDGETC_H
#define WIDGETC_H

#include <QWidget>

namespace Ui {
class WidgetC;
}

class WidgetC : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetC(QWidget *parent = 0);
    ~WidgetC();

    void paintEvent(QPaintEvent *event);

private:
    Ui::WidgetC *ui;
};

#endif // WIDGETC_H
