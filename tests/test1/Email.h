#ifndef EMAIL_H
#define EMAIL_H

#include <QObject>

class Email : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString address READ address WRITE setAddress)
    Q_PROPERTY(QString name READ name WRITE setName)
public:
    explicit Email(QObject *parent = nullptr);
    explicit Email(const QString &address,const QString &name,QObject *parent = nullptr);

private:
    QString address() {
        return _address;
    }
    void setAddress(const QString &address) {
        _address = address;
    }
    QString name() {
        return _name;
    }
    void setName(const QString &name) {
        _name = name;
    }
    QString _address;
    QString _name;
};

#endif // EMAIL_H
