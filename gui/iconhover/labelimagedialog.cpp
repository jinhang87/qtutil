#include "labelimagedialog.h"
#include "ui_labelimagedialog.h"

LabelImageDialog::LabelImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LabelImageDialog)
{
    ui->setupUi(this);

    QPixmap pixmapclick(":/image/click.png");
    QPixmap fitpixmapclick = pixmapclick.scaled(ui->labelImage->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPixmap pixmapnormal(":/image/normal.png");
    QPixmap fitpixmapnormal =pixmapnormal.scaled(ui->labelImage->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    ui->labelImage->setPixmap(fitpixmapclick);

}

LabelImageDialog::~LabelImageDialog()
{
    delete ui;
}
