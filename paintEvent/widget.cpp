#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    x = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    //QPainter p(this);
    QPainter p;
    p.begin(this);

    //p.drawPixmap(0, 0, width(), height(), QPixmap("../image/666.jpg"));

    p.drawPixmap(rect(), QPixmap("../image/555.jpg"));

    QPen pen;
    pen.setWidth(5);
    //pen.setColor(Qt::red);
    pen.setStyle(Qt::DashLine);


    p.setPen(pen);

    p.drawLine(50, 50, 150, 50);
    p.drawLine(50, 50, 50, 150);

    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::Dense1Pattern);

    p.setBrush(brush);

    p.drawRect(150, 150, 100, 50);

    p.drawEllipse(QPoint(150, 150), 50, 25);

    p.drawPixmap(x, 100, 80, 80,QPixmap("../image/2233.jpg"));

    p.end();
}

void Widget::on_pushButton_clicked()
{
    x += 20;

    if(x > width() )
    {
        x = 0;
    }

    update();
}
