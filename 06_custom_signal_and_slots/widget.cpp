#include "widget.h"

#include "QPushButton"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pTeacher1 = new Teacher(this);
    pStudent1 = new student(this);

//    connect(pTeacher1, &Teacher::hungry, pStudent1, &student::treat);
    // 函数发生重载，需要指定重载函数地址
//    connect(pTeacher1,
//            static_cast<void (Teacher::*)(QString)>(&Teacher::hungry),
//            pStudent1,
//            static_cast<void (student::*)(QString)>(&student::treat));
    connect(pTeacher1,
            static_cast<void (Teacher::*)()>(&Teacher::hungry),
            pStudent1,
            static_cast<void (student::*)()>(&student::treat));
    void (Teacher::*teacher_qstr)(QString) = &Teacher::hungry;
    void (student::*student_qstr)(QString) = &student::treat;
    connect(pTeacher1, teacher_qstr, pStudent1, student_qstr);

    this->classisOver();

    QPushButton* pBnt = new QPushButton("按钮", this);
// 由于没有传参所以这里编译不过
//    connect(pBnt, &QPushButton::clicked, teacher_qstr, &Teacher::hungry);
    int a = 9;
    int b = 10;
    connect(pBnt,
            &QPushButton::clicked,
            pTeacher1,
            static_cast<void (Teacher::*)()>(&Teacher::hungry));
    connect(pBnt, &QPushButton::clicked, [=]() {
        qDebug() << a * b << Qt::endl;
        static bool cnt;
        if(cnt) {
            cnt = !cnt;
            this->resize(400, 300);
        } else {
            cnt = !cnt;
            this->resize(800, 600);
        }

    });
}

void Widget::classisOver()
{
    // 触发老师饿了的信号
    emit pTeacher1->hungry("黄焖鸡");
}

Widget::~Widget()
{
}

