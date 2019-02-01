#include "mainwidget.h"
#include <QPushButton>
#include <QDebug>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{


    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("隐藏");


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




    setWindowTitle("老大");
    //this->setWindowsTitle("老大");//与上面等价
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50,50);

    //显示子窗口
    //subWin.show();
    connect(&b3, &QPushButton::released, this, &MainWidget::changeWin);

    void (subwidget::*funSignal)() = &subwidget::mySignal;
    connect(&subWin, funSignal, this, &MainWidget::dealSub);
    void (subwidget::*testsignal)(int,QString) = &subwidget::mySignal;
    connect(&subWin, testsignal, this, &MainWidget::dealSlot);
    QPushButton *b4 = new QPushButton(this);
    b4->setText("Lambda表达式");
    b4->move(150,150);
    int a = 10,b = 100;

    connect(b4, &QPushButton::released,
            //= :把外部全部变量传进来
            [=](){

                     b4->setText("123");
                     qDebug() << "11111";
                     qDebug() << a << b;


                });

    resize(400,300);


}


void MainWidget::dealSlot(int a,QString str)
{

     qDebug()<< a <<str.toUtf8().data();

}

void MainWidget::mySlot()
{

    b2->setText("123");

}

void MainWidget::changeWin()
{
    //子窗口显示
    subWin.show();
    //本窗口隐藏
    this->hide();
}

void MainWidget::dealSub()
{


    subWin.hide();
    show();


}
MainWidget::~MainWidget()
{

}
