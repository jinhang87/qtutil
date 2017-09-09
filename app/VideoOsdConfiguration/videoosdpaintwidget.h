#ifndef VIDEOOSDPAINTWIDGET_H
#define VIDEOOSDPAINTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHash>
#include <QGridLayout>
#include <QTimer>

class VideoOsdPaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoOsdPaintWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;
signals:

public slots:
private:
    int m_row = 12;
    int m_column = 11;
    QGridLayout* m_layout = nullptr;
    QLabel *m_label = nullptr;
    QHash<QWidget*, QPoint> m_hashWidgets;
    QTimer *timer = nullptr;
};

#endif // VIDEOOSDPAINTWIDGET_H
