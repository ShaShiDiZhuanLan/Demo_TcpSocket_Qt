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
#ifndef TCPSEVER_H
#define TCPSEVER_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QByteArray>
#include <QNetworkInterface>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>

class TcpSever : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpSever(QObject *parent = 0);
    ~TcpSever();
    static QString getIPAddress();
    quint16 returnPeer();
    QString returnIP();
    QString returnOutIP();
public slots:
    QString returnReadSomething();
    void setSendMessage(QString str);
signals:
    void alreadyRead();
protected:
    void incomingConnection(qintptr handle);
private slots:
    void readSomething();
    QString GetHtml(QString url);
    QString GetNetIP(QString webCode);
private:
    QTcpSocket *socket;
    QString strTMP;
};

#endif // TCPSEVER_H
