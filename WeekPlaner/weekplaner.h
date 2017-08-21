#ifndef WEEKPLANER_H
#define WEEKPLANER_H

#include <QWidget>
#include <QSharedPointer>
#include <QStackedWidget>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QStateMachine>

class WeekPlanEditablePanel;
class WeekPlanCopyablePanel;
class WeekPlaner : public QWidget
{
    Q_OBJECT
public:
    explicit WeekPlaner(QWidget *parent = 0);

    QPushButton *copytopushbutton() const;
    void setCopytopushbutton(QPushButton *copytopushbutton);
    QPushButton *newpushbutton() const;
    void setNewpushbutton(QPushButton *newpushbutton);
    QPushButton *deletepushbutton() const;
    void setDeletepushbutton(QPushButton *deletepushbutton);
    QDialogButtonBox *buttonBox() const;
    void setButtonBox(QDialogButtonBox *buttonBox);

protected:

    virtual QSize sizeHint() const;

signals:

public slots:
    void on_deletepushbutton_clicked();

private:
    void machineReset();

private:
    QStackedWidget *m_stackedWidget = nullptr;
    QSharedPointer<WeekPlanEditablePanel> m_editWidget;
    QSharedPointer<WeekPlanCopyablePanel> m_copyWidget;
    QPushButton* m_copytopushbutton = nullptr;
    QPushButton* m_newpushbutton = nullptr;
    QPushButton* m_deletepushbutton = nullptr;
    QDialogButtonBox* m_buttonBox = nullptr;
    QSharedPointer<QStateMachine> m_machine;
};

#endif // WEEKPLANER_H
