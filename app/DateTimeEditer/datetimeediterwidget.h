#ifndef DATETIMEEDITERWIDGET_H
#define DATETIMEEDITERWIDGET_H

#include <QWidget>
#include <QSharedPointer>
#include <QLabel>

namespace Ui {
class DateTimeEditerWidget;
}
class DateTimeEditerModel;
class DateTimeEditerWidget : public QWidget
{
    Q_OBJECT

public:
    const int LAEBL_PER_LINE = 9;
    explicit DateTimeEditerWidget(QWidget *parent = 0);
    ~DateTimeEditerWidget();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    void setupUi();
    Ui::DateTimeEditerWidget *ui;
    QSharedPointer<DateTimeEditerModel> m_model;
    QHash<QLabel*, QModelIndex> m_hashWatchedLabels;
};

#endif // DATETIMEEDITERWIDGET_H
