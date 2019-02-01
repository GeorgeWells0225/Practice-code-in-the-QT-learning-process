#ifndef CLIENWIDGET_H
#define CLIENWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>

namespace Ui {
class ClienWidget;
}

class ClienWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClienWidget(QWidget *parent = nullptr);
    ~ClienWidget();

private slots:
    void on_pushButtonConnect_clicked();

private:
    Ui::ClienWidget *ui;

    QTcpSocket *tcpSocket;

};

#endif // CLIENWIDGET_H
