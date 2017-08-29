#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "listitemdelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    model = QSharedPointer<QStringListModel>(new QStringListModel());
    delegate = QSharedPointer<ListItemDelegate>(new ListItemDelegate());


    QStringList list;
    //list << "one" << "two" << "three" << "four"
    list << "1" << "2" << "3" << "4"
         << "5" << "6" << "7" << "8"
         << "9" << "10" << "11" << "12"
         << "13" << "14" << "15" << "16"
         << "17" << "18" << "19" << "20";
    model->setStringList(list);
    ui->listView->setModel(model.data());
    //ui->listView->setItemDelegate(delegate.data());
    //ui->listView->setSpacing(3);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listView->setUniformItemSizes(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int displayrowcounts = getDisplayRowsCounts();
    qDebug() << "on_pushButton_clicked" << ui->listView->currentIndex() << displayrowcounts;
    QModelIndex index = ui->listView->currentIndex();
    int newrow = ((index.row()+1)<displayrowcounts) ? displayrowcounts: (index.row()+1);
    QModelIndex newIndex = model->index(newrow,0);
    if(newIndex.isValid()){
        ui->listView->scrollTo(newIndex,QAbstractItemView::PositionAtBottom);
        ui->listView->setCurrentIndex(newIndex);
    }else{
        //ui->pushButton_2->setEnabled(true);
        //ui->pushButton->setEnabled(false);
    }
    QSize areaSize = ui->listView->viewport()->size();
    QRect rect = ui->listView->visualRect(newIndex);
    qDebug() << areaSize << rect;
    //QWidgetList l = ui->listView->scrollBarWidgets();
    //qDebug() << l.size();

    QSize size = ui->listView->gridSize();
    qDebug() << size;
}

void MainWindow::on_pushButton_2_clicked()
{
    int displayrowcounts = getDisplayRowsCounts();
    qDebug() << "on_pushButton_2_clicked" << ui->listView->currentIndex() << displayrowcounts;
    QModelIndex index = ui->listView->currentIndex();
    int size = model->stringList().size();
    int newrow = ((size-index.row()+1)<displayrowcounts) ? size-displayrowcounts-1: (index.row()-1);
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

int MainWindow::getDisplayRowsCounts()
{
    QModelIndex newIndex = model->index(0,0);
    QSize areaSize = ui->listView->viewport()->size();
    QRect rect = ui->listView->visualRect(newIndex);
    qDebug() << areaSize << rect;
    if(newIndex.isValid())
        return areaSize.height()/rect.height();
    else
        return 0;
}
