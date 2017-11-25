#include "buttonimagedialog.h"
#include "ui_buttonimagedialog.h"
#include <QBitmap>
#include <QDebug>

ButtonImageDialog::ButtonImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ButtonImageDialog)
{
    ui->setupUi(this);
    QPixmap pixmapclick(QString(":/image/click.png"));
    QPixmap pixmapnormal(QString(":/image/normal.png"));

    //From Icon ! Can not stretch
    QPixmap fitpixmapclick = pixmapclick.scaled(ui->pushButtonFromIcon->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPixmap fitpixmapnormal = pixmapnormal.scaled(ui->pushButtonFromIcon->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QIcon icon;
    icon.addPixmap(fitpixmapnormal, QIcon::Normal);
    icon.addPixmap(fitpixmapclick, QIcon::Active);
    ui->pushButtonFromIcon->setCheckable(true);
    ui->pushButtonFromIcon->setIcon(icon);
    ui->pushButtonFromIcon->setIconSize(ui->pushButtonFromIcon->size());
    ui->pushButtonFromIcon->setFlat(true);

    //From QPalette !
    ui->pushButtonFromQPalette->setAutoFillBackground(true);
    ui->pushButtonFromQPalette->setFlat(true);
    QPalette palette;
    palette.setBrush(ui->pushButtonFromQPalette->backgroundRole(),QBrush(pixmapnormal));
    ui->pushButtonFromQPalette->setMask(pixmapnormal.mask());
    ui->pushButtonFromQPalette->setPalette(palette);

/*
    QPushButton{
      border-image: url(:/image/主菜单-normal.png);
    }
    QPushButton:hover,QPushButton:checked{
      border-image: url(:/image/主菜单-click.png);
    }
*/


}

ButtonImageDialog::~ButtonImageDialog()
{
    delete ui;
}
