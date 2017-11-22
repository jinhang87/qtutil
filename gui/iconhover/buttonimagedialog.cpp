#include "buttonimagedialog.h"
#include "ui_buttonimagedialog.h"

ButtonImageDialog::ButtonImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ButtonImageDialog)
{
    ui->setupUi(this);
    QPixmap pixmapclick(":/image/click.png");
    QPixmap fitpixmapclick = pixmapclick.scaled(ui->pushButton->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPixmap pixmapnormal(":/image/normal.png");
    QPixmap fitpixmapnormal = pixmapnormal.scaled(ui->pushButton->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QIcon icon;
    icon.addPixmap(fitpixmapnormal, QIcon::Normal);
    icon.addPixmap(fitpixmapclick, QIcon::Selected);
    ui->pushButton->setIcon(icon);
    ui->pushButton->setIconSize(ui->pushButton->size());
    ui->pushButton->setFlat(true);


}

ButtonImageDialog::~ButtonImageDialog()
{
    delete ui;
}
