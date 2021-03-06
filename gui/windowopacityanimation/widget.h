#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPropertyAnimation;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int alpha READ alpha WRITE setAlpha)
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int alpha() const;
    void setAlpha(const int alpha);
    qreal opacity() const;
    void setOpacity(const qreal opacity);

private slots:
    void onBtnClicked();

private:
    Ui::Widget *ui;
    int m_nAlpha;
    qreal m_fOpacity;
    QPropertyAnimation *pAnimation;
    QPropertyAnimation *pAnimation2;
};

#endif // WIDGET_H
