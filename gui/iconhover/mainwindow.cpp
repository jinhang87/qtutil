#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menubutton.h"
#include "buttonimagedialog.h"
#include "labelimagedialog.h"
#include "widgetimagedialog.h"
#include "lineeditdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MenuButton *button = new MenuButton(this);
    //button->resize(200,200);
    //button->move(100,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonImage_clicked()
{
    this->hide();
    ButtonImageDialog d;
    d.setModal(true);
    d.show();
    d.exec();
    this->show();
}

void MainWindow::on_pushButtonLabelImage_clicked()
{
    this->hide();
    LabelImageDialog d;
    d.setModal(true);
    d.show();
    d.exec();
    this->show();
}

void MainWindow::on_pushButtonWidgetImage_clicked()
{
    this->hide();
    WidgetImageDialog d;
    d.setModal(true);
    d.show();
    d.exec();
    this->show();
}

void MainWindow::on_pushButtonLineEdit_clicked()
{
    this->hide();
    LineEditDialog d;
    d.setModal(true);
    d.show();
    d.exec();
    this->show();
}

void MainWindow::on_pushButton_clicked()
{

}
