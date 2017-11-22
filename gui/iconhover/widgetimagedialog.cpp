#include "widgetimagedialog.h"
#include "ui_widgetimagedialog.h"

WidgetImageDialog::WidgetImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WidgetImageDialog)
{
    ui->setupUi(this);

    QPixmap pixmapclick(":/image/click.png");
    QPixmap fitpixmapclick = pixmapclick.scaled(ui->widgetImage->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPixmap pixmapnormal(":/image/normal.png");
    QPixmap fitpixmapnormal = pixmapnormal.scaled(ui->widgetImage->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(fitpixmapclick));

    ui->widgetImage->setAutoFillBackground(true);
    ui->widgetImage->setPalette(palette);

    ui->pushButton->setStyleSheet("QPushButton{background: transparent;}");

}

WidgetImageDialog::~WidgetImageDialog()
{
    delete ui;
}

void WidgetImageDialog::on_pushButtonChange_clicked()
{
    onWidgetImageChange();
}

void WidgetImageDialog::onWidgetImageChange()
{
    static int loop = 0;
    QPixmap pixmapclick(":/image/click.png");
    QPixmap fitpixmapclick = pixmapclick.scaled(ui->widgetImage->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPixmap pixmapnormal(":/image/normal.png");
    QPixmap fitpixmapnormal = pixmapnormal.scaled(ui->widgetImage->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    if(loop++%2 == 0){
        palette.setBrush(QPalette::Background, QBrush(fitpixmapclick));
        ui->widgetImage->setPalette(palette);
        ui->pushButton->setStyleSheet("QPushButton{background: #dddddd; color: #0f62de;}");
        ui->label->setStyleSheet("QLabel{background: transparent; color: #dddddd;}");
    }else{
        palette.setBrush(QPalette::Background, QBrush(fitpixmapnormal));
        ui->widgetImage->setPalette(palette);
        ui->pushButton->setStyleSheet("QPushButton{background: #0f62de; color: #dddddd;}");
        ui->label->setStyleSheet("QLabel{background: transparent; color: #646464;}");
    }
}
