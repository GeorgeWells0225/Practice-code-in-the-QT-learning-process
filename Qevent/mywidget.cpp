#include "mywidget.h"
#include "ui_mywidget.h"
#include <QtDebug>
#include <QKeyEvent>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    this->startTimer(1000);
    //this->killTimer();
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::KeyPressEvent(QKeyEvent *e)
{
    qDebug() << (char)e->key();
    if(e->key() == Qt::Key_A)
    {
        qDebug()<< "Qt::Key_A";
    }

}

void MyWidget::timerEvent(QTimerEvent *e)
{
    static int sec = 0;
    sec ++;
    ui->label->setText(QString("<center><h1>timer out: %1</h1></center>").arg(sec++));

}
