#include "clienwidget.h"
#include "ui_clienwidget.h"
#include <QHostAddress>

ClienWidget::ClienWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClienWidget)
{
    ui->setupUi(this);

    tcpSocket = nullptr;
    tcpSocket = new QTcpSocket(this);

}

ClienWidget::~ClienWidget()
{
    delete ui;
}

void ClienWidget::on_pushButtonConnect_clicked()
{
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditport->text().toInt();

    tcpSocket->connectToHost(QHostAddress(ip), port);


}
