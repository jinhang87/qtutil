#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QWidget>

class MenuButton : public QWidget
{
    Q_OBJECT
public:
    explicit MenuButton(QWidget *parent = 0);

signals:

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

public slots:
};

#endif // MENUBUTTON_H
