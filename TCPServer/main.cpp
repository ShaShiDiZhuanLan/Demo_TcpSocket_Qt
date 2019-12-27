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
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qInfo() << "This is Server";
    w.show();

    return a.exec();
}
