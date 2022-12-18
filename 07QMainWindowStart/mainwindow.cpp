#include "mainwindow.h"
#include "QMenuBar"
#include "QToolBar"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800, 600);
    // 菜单栏,获取当前窗口的菜单栏，没有会自动创建一个
    QMenuBar *mb  = this->menuBar();
    // 添加菜单
    QMenu *menuFile = mb->addMenu("文件");
    QMenu *menuEdit = mb->addMenu("编辑");
    // 菜单里添加选项
    menuFile->addAction("新建");
    menuFile->addAction("打开");
    // 添加分割符号
    menuFile->addSeparator();
    // 添加二级菜单
    QMenu *menuRecent = menuFile->addMenu("最近打开的文件");
    menuRecent->addAction("1.text");

    // 工具栏，可以有多个
    QToolBar *toolBar = this->addToolBar("");
    QAction *actionNew = menuRecent->addAction("新建");
    QAction *actionOpen = menuRecent->addAction("打开");
    // 添加工具
    toolBar->addAction(actionNew);
    toolBar->addAction(actionOpen);

    // 默认停靠在左边
    this->addToolBar(Qt::LeftToolBarArea, toolBar);

    //只允许停靠在左边或者右边
    toolBar->setAllowedAreas(Qt::LeftToolBarArea |
                             Qt::RightToolBarArea |
                             Qt::TopToolBarArea);
    // 设置状态栏不可以浮动
    toolBar->setFloatable(false);
    // 设置状态栏不允许拖动
    toolBar->setMovable(false);

    // 状态栏，只有一个
    // 获取窗口的状态栏
    QStatusBar *Sb = this->statusBar();


}

MainWindow::~MainWindow()
{
}

