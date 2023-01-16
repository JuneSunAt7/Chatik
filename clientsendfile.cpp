#include "clientsendfile.h"
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDataStream>

ClientSendFile::ClientSendFile(QObject *parent) : QObject(parent)
{

}

void ClientSendFile::sendFile(QHostAddress m_host){
    QTcpSocket *socket = new QTcpSocket;

        connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));

        // specified m_host and m_port to yours
        socket->connectToHost(m_host, 51);
        socket->waitForConnected();

        if ( (socket->state() != QAbstractSocket::ConnectedState) || (!m_file->open(QIODevice::ReadOnly)) ) {
            qDebug() << "Socket can't connect or can't open file for transfer";
            delete socket;
            return;
        }

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_4);

        // This part i  need to send not only file, but file name too
        // Erase it if you needn't it
        out << (quint32)0 << m_file->fileName();

        QByteArray q = m_file->readAll();
        block.append(q);
        m_file->close();

        out.device()->seek(0);
        // This difference appear because of we send file name
        out << (quint32)(block.size() - sizeof(quint32));

        qint64 x = 0;
        while (x < block.size()) {
            qint64 y = socket->write(block);
            x += y;
            //qDebug() << x;    // summary size you send, so you can check recieved and replied sizes
        }
}

