#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QItemSelection>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("Mysql@25");
    db.setDatabaseName("query_the_database");


    if( !db.open() )
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }


    model = new  QSqlTableModel(this);
    model->setTable("fuck");
    ui->tableView->setModel(model);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "学号");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//数据不允许修改





}

Widget::~Widget()
{
    delete ui;


}

void Widget::on_ButtonAdd_clicked()
{
    QSqlRecord record = model->record();
    int row = model->rowCount();
    model->insertRecord(row, record);

}

void Widget::on_ButtonSure_clicked()
{
    model->submitAll();
}

void Widget::on_ButtonCancel_clicked()
{
    model->revertAll();
    model->submitAll();
}

void Widget::on_ButtonDel_clicked()
{
    QItemSelectionModel *sModel = ui->tableView->selectionModel();

    QModelIndexList List = sModel->selectedRows();

    for(int i = 0; i < List.size(); i++)
    {
        model->removeRow( List.at(i).row() );
    }
}

void Widget::on_ButtonFind_clicked()
{
    QString name = ui->lineEdit->text();
    QString str = QString("name = '%1'").arg(name);

    model->setFilter(str);
    model->select();
}
