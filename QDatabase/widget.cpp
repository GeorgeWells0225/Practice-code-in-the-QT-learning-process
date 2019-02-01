#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("PASSWORD");
    db.setDatabaseName("query_the_database");


    if( !db.open() )
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }

     QSqlQuery query;
    // query.exec("create table 妈的智障(id int primary key auto_increment, name varchar(255), age int, score int);");

     /*QSqlDatabase db1 = QSqlDatabase::addDatabase("QMYSQL", "a");
     db1.setHostName("localhost");
     db1.setUserName("root");
     db1.setPassword("Mysql@25");
     db1.setDatabaseName("query_the_database");

     QSqlQuery query1(db1);
     query1.exec(); */
     query.exec("select * from 妈的智障");
     while (query.next())
     {
         qDebug() << query.value(0).toInt()
                  << query.value(1).toString()
                  << query.value("age").toInt()
                  << query.value("score").toInt();

     }




}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ButtonDel_clicked()
{
    QString name = ui->lineEdit->text();


    QString sql = QString("delete from 妈的智障 where name = '%1'").arg(name);

    QSqlDatabase::database().transaction();

    QSqlQuery query;
    query.exec(sql);





}

void Widget::on_ButtonSure_clicked()
{
    QSqlDatabase::database().commit();
}

void Widget::on_ButtonCancel_clicked()
{
    QSqlDatabase::database().rollback();
}
