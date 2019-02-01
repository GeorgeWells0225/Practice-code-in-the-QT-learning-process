#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QMenuBar *mbar = menuBar();
    QMenu *menu = mbar->addMenu("对话框");
    QAction *pl = menu->addAction("模态对话框");
    connect(pl, &QAction::triggered,
            []()
    {

        QDialog dlg;
        dlg.exec();
        qDebug() << "111111";

    });

    QAction *p2 = menu->addAction("非模态对话框");
    connect(p2, &QAction::triggered,
            []()
    {

        QDialog dlg;
        dlg.show();
        qDebug() << "111111";

    });


    QAction *p3 = menu->addAction("关于对话框");
    connect(p3, &QAction::triggered,
            [=]()
    {

        QMessageBox::about(this, "about", "关于Qt");
    });

    QAction *p4 = menu->addAction("问题对话框");
    connect(p4, &QAction::triggered,
            [=]()
    {

        int ret = QMessageBox::question(this, "question", "Are you OK?");

        switch (ret) {

        case QMessageBox::Yes:
            qDebug() << "I am OK";
            break;

        case QMessageBox::No:
            qDebug() << "i am bad";
            break;


        }

    });

    QAction *p5 = menu->addAction("文件对话框");
    connect(p5, &QAction::triggered,
            [=]()
    {

        QString path = QFileDialog::getOpenFileName(
                    this, "open", "../" , "souce(*.cpp *.h);;"
                                          "Text(*.txt);;"
                                          "all(*.*)");
        qDebug() <<path;


    });






}

MainWindow::~MainWindow()
{

}
