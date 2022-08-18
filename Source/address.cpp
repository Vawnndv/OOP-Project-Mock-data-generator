#include "address.h"
#include "NameGenerator.h"
#include "RandomIntegerGenerator.h"
#include <sstream>

Address::Address () {
    stringstream ss;
    RandomVietnamFullnameGenerator rvfg;
    RandomIntegerGenerator rig;
    ss << rig.next(1,100) << "/" << rig.next(1,100) << " " << rvfg.next() << ", " << this->dns;
    this->addr = ss.str();
}

Address::Address (string str) {
    this->addr = str;
}

string Address::getAdd () {
    return this->addr;
}

Address& Address::operator = (const Address& a) {
    this->addr = a.addr;
    return *this;
}