#include "mylabel.h"
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent}
{

}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int x = ev->position().x();
    int y = ev->position().y();

    // 获取按键
    Qt::MouseButton btn = ev->button();
    QString strButton = "";
    if(btn==Qt::RightButton) {
        strButton = "RightButton";
    } else if(btn==Qt::LeftButton) {
        strButton = "LeftButton";
    } else if(btn==Qt::MiddleButton) {
        strButton = "MiddleButton";
    }



    // lable是可以显示html
    QString str = QString("<h1><center>[%1, %2][%3]</center></h1>")
            .arg(x).arg(y).arg(strButton);

    this->setText(str);


}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    int x = ev->position().x();
    int y = ev->position().y();

    // 获取按键
    Qt::MouseButtons btns = ev->buttons();
    QString strButton = "";
    if(btns&Qt::RightButton) {
        strButton += "RightButton";
    }
    if(btns&Qt::LeftButton) {
        strButton += "LeftButton";
    }
    if(btns&Qt::MiddleButton) {
        strButton += "MiddleButton";
    }



    // lable是可以显示html
    QString str = QString("<h1><center>[%1, %2][%3]</center></h1>")
            .arg(x).arg(y).arg(strButton);

    this->setText(str);
}

bool MyLabel::event(QEvent *e)
{
    // 返回值：ture表示该事件得到处理，如果时false，没被处理，事件会继续传递到父窗口
    // QEvent就是所有Event类的父类
    // 判断event的类型
    // 这里是拦截，一般不推荐拦截，因为有对应的函数去处理对应事件，    这里只是做了示范
    if(e->type()==QEvent::MouseMove) {
        this->mouseMoveEvent(static_cast<QMouseEvent*>(e));
        return true;
    }
    return QLabel::event(e);
}
