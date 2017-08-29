#include "mainwindow.h"
#include <QApplication>


#include <QTreeView>
#include <QListView>
#include <QFileSystemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QFileSystemModel model;
    model.setRootPath(QDir::currentPath());

    QTreeView tree;
    tree.setModel(&model);
    tree.setRootIndex(model.index(QDir::currentPath()));

    QListView list;
    list.setModel(&model);
    list.setRootIndex(model.index(QDir::currentPath()));

    tree.show();
    list.show();

    return a.exec();
}
