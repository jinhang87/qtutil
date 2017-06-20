#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTranslator>
#include <QDebug>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_tras = new QTranslator(this);
    connect(ui->changelang, &QPushButton::clicked, this, [this](){
        static int i = 0;
        if(i++%2 == 0)
            this->changeTranslator("i18n_zh_cn.qm");
        else
            this->changeTranslator("");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange){
        this->ui->retranslateUi(this);
        qDebug() << "retranslateUi";
    }
}

void MainWindow::changeTranslator(const QString &file)
{
    //加载语言包
    if(m_tras->load(file)){
        //安装翻译器
        qApp->installTranslator(m_tras);
        qDebug() << "install ok!";
    }else{
        qDebug() << "install not ok!";
    }

}
