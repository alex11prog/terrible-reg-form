#ifndef ACC_H
#define ACC_H
#include <QString>

class acc
{
    QString login;
    QString password;
    QString number_phone;
public:
    acc();
    void set_login(QString login);
    QString get_login();
    void set_password(QString password);
    QString get_password();
    void set_number_phone(QString number_phone);
    QString get_number_phone();
};

#endif // ACC_H
