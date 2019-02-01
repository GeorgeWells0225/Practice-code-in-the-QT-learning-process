#include "mylabel.h"
#include <QMouseEvent>
#include <QtDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);

}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    if(ev->button() == Qt::LeftButton)
    {
        qDebug() << "left";

    }else if (ev->button() == Qt::RightButton) {
         qDebug() << "right";

}else if (ev->button() == Qt::MidButton) {
         qDebug() << "middle";

}

    QString text = QString("<center><h1>Mouse Press: (%1, %2)</h1></center>")
            .arg(i).arg(j);
    this->setText(text);

}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Release: (%1, %2)</h1></center>")
            .arg(ev->x()).arg(ev->y());
    this->setText(text);

}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Move: (%1, %2)</h1></center>")
            .arg(ev->x()).arg(ev->y());
    this->setText(text);
}

void MyLabel::enterEvent(QEvent *e)
{
    QString text = QString("<center><h1>Mouse enter</h1></center>");

    this->setText(text);
}

void MyLabel::leaveEvent(QEvent *e)
{
    QString text = QString("<center><h1>Mouse leave</h1></center>");

    this->setText(text);
}
