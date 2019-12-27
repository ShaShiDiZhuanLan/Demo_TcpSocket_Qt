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
#ifndef INDOORGUIDEDCLIENT_H
#define INDOORGUIDEDCLIENT_H
#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QByteArray>
#include <QAbstractSocket>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = 0);
    ~TcpClient();
    void newConnect();
    void setIP(QString ip);
    void setPort(int port);
    void sendMessage(QString str);
    void sendDWMessage();
    bool returnConnectState();
    QString returnIP();
    QString returnPort();
    int returnError();
signals:
    void alreadyRead();
public slots:
    QString returnMessage();
private slots:
    void readMessage();
    void isConnect();
    void isDisconnect();
    void isError(QAbstractSocket::SocketError er);
protected:
    void incomingConnection(qintptr handle);
private:
    QTcpSocket *socket = Q_NULLPTR;
    QString clientIP;
    int clientPort;
    QString message;
    bool connectBool;
    QAbstractSocket::SocketError m_error;
};

#endif // INDOORGUIDEDCLIENT_H
