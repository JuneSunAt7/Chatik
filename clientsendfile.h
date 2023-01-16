#ifndef CLIENTSENDFILE_H
#define CLIENTSENDFILE_H

#include <QObject>
#include <QFile>
#include <QHostAddress>

class ClientSendFile : public QObject
{
    Q_OBJECT
public:
    explicit ClientSendFile(QObject *parent = nullptr);

    void sendFile(QHostAddress m_host);

    QFile *m_file;

signals:

};

#endif // CLIENTSENDFILE_H
