#include "mywidget.h"
//QAPPlication应用程序类
#include <QApplication>
//QT头文件没有.h

int main(int argc, char *argv[])//int argc, char*argv有且仅有一个应用程序类的对象
{
    QApplication a(argc, argv);
    //MyWidget继承与QWidget,Qwdget是一个窗口基类
    MyWidget w;
    //MyWidget也是窗口
    w.show();
    //默认隐藏需要人为显示

    //让程序一直执行，等待用户操作
    return a.exec();
}
