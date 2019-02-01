#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void mySlot();
    void changeWin();
    void dealSub();
    void dealSlot(int, QString);

private:

    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;

    subwidget subWin;
};
#endif // MAINWIDGET_H
