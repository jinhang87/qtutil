#ifndef IRREGULARPAINTER_H
#define IRREGULARPAINTER_H

#include <QWidget>

class IrregularPainter : public QWidget
{
    Q_OBJECT
public:
    explicit IrregularPainter(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event) override;
signals:

public slots:

private:

};

#endif // IRREGULARPAINTER_H
