#include "passwordvalidator.h"
#include <QDebug>

PasswordValidator::PasswordValidator(const QString &strings, QObject *parent) : QObject(parent), m_password(strings)
{
    m_bContainLower = containLowerCharacter();
    m_bContainHigher = containHigherCharacter();
    m_bContainNumber = containNumber();
    m_bContainSpecial = containSpecial();
}

bool PasswordValidator::containLowerCharacter()
{
    QString pattern("[a-z]+");
    QRegExp rx(pattern);

    int pos = m_password.indexOf(rx);
    qDebug() << "containLowerCharacter" <<pos;
    if ( pos >= 0 ){
        return true;
    }
    return false;
}

bool PasswordValidator::containHigherCharacter()
{
    QString pattern("[A-Z]+");
    QRegExp rx(pattern);

    int pos = m_password.indexOf(rx);
    qDebug() << "containHigherCharacter" << pos;
    if ( pos >= 0 ){
        return true;
    }
    return false;
}

bool PasswordValidator::containNumber()
{
    QString pattern("[0-9]+");
    QRegExp rx(pattern);

    int pos = m_password.indexOf(rx);
    qDebug() << "containNumber" << pos;
    if ( pos >= 0 ){
        return true;
    }
    return false;
}

bool PasswordValidator::containSpecial()
{
    QString pattern("[^A-Za-z0-9]+");
    QRegExp rx(pattern);

    int pos = m_password.indexOf(rx);
    qDebug() << "containSpecial" << pos;
    if ( pos >= 0 ){
        return true;
    }
    return false;
}

PasswordValidator::Level PasswordValidator::level()
{
    PasswordValidator::Level lv = PasswordValidator::InValid;
    int count = 0;
    count = (m_bContainLower)? count+1 : count;
    count = (m_bContainHigher)? count+1 : count;
    count = (m_bContainNumber)? count+1 : count;
    count = (m_bContainSpecial)? count+1 : count;

    if(count >= 3){
        lv = PasswordValidator::High;
    }else if(count == 2){
        if( (m_bContainLower && m_bContainNumber)
            ||(m_bContainHigher && m_bContainNumber)){
            lv = PasswordValidator::Low;
        }else{
            lv = PasswordValidator::Medium;
        }
    }else{
        lv = PasswordValidator::InValid;
    }

    return lv;
}

