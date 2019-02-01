#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                "open", "../", "TXT(*.txt)");

    QFile file(path);

    bool isOk = file.open(QIODevice::ReadOnly);
    if(isOk == true)
    {

#if 0
        QByteArray array = file.readAll();

        //ui->textEdit->setText(QString(array));

        ui->textEdit->setText(array);

#endif

        QByteArray array;
        while ( file.atEnd() == false) {
            array += file.readLine();

        }

        ui->textEdit->setText(array);
    }

    file.close();

    QFileInfo info(path);
    qDebug() <<"文件名字：" << info.fileName().toUtf8().data();
    qDebug() <<"文件后缀：" << info.suffix();
    qDebug() <<"文件大小：" << info.size();
    qDebug() <<"文件创建时间：" << info.birthTime().toString("yyyy-MM-dd");

}

void Widget::on_pushButton_2_clicked()
{
   QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.txt)");
   if(path.isEmpty() == false)
   {
       QFile file;
       file.setFileName(path);
       bool isOk = file.open(QIODevice::WriteOnly);

       if(isOk == true)
       {
           QString str = ui->textEdit->toPlainText();

           //file.write(str.toUtf8());
           file.write(str.toStdString().data());

       }

       file.close();
   }
}
