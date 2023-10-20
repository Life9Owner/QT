#include <QCoreApplication>
#include"sender.h"
int main(int argc, char *argv[])
{
    Sender senderObj;
    senderObj.incAge();
    qDebug()<<senderObj.get_m_age();
    senderObj.incAge();
    senderObj.incAge();
    qDebug()<<senderObj.get_m_age();

}
