#include "mypushbutton.h"

// 构造函数
MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton(parent)
{

}


// 构析函数
MyPushButton::~MyPushButton()
{
    qDebug() << "my push button destroyd";
}
