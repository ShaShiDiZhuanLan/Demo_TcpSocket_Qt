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
#include "tcpclient.h"
#include <QDebug>
TcpClient::TcpClient(QObject *parent) :
    QObject(parent)
{
    clientIP = "193.112.61.11"; //
    clientPort = 1414,
    connectBool = false;
    m_error = QAbstractSocket::ConnectionRefusedError;
}
TcpClient::~TcpClient()
{
    delete socket;
}
void TcpClient::newConnect()
{
    qDebug() << "newConnect";
    if(socket != Q_NULLPTR) {
        qDebug() << "!=";
        disconnect(socket,SIGNAL(readyRead()),this,SLOT(readMessage()));
        disconnect(this,SIGNAL(alreadyRead()),this,SLOT(returnMessage()));
        disconnect(socket,SIGNAL(connected()),this,SLOT(isConnect()));
        disconnect(socket,SIGNAL(disconnected()),this,SLOT(isDisconnect()));
        disconnect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(isError(QAbstractSocket::SocketError)));
        socket->abort();
    } else {
        qDebug() << "==";
        socket = new QTcpSocket;
    }
    qDebug() << "connectToHost";
    socket->connectToHost(clientIP,clientPort);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(this,SIGNAL(alreadyRead()),this,SLOT(returnMessage()));
    connect(socket,SIGNAL(connected()),this,SLOT(isConnect()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(isDisconnect()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(isError(QAbstractSocket::SocketError)));
}
void TcpClient::setIP(QString ip)
{
    clientIP = ip;
}
void TcpClient::setPort(int port)
{
    clientPort = port;
}
void TcpClient::sendMessage(QString str)
{
    qDebug() << "sendMessage" << str;
    socket->write(QByteArray(str.toLocal8Bit()));
}
void TcpClient::sendDWMessage()
{
    socket->write(QByteArray(QString("@").toLocal8Bit()));
}
bool TcpClient::returnConnectState()
{
    return connectBool;
}

QString TcpClient::returnIP()
{
    return clientIP;
}

QString TcpClient::returnPort()
{
    return QString::number(clientPort);
}
int TcpClient::returnError()
{
    return m_error;
}
void TcpClient::readMessage()
{
    message = QString::fromLocal8Bit(socket->readAll());
    emit alreadyRead();
}
void TcpClient::isConnect()
{
    connectBool = true;
}
void TcpClient::isDisconnect()
{
    connectBool = false;
}
void TcpClient::isError(QAbstractSocket::SocketError er)
{
    m_error = er;
    qDebug() << "Error:" << er;
}
void TcpClient::incomingConnection(qintptr handle)
{
    socket->setSocketDescriptor(handle);
}
QString TcpClient::returnMessage()
{
    return message;
}
