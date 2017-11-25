#include "buttonimagedialog.h"
#include "ui_buttonimagedialog.h"

ButtonImageDialog::ButtonImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ButtonImageDialog)
{
    ui->setupUi(this);
    QPixmap pixmapclick(":/image/click.png");
    //QPixmap fitpixmapclick = pixmapclick.scaled(ui->pushButton->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPixmap pixmapnormal(":/image/normal.png");
    //QPixmap fitpixmapnormal = pixmapnormal.scaled(ui->pushButton->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);


    //From Icon ! Can not stretch
    QIcon icon;
    icon.addPixmap(pixmapnormal, QIcon::Normal);
    //icon.addPixmap(pixmapclick, QIcon::Active);
    ui->pushButtonFromIcon->setCheckable(true);
    ui->pushButtonFromIcon->setIcon(icon);
    ui->pushButtonFromIcon->setIconSize(ui->pushButtonFromIcon->size());
    ui->pushButtonFromIcon->setFlat(true);

    //From QPalette !
    ui->pushButtonFromQPalette->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Button,QBrush(pixmapnormal));
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
