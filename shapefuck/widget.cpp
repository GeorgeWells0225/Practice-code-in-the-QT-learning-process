#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

   // setWindowFlags(Qt::Dialog);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap("../image/2233.jpg"));
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
    {
        close();
    }else if (e->button() == Qt::LeftButton) {
        p = e->globalPos() - this ->frameGeometry().topLeft();

}
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        move(e->globalPos() - p);
    }
}
