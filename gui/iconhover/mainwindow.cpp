#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menubutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MenuButton *button = new MenuButton(this);
    button->resize(200,200);
    button->move(100,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
