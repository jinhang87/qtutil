#ifndef SLIDESWITCH_H
#define SLIDESWITCH_H

#include <QWidget>
#include <QTimer>

class SlideSwitch : public QWidget
{
    Q_OBJECT
public:
    explicit SlideSwitch(QWidget *parent = 0);
    bool checked() const;
    void setChecked(bool checked);
    void setSpeed(int speed);

signals:
    // 状态改变时，发射信号
    void toggled(bool checked);

public slots:
    // 状态切换时，用于产生滑动效果
    void onTimeout();
    // 状态切换时间间隔
    int interval();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;

private:
    // 是否选中
    bool m_checked = false;
    // 背景颜色
    QColor m_background = Qt::black;
    // 选中颜色
    QColor m_checkedColor = QColor(0, 150, 136);
    // 不可用颜色
    QColor m_disabledColor = QColor(190, 190, 190);
    // 拇指颜色
    QColor m_thumbColor = Qt::white;
    // 圆角
    qreal m_radius = 8.0;
    // x点坐标
    qreal m_nX;
    // y点坐标
    qreal m_nY;
    // 高度
    qint16 m_nHeight = 16;
    // 外边距
    qint16 m_nMargin = 3;
    // 滑动速度（1~10）
    int m_speed = 5;
    // 定时器
    QTimer m_timer;
};

#endif // SLIDESWITCH_H
