#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    centralWidget()->setAttribute(Qt::WA_TransparentForMouseEvents);//set this,or centralWidget get the mouse event.
    this->setMouseTracking(true);
    auto *quitBtn=new QPushButton("Quit",this);
    quitBtn->setGeometry(50,25,100,50);
    connect(quitBtn,&QPushButton::clicked,qApp,&QApplication::quit);
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
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x=event->pos().x();
    int y=event->pos().y();
    QString text="pos:"+QString::number(x)+","+QString::number(y);
    this->statusBar()->showMessage(text);
}

