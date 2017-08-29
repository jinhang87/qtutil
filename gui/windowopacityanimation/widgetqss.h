#ifndef WIDGETQSS_H
#define WIDGETQSS_H

#include <QWidget>

namespace Ui {
class WidgetQss;
}

class WidgetQss : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetQss(QWidget *parent = 0);
    ~WidgetQss();

private:
    Ui::WidgetQss *ui;
};

#endif // WIDGETQSS_H
