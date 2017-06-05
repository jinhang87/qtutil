#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QLinearGradient>
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveScreen()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QPixmap fullScreenPixmap = screen->grabWindow(0);
    fullScreenPixmap.save("fullScreen.jpg","JPG");
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    qDebug() << "paintEvent";
#if 0
    QPainter painter(this);
    painter.fillRect(this->rect(),QColor(0,0xff,0,0x01));
#endif

#if 0
    QPixmap covert_pixmap(":/image/logo.jpg");
    QPixmap pixmap(covert_pixmap.width(), covert_pixmap.height());
    pixmap.fill(Qt::transparent);
    qDebug() << "paintEvent: w = " << covert_pixmap.width() << "h = " << covert_pixmap.height();

    QPainter painter(&pixmap);
    QPoint start_point(0, 0);
    QPoint end_point(0, pixmap.height());
    //QLinearGradient进行渐变色设置
    QLinearGradient linear_gradient(start_point, end_point);
    linear_gradient.setColorAt(0, QColor(255, 255, 255, 100));
    linear_gradient.setColorAt(0.5, QColor(255, 255, 255, 150));
    linear_gradient.setColorAt(1, QColor(255, 255, 255, 255));
    painter.fillRect(this->rect(), QBrush(linear_gradient));
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.drawPixmap(0, 0, covert_pixmap);
    painter.end();

    QPainter painter2(this);
    painter2.drawPixmap(0, 0, pixmap);
#endif
#if 0
    QPixmap pixmap = QPixmap(":/image/logo.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
#endif
    saveScreen();
}
