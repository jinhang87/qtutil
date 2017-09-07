#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //限制100~999
    //100以下可以输入，999以上无法输入
//    {
//        QValidator *validator = new QIntValidator(100,999,this);
//        ui->lineEdit->setValidator(validator);
//    }

    //正则表达式，第一位数字为a-z的数字，第二位为1-9的数字，后边是0-2位0-9的数字
    //符合要求
//    {
//        QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
//        ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
//    }

    //匹配特殊字符
    //  "\" --->  四个反斜杠表示，因为本身字符串就需要转移，正则仍需转移
    {
        QString regString("[^\\\\,/.* ]{8,16}");
        QRegExp regExp(regString);
        ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
    }

    //不能输入a-z
//    {
//        QString regString("[^a-z]+");
//        QRegExp regExp(regString);
//        ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
