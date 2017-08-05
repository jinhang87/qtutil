#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    model = QSharedPointer<QStringListModel>(new QStringListModel());
    QStringList list;
    //list << "one" << "two" << "three" << "four"
    list << "1" << "2" << "3" << "4"
         << "5" << "6" << "7" << "8"
         << "9" << "10" << "11" << "12";
    model->setStringList(list);
    ui->listView->setModel(model.data());
    ui->listView->setSpacing(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "on_pushButton_clicked" << ui->listView->currentIndex();
    QModelIndex index = ui->listView->currentIndex();
    int newrow = ((index.row()+1)<8) ? 8: (index.row()+1);
    QModelIndex newIndex = model->index(newrow,0);
    if(newIndex.isValid()){
        ui->listView->scrollTo(newIndex,QAbstractItemView::PositionAtBottom);
        ui->listView->setCurrentIndex(newIndex);
    }else{
        //ui->pushButton_2->setEnabled(true);
        //ui->pushButton->setEnabled(false);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "on_pushButton_2_clicked" << ui->listView->currentIndex();
    QModelIndex index = ui->listView->currentIndex();
    int size = model->stringList().size();
    int newrow = ((size-index.row()+1)<8) ? size-8-1: (index.row()-1);
    QModelIndex newIndex = model->index(newrow,0);
    if(newIndex.isValid()){
        ui->listView->scrollTo(newIndex,QAbstractItemView::PositionAtTop);
        ui->listView->setCurrentIndex(newIndex);
    }else{
        //ui->pushButton_2->setEnabled(false);
        //ui->pushButton->setEnabled(true);
    }
}

void MainWindow::on_listView_indexesMoved(const QModelIndexList &indexes)
{
    qDebug() << "on_listView_indexesMoved" << indexes;
}

void MainWindow::on_listView_pressed(const QModelIndex &index)
{
    qDebug() << "on_listView_pressed" << index;
}



void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    qDebug() << "on_listView_clicked" << index;
}
