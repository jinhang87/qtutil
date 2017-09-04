#include "slideswitch.h"
#include <QPainter>
#include <QMouseEvent>

SlideSwitch::SlideSwitch(QWidget *parent) : QWidget(parent)
{
    // 鼠标滑过光标形状 - 手型
    setCursor(Qt::PointingHandCursor);

    // 连接信号槽
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

bool SlideSwitch::checked() const
{
    return m_checked;
}

void SlideSwitch::setChecked(bool checked)
{
    m_checked = checked;
    m_timer.start(interval());
}

void SlideSwitch::onTimeout()
{
    if (m_checked) {
        m_nX += 1;
        if (m_nX >= width() - m_nHeight)
            m_timer.stop();
    } else {
        m_nX -= 1;
        if (m_nX <= m_nHeight / 2)
            m_timer.stop();
    }
    update();
}

int SlideSwitch::interval()
{
    int timeInterval = 5;
    if(m_speed > 0 && m_speed <= 10){
        timeInterval = 10 - m_speed + 1;
    }
    return timeInterval;
}

void SlideSwitch::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

      QPainter painter(this);
      painter.setPen(Qt::NoPen);
      painter.setRenderHint(QPainter::Antialiasing);

      QPainterPath path;
      QColor background;
      QColor thumbColor;
      qreal dOpacity;
      if (isEnabled()) { // 可用状态
          if (m_checked) { // 打开状态
              background = m_checkedColor;
              thumbColor = m_checkedColor;
              dOpacity = 0.600;
          } else { //关闭状态
              background = m_background;
              thumbColor = m_thumbColor;
              dOpacity = 0.800;
          }
      } else {  // 不可用状态
          background = m_background;
          dOpacity = 0.260;
          thumbColor = m_disabledColor;
      }
      // 绘制大椭圆
      painter.setBrush(background);
      painter.setOpacity(dOpacity);
      path.addRoundedRect(QRectF(m_nMargin, m_nMargin, width() - 2 * m_nMargin, height() - 2 * m_nMargin), m_radius, m_radius);
      painter.drawPath(path.simplified());

      // 绘制小椭圆
      painter.setBrush(thumbColor);
      painter.setOpacity(1.0);
      painter.drawEllipse(QRectF(m_nX - (m_nHeight / 2), m_nY - (m_nHeight / 2), height(), height()));
}

void SlideSwitch::mousePressEvent(QMouseEvent *event)
{
    if (isEnabled()) {
        if (event->buttons() & Qt::LeftButton) {
            event->accept();
        } else {
            event->ignore();
        }
    }
}

void SlideSwitch::mouseReleaseEvent(QMouseEvent *event)
{
    if (isEnabled()) {
        if ((event->type() == QMouseEvent::MouseButtonRelease) && (event->button() == Qt::LeftButton)) {
            event->accept();
            m_checked = !m_checked;
            emit toggled(m_checked);
            m_timer.start(interval());
        } else {
            event->ignore();
        }
    }
}

void SlideSwitch::resizeEvent(QResizeEvent *event)
{
    m_nX = m_nHeight / 2;
    m_nY = m_nHeight / 2;
    QWidget::resizeEvent(event);
}

QSize SlideSwitch::sizeHint() const
{
    return minimumSizeHint();
}

QSize SlideSwitch::minimumSizeHint() const
{
    return QSize(2 * (m_nHeight + m_nMargin), m_nHeight + 2 * m_nMargin);
}

void SlideSwitch::setSpeed(int speed)
{
    m_speed = speed;
}

