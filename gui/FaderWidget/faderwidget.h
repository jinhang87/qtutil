#ifndef FADERWIDGET_H
#define FADERWIDGET_H

#include <QWidget>
#include <QTimer>

class FaderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FaderWidget(QWidget *parent = nullptr);
    void start();

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:

private:
    QColor startColor;
    int currentAlpha;
    int fadeTimes;
    QTimer *timer;
};

#endif // FADERWIDGET_H
