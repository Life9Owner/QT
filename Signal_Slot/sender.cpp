#include "sender.h"

Sender::Sender(QObject *parent)
    : QObject{parent}
{

}
void Sender::incAge()
{
    m_age++;
    emit ageChanged(m_age);
}
int Sender::get_m_age()
{
    return this->m_age;
}
