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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpClient = new TcpClient;
    connect(tcpClient,SIGNAL(alreadyRead()),this,SLOT(readSSMessage()));

    ui->lineEdit_ip->setText(tcpClient->returnIP());
    ui->lineEdit_port->setText(tcpClient->returnPort());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    tcpClient->sendMessage(ui->lineEdit->text());
}

void MainWindow::readSSMessage()
{
    ui->label_3->setText(tcpClient->returnMessage());
}

void MainWindow::on_pushButton_update_clicked()
{
    tcpClient->setIP(ui->lineEdit_ip->text());
    tcpClient->setPort(ui->lineEdit_port->text().toInt());
    tcpClient->newConnect();
}
