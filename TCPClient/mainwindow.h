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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void readSSMessage();

    void on_pushButton_update_clicked();

private:
    Ui::MainWindow *ui;
    TcpClient *tcpClient;
};

#endif // MAINWINDOW_H
