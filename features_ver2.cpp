#include "chatdialog.h"
#include "client.h"
#include "connection.h"
#include "peermanager.h"
<<<<<<< HEAD
=======
#include "clientsendfile.h"

>>>>>>> 818b409 (NEW FILE UPDATE)
#define BUF_SIZE 1024*4

#include <QFileDialog>
#include <QFileInfo>

void ChatDialog::choseFile(){
    QString filePath = QFileDialog::getOpenFileName(this, tr("Add file"));
    QFileInfo fInfo(filePath);
<<<<<<< HEAD
=======
    ClientSendFile sender;

>>>>>>> 818b409 (NEW FILE UPDATE)

    fileName = fInfo.fileName();

    QFile file(filePath);

    label_2->setText(fileName);

<<<<<<< HEAD
    //label_2->clear();
=======
    sender.m_file = &file;
    sender.sendFile(QHostAddress::AnyIPv4);


    appendMessage(myNickName, "send file: "+fileName);

    label_2->clear();
>>>>>>> 818b409 (NEW FILE UPDATE)

}
void ChatDialog::setNickname(){

}

void ChatDialog::addStick(){

}

void ChatDialog::setNotif(){


}
