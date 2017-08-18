#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProgressDialog>
#include <QDebug>

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

void MainWindow::on_pushButton_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"), tr("取消"), 0, 50000, this);
   // dialog.setWindowTitle(tr("进度对话框"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    for(int i = 0; i < 50000; i++)//已知最大值不超过50000
    {
        dialog.setValue(i);
        QCoreApplication::processEvents();
        if(dialog.wasCanceled())
            break;
    }
    dialog.setValue(50000);
    //qDebug()<<tr("复制结束！");
}

void MainWindow::on_pushButton_2_clicked()
{
    QProgressDialog* process = new QProgressDialog(this);
    process->setLabelText("test....");
    process->setRange(0,1000);
    process->setCancelButtonText(tr("取消"));
    process->setModal(true);
    process->setStyleSheet("QProgressBar{border:1px solid #FFFFFF;"
                           "height:30;"
                           "background:red;"
                           "text-align:center;"
                           "color:rgb(255,255,0);"
                           "border-radius:10px;}"
                           "QProgressBar::chunk{"
                           "border-radius:3px;"    // 斑马线圆角
                           "border:0.5px "
                           "solid green;" // 黑边，默认无边
                           "background-color:blue;}");
    connect(process, SIGNAL(canceled()), this, SLOT(onProcessCanceled()));
    process->show();
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<2000000;j++);
        process->setValue(i);
        process->setLabelText(QString::number(process->value()*100/process->maximum()));
        QCoreApplication::processEvents();
        if(process->wasCanceled())//检测是否取消
        {
            //delete process;
            break;

        }
    }
    //delete process;
}

void MainWindow::onProcessCanceled()
{
    qDebug() << "Cancel !";
}
