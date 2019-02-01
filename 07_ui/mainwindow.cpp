#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QMovie *myQmove = new QMovie("../image/999.gif");
    ui->labelmove->setMovie(myQmove);

    myQmove->start();
    ui->labelmove->setScaledContents(1);

    ui->label_wang->setText("<h1><a href=\"https://www.bilibili.com/video/av9080024\">吔屎啦你</a></h1>");
    ui->label_wang->setOpenExternalLinks(1);

    ui->lcdNumber->display(666);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(66);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_change_clicked()
{
    static int i = 1;

    ui->stackedWidget->setCurrentIndex(++i % 4);


}
