#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QWidget>
#include <QListView>

class ListView : public QListView
{
    Q_OBJECT
public:
    explicit ListView(QWidget *parent = nullptr);

    //void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible) override;


signals:

public slots:
};

#endif // LISTVIEW_H
