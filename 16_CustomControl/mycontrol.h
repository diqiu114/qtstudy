#ifndef MYCONTROL_H
#define MYCONTROL_H

#include <QWidget>

namespace Ui {
class MyControl;
}

class MyControl : public QWidget
{
    Q_OBJECT

public:
    explicit MyControl(QWidget *parent = nullptr);
    ~MyControl();
    // 定义外部的使用接口
    // 设置值、获取值
    void setValue(int val);
    int value();
private:
    Ui::MyControl *ui;
};

#endif // MYCONTROL_H
