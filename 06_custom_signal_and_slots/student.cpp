#include "student.h"

#include <QDebug>

student::student(QObject *parent)
    : QObject{parent}
{

}

void student::treat()
{
    qDebug() << "treat";
}

void student::treat(QString what)
{
    qDebug() << what.toUtf8().data();
}
