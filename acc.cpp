#include "acc.h"

acc::acc()
{

}

void acc::set_login(QString login)
{
this->login = login;
}

QString acc::get_login()
{
return login;
}

void acc::set_password(QString password)
{
this->password = password;
}

QString acc::get_password()
{
return password;
}

void acc::set_number_phone(QString number_phone)
{
this->number_phone = number_phone;
}

QString acc::get_number_phone()
{
return number_phone;
}
