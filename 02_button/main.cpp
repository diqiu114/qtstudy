#include "mainwindow.h"

#include <QApplication>

#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // 添加按钮
    QPushButton Btn;
    Btn.setText("按钮1");
    /*建立父子关系，默认情况下没有建立父子关系，直接show的话
     * 都是顶层窗口
    */
    // 方式1
    Btn.setParent(&w);
    Btn.show();
    // 方式2 构造函数传参
    QPushButton bnt2("按钮2", &w);
    // 移动一下按钮位置
    bnt2.move(100, 100);
    bnt2.show();

    QPushButton Bnt3("按钮3父子", &Btn);
    Bnt3.show();

    w.show();
    return a.exec();
}


