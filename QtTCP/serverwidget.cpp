#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QString>

ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    tcpServer = new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any, 8888);

    setWindowTitle("服务器：端口8888");

    connect(tcpServer, &QTcpServer::newConnection,
            [=]()
    {
       tcpSocket = tcpServer->nextPendingConnection();
       QString IP = tcpSocket->peerAddress().toString();
       quint16 port = tcpSocket->peerPort();
       QString temp = QString("[%1;%2]：成功连接").arg(port);

       ui->textRead->setText(temp);
    });

       connect(tcpSocket,&QTcpSocket::readyRead,
               [=]()
       {
           QByteArray array = tcpSocket->readAll();
           ui->textRead->append(array);

       });



}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_pushButton_clicked()
{
    if(nullptr == tcpSocket)
    {
        return;
    }
    QString str = ui->textWrite->toPlainText();
    tcpSocket->write( str.toUtf8().data());
}

void ServerWidget::on_pushButton_2_clicked()
{
    if(nullptr == tcpSocket)
    {
        return;
    }
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
