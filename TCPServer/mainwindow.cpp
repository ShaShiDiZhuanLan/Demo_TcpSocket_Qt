/*-------------------------------------------------
#
# Project created by QtCreator
# Author: 沙振宇
# CreateTime: 2016-04-22
# UpdateTime: 2019-12-27
# Info: QTcpSocket客户端、服务端互发字符串Demo
# Url:https://shazhenyu.blog.csdn.net/article/details/53283686
# Github:https://github.com/ShaShiDiZhuanLan/Demo_TcpSocket_Qt
#
#-------------------------------------------------*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpSever = new TcpSever;
    QString str;
    str = "network ip:"+tcpSever->returnOutIP()+" port:1414";
    str =  str + "\n\nlocal ip:"+tcpSever->getIPAddress();
    ui->label_3->setText(str);
    if(!tcpSever->listen(QHostAddress::Any,1414)){
        this->close();
    }
    connect(tcpSever,SIGNAL(alreadyRead()),this,SLOT(readMessage()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tcpSever;
}

void MainWindow::readMessage()
{
    ui->label_2->setText(QString("端口%0发来:%1").arg(QString::number(tcpSever->returnPeer()),
                                                tcpSever->returnReadSomething()));
}

void MainWindow::on_pushButton_clicked()
{
    tcpSever->setSendMessage(ui->lineEdit->text());
}

void MainWindow::on_pushButton_2_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针
    QString Str = tcpSever->returnOutIP();
    clipboard->setText(Str);
}
