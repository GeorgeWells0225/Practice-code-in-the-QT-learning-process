#include <QApplication>
#include <QWidget> //窗口控制基类
#include <QPushButton>
int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    w.setWindowTitle("主要看气质");


    QPushButton b;
    b.setText(">_<");
    b.setParent(&w);//需要指定父对象，将子窗口安排到父窗口中a为b的父对象则b在a的里面（1）setParent（2）构造函数传参，且仅需要一个show
    b.move(100,100);



    QPushButton b1(&w);
    b1.setText("妈的智障");
    b1.move(200,200);

    w.show();




    app.exec();
    return 0;
}
