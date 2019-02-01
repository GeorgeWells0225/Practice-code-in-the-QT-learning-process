#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //菜单栏，工具栏，状态栏，书签，浮动窗口
    QMenuBar *mbar = menuBar();

    QMenu *pFile = mbar->addMenu("文件");

    QAction *pNew = pFile->addAction("新建");
    connect(pNew, &QAction::triggered,
            [=]()
    {
        qDebug() << "新建被按下";

    });
    pFile->addSeparator();
    QAction *pOpen = pFile->addAction("打开");
    QToolBar *toolbar = addToolBar("toolbar");

    toolbar->addAction(pNew);
    QPushButton *b = new QPushButton(this);
    b->setText("^_^");
    toolbar->addWidget(b);
    connect(b, &QPushButton::clicked,
            [=]{

        b->setText("123");
    });
    QStatusBar *sbar = statusBar();
    QLabel *label =new QLabel(this);
    label->setText("normal text file");
    sbar->addWidget(label);

    sbar->addWidget(new QLabel("2", this));

    sbar->addPermanentWidget(new QLabel("3", this));

    QTextEdit *textedit = new QTextEdit(this);
    setCentralWidget(textedit);

    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    QTextEdit *textedit1 = new QTextEdit(this);
    dock->setWidget(textedit1);









}

MainWindow::~MainWindow()
{

}
