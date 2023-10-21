#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QtWidgets>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    centralWidget()->setAttribute(Qt::WA_TransparentForMouseEvents);//set this,or centralWidget get the mouse event.
    this->setMouseTracking(true);
    auto *quitBtn=new QPushButton("Quit",this);
    quitBtn->setGeometry(50,25,500,50);
    connect(quitBtn,&QPushButton::clicked,qApp,&QApplication::quit);
    //(objsender,signal,objreceiver,slot)
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        qApp->quit();
    }
    else if(event->key()==Qt::Key_J)
    {
        qDebug()<<"hello world"<<"this is key 'j'";
//        qApp->quit();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x=event->pos().x();
    int y=event->pos().y();
    QString text="pos:"+QString::number(x)+","+QString::number(y);
    this->statusBar()->showMessage(text);
}

