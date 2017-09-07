#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <QObject>

class PasswordValidator : public QObject
{
    Q_OBJECT
public:
    enum Level { InValid, Low, Medium, High};
    Q_ENUM(Level)
    explicit PasswordValidator(const QString &strings, QObject *parent = 0);
    bool containLowerCharacter();
    bool containHigherCharacter();
    bool containNumber();
    bool containSpecial();
    Level level();

signals:

public slots:

private:
    QString m_password;
    bool m_bContainLower;
    bool m_bContainHigher;
    bool m_bContainNumber;
    bool m_bContainSpecial;
};

#endif // PASSWORDVALIDATOR_H
