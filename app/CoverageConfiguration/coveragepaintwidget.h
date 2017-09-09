#ifndef COVERAGEPAINTWIDGET_H
#define COVERAGEPAINTWIDGET_H

#include <QWidget>

class CoveragePaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CoveragePaintWidget(QWidget *parent = 0);
    QPoint startPonit() const;
    QPoint endPoint() const;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
signals:

public slots:
private:
    QPoint m_startPonit;
    QPoint m_endPoint;
    bool m_bStart = false;
    bool m_bEnd = false;
    bool m_bReflush = true;
    bool m_isDrawing;
    QPixmap m_buffer;
    QPixmap m_TempBuffer;
};

#endif // COVERAGEPAINTWIDGET_H
