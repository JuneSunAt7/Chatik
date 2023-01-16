#include "serversendfile.h"
#include "socketthread.h"

ServerSendFile::ServerSendFile(QHostAddress host, quint16 port, QObject *parent)
    : QTcpServer(parent),
      m_host(host),
      m_port(port) {

    //some code
    start();

}


void ServerSendFile::start()
{
    if ( this->listen(m_host, m_port) )
        qDebug() << "Server started at " << m_host.toString() << ":" << m_port;
    else
        qDebug() << "Can't start server";
}

void ServerSendFile::incomingConnection(qintptr handle)
{
    qDebug() << "incomingConnection = " << handle;
    SocketThread *thread = new SocketThread(handle);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
