#ifndef SENDER_H
#define SENDER_H

#include <QObject>

class Sender : public QObject
{
    Q_OBJECT
public:
    explicit Sender(QObject *parent = nullptr);
private:
    int m_age=10;
public:
    void incAge();
public:
    //mine
    int get_m_age();
signals:
    void ageChanged(int value);
};

#endif // SENDER_H
