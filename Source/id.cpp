#include "id.h"
#include "RandomIntegerGenerator.h"
#include <sstream>

ID::ID () {
    RandomIntegerGenerator rig;
    stringstream ss;
    ss << rig.next(2000000,2999999);
    this->id = ss.str();
}

ID::ID (string str){
    this->id = str;
}

string ID::getID () {
    return this->id;
}