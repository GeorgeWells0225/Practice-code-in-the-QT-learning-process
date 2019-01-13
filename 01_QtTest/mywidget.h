#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT //信号与槽时需要

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
};

#endif // MYWIDGET_H
