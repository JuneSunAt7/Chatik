#ifndef SERVERSENDFILE_H
#define SERVERSENDFILE_H
#define DEFAULT_PORT 51

#include <QObject>
#include <QHostAddress>
#include <QTcpServer>

class ServerSendFile : public QTcpServer
{
    Q_OBJECT
public:
    explicit ServerSendFile(QHostAddress host = QHostAddress::Any,
                            quint16 port      = DEFAULT_PORT,
                            QObject *parent   = 0);
public slots:
    void start();

protected:
    void incomingConnection(qintptr handle) ;

private:
    QHostAddress m_host;
    quint16      m_port;

signals:

};

#endif // SERVERSENDFILE_H
