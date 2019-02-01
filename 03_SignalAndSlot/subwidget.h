#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>


class subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit subwidget(QWidget *parent = nullptr);

    void sendSolt();

signals:
    //信号没有返回值，但可以有参数，信号就是函数的声明，仅需声明，无需定义,可以重载

    void mySignal();
    void mySignal(int, QString);

public slots:

private:

    QPushButton b;

};


#endif // SUBWIDGET_H
