#include "subwidget.h"

subwidget::subwidget(QWidget *parent) : QWidget(parent)
{

    setWindowTitle("小弟");
    b.setParent(this);
    b.setText("切换到主窗口");

    connect(&b, &QPushButton::clicked, this, &subwidget::sendSolt);

    resize(400,300);

}


void subwidget ::sendSolt()
{

    emit mySignal();
    emit mySignal(250,"我是子窗口");
}
