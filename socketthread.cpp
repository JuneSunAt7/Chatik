#include "socketthread.h"
#include <QFile>
#include <QDataStream>

SocketThread::SocketThread(qintptr descriptor, QObject *parent)
    : QThread(parent),
      m_socketDescriptor(descriptor),
      m_blockSize(0)
{
}

SocketThread::~SocketThread()
{
    delete m_socket;
}

void SocketThread::run()
{
    m_socket = new QTcpSocket;
    m_socket->setSocketDescriptor(m_socketDescriptor);

    connect(m_socket, SIGNAL(readyRead()),    this, SLOT(onReadyRead()),    Qt::DirectConnection);
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()), Qt::DirectConnection);

    exec();
}

void SocketThread::onReadyRead()
{
    QDataStream in(m_socket);
    in.setVersion(QDataStream::Qt_5_4);

    if (m_blockSize == 0) {
        if (m_socket->bytesAvailable() < sizeof(quint32))
        return;
        in >> m_blockSize;
    }
    if (m_socket->bytesAvailable() < m_blockSize)
        return;

    QString fileName;
    // get sending file name
    in >> fileName;
    QByteArray line = m_socket->readAll();

    QString filePath = "YOUR"; // your file path for receiving
    fileName = fileName.section("/", -1);
    QFile target(filePath + "/" + fileName);

    if (!target.open(QIODevice::WriteOnly)) {
        qDebug() << "Can't open file for written";
        return;
    }
    target.write(line);

    target.close();

    emit onFinishRecieved();
    m_socket->disconnectFromHost();
}

void SocketThread::onDisconnected()
{
    m_socket->close();

    // leave event loop
    quit();
}
