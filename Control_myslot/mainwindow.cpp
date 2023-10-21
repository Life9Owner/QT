#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget* widget=new QWidget(this);
    setCentralWidget(widget);
    clickBtn=new QPushButton("click",widget);
    QCheckBox* cb=new QCheckBox("Connect",widget);
    cb->setCheckState(Qt::Checked);
    label=new QLabel(QTime::currentTime().toString(),widget);

    QHBoxLayout* hbox=new QHBoxLayout(widget);
    hbox->addWidget(clickBtn);
    hbox->addWidget(cb);
    hbox->addWidget(label);

    startTimer(1000);
    connect(clickBtn,&QPushButton::clicked,this,&MainWindow::onClick);
    connect(cb,&QCheckBox::checkStateChanged,this,&MainWindow::onCheck);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClick()
{
    statusBar()->showMessage("Button clicked");
}

void MainWindow::onCheck(int state)
{
    statusBar()->showMessage("");
    if(state==Qt::Checked)
    {
        connect(clickBtn,&QPushButton::clicked,this,&MainWindow::onClick);
    }
    else{
        disconnect(clickBtn,&QPushButton::clicked,this,&MainWindow::onClick);
    }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    label->setText(QTime::currentTime().toString());
}

