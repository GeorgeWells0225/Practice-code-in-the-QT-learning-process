#include "mainwidget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget subWin;//执行MainWidget的构造函数
    subWin.show();

    return a.exec();

}
