#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
protected:
    void KeyPressEvent(QKeyEvent *);
    void timerEvent(QTimerEvent *);

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
