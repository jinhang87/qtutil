#ifndef PAGERWIDGET_H
#define PAGERWIDGET_H

#include <QWidget>

namespace Ui {
class PagerWidget;
}

class PagerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PagerWidget(QWidget *parent = 0);
    ~PagerWidget();

    int currentPage() const;
    void setCurrentPage(int currentPage);

    int totalPage() const;
    void setTotalPage(int totalPage);

signals:
    void currentPageChanged(int currentPage);

private slots:
    void on_beginning_clicked();
    void on_previous_clicked();
    void on_next_clicked();
    void on_last_clicked();

private:
    void setupUi();
    Ui::PagerWidget *ui;
    int m_currentPage;
    int m_totalPage;
};

#endif // PAGERWIDGET_H
