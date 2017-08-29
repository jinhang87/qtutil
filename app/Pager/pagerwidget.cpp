#include "pagerwidget.h"
#include "ui_pagerwidget.h"

PagerWidget::PagerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PagerWidget)
{
    ui->setupUi(this);
    setupUi();
}

PagerWidget::~PagerWidget()
{
    delete ui;
}

int PagerWidget::currentPage() const
{
    return m_currentPage;
}

void PagerWidget::setCurrentPage(int currentPage)
{
    m_currentPage = currentPage;
    setupUi();
    currentPageChanged(m_currentPage);
}

int PagerWidget::totalPage() const
{
    return m_totalPage;
}

void PagerWidget::setTotalPage(int totalPage)
{
    m_totalPage = totalPage;
    setupUi();
}

void PagerWidget::setupUi()
{
    ui->label->setText(QString("%1/%2").arg(m_currentPage).arg(m_totalPage));
}

void PagerWidget::on_beginning_clicked()
{
    m_currentPage = 0;
    currentPageChanged(m_currentPage);
    setupUi();
}

void PagerWidget::on_previous_clicked()
{
    if(m_currentPage > 0){
        m_currentPage--;
        currentPageChanged(m_currentPage);
        setupUi();
    }
}

void PagerWidget::on_next_clicked()
{
    if(m_currentPage < m_totalPage){
        m_currentPage++;
        currentPageChanged(m_currentPage);
        setupUi();
    }

}

void PagerWidget::on_last_clicked()
{
    m_currentPage = m_totalPage;
    currentPageChanged(m_currentPage);
    setupUi();
}
