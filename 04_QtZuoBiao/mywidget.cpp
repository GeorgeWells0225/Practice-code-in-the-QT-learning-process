#include "mywidget.h"
#include <QPushButton>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //主窗口的移动，坐标系统相对于屏幕，左上角为原点y往下递增
    move(0,0);
    QPushButton *b1 = new QPushButton(this);
    b1->move(0,1); //子窗口相对于父窗口
    b1->setText("^_^");
    b1->resize(100,100);

    QPushButton *b2 =new QPushButton(b1);
    b2->move(10,10);
    b2->setText(">_<");
    b2->resize(50,50);


}

MyWidget::~MyWidget()
{

}
