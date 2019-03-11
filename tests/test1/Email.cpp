#include "Email.h"

Email::Email(QObject *parent) : QObject(parent)
{

}

Email::Email(const QString &address, const QString &name, QObject *parent) : QObject(parent)
{
    _address = address;
    _name = name;
}
