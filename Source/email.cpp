#include "email.h"
#include <sstream>

Email::Email () {
    this->email = this->dns;
}

Email::Email (string str) {
    this->email = str;
}

Email::Email (string str, string s) {
    this->email = str + this->dns;
}

string Email::getMail () {
    return this->email;
}

Email& Email::operator = (const Email& e){
    this->email = e.email;
    return *this;
}