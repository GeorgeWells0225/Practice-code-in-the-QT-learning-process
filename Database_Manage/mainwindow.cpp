#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "donxml.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //开始 车辆管理界面
    on_actionCar_triggered();

    //打开数据库
    connectDB();
    //初始化数据
    initData();

    DonXML::createXML("../demo.xml");
//    QStringList list;
//    list << "上海大众" << "辉腾" << "452" <<"93" <<"8756" <<"56";
//    DonXML::appendXML("../demo.xml", list);

//    QStringList fList;
//     QStringList bList;
//      QStringList pList;
//       QStringList nList;
//        QStringList tList;
//     DonXML::readXML("../demo.xml", fList, bList, pList, nList, tList);
//        for(int i = 0; i < fList.size(); i++)
//        {
//            QString str = QString("%1:%2:卖出了%3,单价:%4,总价:%5")
//                    .arg(fList.at(i))
//                    .arg(bList.at(i))
//                    .arg(nList.at(i))
//                    .arg(pList.at(i))
//                    .arg(tList.at(i));
//            qDebug() << str.toUtf8().data();
//        }
}

MainWindow::~MainWindow()
{
    delete ui;
}
//车辆管理
void MainWindow::on_actionCar_triggered()
{
    //切换到车辆管理
    ui->stackedWidget->setCurrentWidget(ui->car);
    ui->label->setText("车辆管理");
}
//销售统计
void MainWindow::on_actionCalc_triggered()
{
    //切换到销售统计
    ui->stackedWidget->setCurrentWidget(ui->calc);
    ui->label->setText("销售统计");

}

void MainWindow::connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("Mysql@25");
    db.setDatabaseName("query_the_database");

    if(!db.open())
    {
        QMessageBox::warning(this, "数据库连接失败", db.lastError().text());
        return;
    }

}

void MainWindow::initData()

{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery("select name from factory");

    ui->comboBoxFactory->setModel(queryModel);

    ui->labelLast->setText("0");//初始化剩余数量
    ui->lineEditTotal->setEnabled(false);//金额



}

//下拉框槽函数
void MainWindow::on_comboBoxFactory_currentIndexChanged(const QString &arg1)
{

    if(arg1 == "请选择厂家")
    {
        ui->comboBoxBrand->clear();
        ui->lineEditPrice->clear();
        ui->labelLast->setText("0");
        ui->lineEditTotal->clear();
        ui->spinBox->setValue(0);
        ui->spinBox->setEnabled(false);
        ui->ButtonSure->setEnabled(false);

    }
    else
    {
        ui->comboBoxBrand->clear();
        QSqlQuery query;
        QString sql = QString("select name from brand where factory = '%1'").arg(arg1);
        query.exec(sql);

        while (query.next())
        {

            QString name = query.value(0).toString();
            ui->comboBoxBrand->addItem(name);


        }
        ui->spinBox->setEnabled(true);


    }

}

void MainWindow::on_comboBoxBrand_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;
    QString sql = QString("select price, last from brand where factory = '%1' and name = '%2'")
            .arg(ui->comboBoxFactory->currentText())
            .arg(arg1);

    query.exec(sql);

    while (query.next())
    {

        int price = query.value("price").toInt();
        int last = query.value("last").toInt();

        ui->lineEditPrice->setText( QString::number(price));
        ui->labelLast->setText( QString::number(last));



    }

}

void MainWindow::on_spinBox_valueChanged(int arg1)
{

    QString factoryStr = ui->comboBoxFactory->currentText();
    QString brandStr = ui->comboBoxBrand->currentText();


    if(0 == arg1)
    {
        ui->ButtonSure->setEnabled(false);
    }
    else
    {
        ui->ButtonSure->setEnabled(true);
    }

    QSqlQuery query;
    QString sql = QString("select sum, last from brand where factory = '%1'")
            .arg(factoryStr)
            .arg(brandStr);

    query.exec(sql);

    int last = 0;

    while (query.next())
    {
        last = query.value("last").toInt();

    }

    if(arg1 >last)
    {
        ui->spinBox->setValue(last);
        return;
    }



    int tempNum =last - arg1;
    ui->labelLast->setText( QString::number(tempNum));

    int price = ui->lineEditPrice->text().toInt();
    int sum = price * arg1;
    ui->lineEditTotal->setText( QString::number(sum));
}

void MainWindow::on_ButtonCancel_clicked()
{
    //on_comboBoxFactory_currentIndexChanged("请选择厂家");
    ui->comboBoxBrand->setCurrentIndex(0);

    ui->labelLast->setText("0");

}

void MainWindow::on_ButtonSure_clicked()
{
    int num = ui->spinBox->value();
    int last = ui->labelLast->text().toInt();


    QSqlQuery query;
    QString sql = QString("select sell from brand where factory = '%1' and name = '%2'")
            .arg(ui->comboBoxFactory->currentText())
            .arg(ui->comboBoxBrand->currentText());

    query.exec(sql);

    int sell = 0;

    while (query.next())
    {

        sell = query.value("sell").toInt();


    }

    sell += num;

    sql = QString("update brand set sell = %1, last = %2 where factory = '%3' and name = '%4'")
            .arg(sell)
            .arg(last)
            .arg(ui->comboBoxFactory->currentText())
            .arg(ui->comboBoxBrand->currentText());

    query.exec(sql);

    QStringList list;
    list <<ui->comboBoxFactory->currentText()
        <<ui->comboBoxBrand->currentText()
           <<ui->lineEditPrice->text()
           <<QString::number(num)
          <<ui->lineEditTotal->text();

        DonXML::appendXML("../demo.xml", list);

        QStringList fList;
         QStringList bList;
          QStringList pList;
           QStringList nList;
            QStringList tList;
         DonXML::readXML("../demo.xml", fList, bList, pList, nList, tList);
            for(int i = 0; i < fList.size(); i++)
            {
                QString str = QString("%1:%2:卖出了%3,单价:%4,总价:%5")
                        .arg(fList.at(i))
                        .arg(bList.at(i))
                        .arg(nList.at(i))
                        .arg(pList.at(i))
                        .arg(tList.at(i));

                ui->textEdit->append(str);
                qDebug() << str.toUtf8().data();
            }

    ui->ButtonSure->setEnabled(false);
    on_ButtonCancel_clicked();






}
