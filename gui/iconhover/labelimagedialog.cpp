#include "labelimagedialog.h"
#include "ui_labelimagedialog.h"

LabelImageDialog::LabelImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LabelImageDialog)
{
    ui->setupUi(this);

    QPixmap pixmapclick(":/image/click.png");
    QPixmap pixmapnormal(":/image/normal.png");

    QPixmap fitpixmapclick = pixmapclick.scaled(ui->labelFromPixmap->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPixmap fitpixmapnormal =pixmapnormal.scaled(ui->labelFromPixmap->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->labelFromPixmap->setPixmap(fitpixmapclick);


    ui->labelFromPixmapContent->setPixmap(pixmapnormal);
    ui->labelFromPixmapContent->setScaledContents(true);

}

LabelImageDialog::~LabelImageDialog()
{
    delete ui;
}
