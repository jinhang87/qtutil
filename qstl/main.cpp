#include <QCoreApplication>
#include <QDebug>
#include <QListIterator>

void test()
{
    QList<QString> list;
    list << "one" << "two" << "three";

    //只读遍历
    for (int i = 0; i < list.size(); ++i) {
        if (list.at(i) == "two")
            qDebug() << "Found two at position " << i << endl;
    }

    //迭代器遍历（正向遍历）
    QListIterator<QString> it(list);
    while (it.hasNext()) {
        qDebug() << it.next();
    }

    //迭代器遍历（逆向遍历）
    it.toBack();
    while (it.hasPrevious())
        qDebug() << it.previous();

    //c++11 for关键字遍历
    for(auto string : list){
        qDebug() << string;
    }
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
