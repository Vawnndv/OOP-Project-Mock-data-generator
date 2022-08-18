#include "telephone.h"
#include "RandomIntegerGenerator.h"
#include <sstream>
Telephone::Telephone () {
    stringstream ss;
    RandomIntegerGenerator rig;
    ss << rig.next(100,999) << "-" << rig.next(100,999) << "-" << rig.next(100,999); 
    this->tel = ss.str();
}

Telephone::Telephone (string str) {
    this->tel = str;
}

string Telephone::getTel () {
    return this->tel;
}