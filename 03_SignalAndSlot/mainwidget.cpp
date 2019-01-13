#include "mainwidget.h"
#include <QPushButton>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{


    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("16");


    connect(b2, &QPushButton::released, this, &MainWidget::mySlot);

    connect(b2, &QPushButton::released, &b1, &QPushButton::hide);



    /*  b1信号发出者，指针类型
        &QPushButton::pressed处理信号 &发送者的类名：：信号名字
        this信号接受者
        &MainWidget::close 槽函数，信号处理函数 &接受的类名：：槽函数的名字
    */

    /*自定义嶆
      QT5任意的成员函数，普通全局函数，静态函数
      槽函数需要和信号一致（参数，返回值）
      由于信号都是没有返回值，所以，槽函数也一定没有返回值
    */

    connect(b2, &QPushButton::released, this, &MainWidget::mySlot);
}

void MainWidget::mySlot()
{
    b2->setText("123");
}


MainWidget::~MainWidget()
{

}
