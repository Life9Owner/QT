#include <QCoreApplication>
#include"sender.h"
#include"receiver.h"
int main(int argc, char *argv[])
{
    Sender senderObj;
    Receiver receiverObj;
    senderObj.incAge();
//    qDebug()<<senderObj.get_m_age();
//    senderObj.incAge();
//    senderObj.incAge();
//    qDebug()<<senderObj.get_m_age();


    QObject::connect(&senderObj,&Sender::ageChanged,&receiverObj,&Receiver::ageChanged);
    senderObj.incAge();
    senderObj.incAge();
    receiverObj.~Receiver();
//    QObject::disconnect(&senderObj,&Sender::ageChanged,&receiverObj,&Receiver::ageChanged);

    senderObj.incAge();

}
