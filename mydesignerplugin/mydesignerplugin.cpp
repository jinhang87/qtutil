#include "mydesignerplugin.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include "dialog.h"

MyDesignerPlugin::MyDesignerPlugin(QWidget *parent) :
    QWidget(parent)
{
#if 1
    QPushButton *button1 = new QPushButton(this);
    QPushButton *button2 = new QPushButton(this);
    button1->setText("hello");
    button2->setText("Qt!");
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    setLayout(layout);
#else
     Dialog *d = new Dialog(parent);
     qDebug() << "dialog";
     d->resize(800,450);
     d->show();
#endif

}
