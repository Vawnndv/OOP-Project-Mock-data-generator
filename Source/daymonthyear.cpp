#include "daymonthyear.h"
#include "RandomIntegerGenerator.h"
#include <sstream>
DayMonthYear::DayMonthYear () {
    stringstream ss;
    RandomIntegerGenerator rig;
    ss << rig.next(1,31) << "/" << rig.next(1,12) << "/" << rig.next(1990, 2021);
    this->day = ss.str();
}

DayMonthYear::DayMonthYear (string str) {
    this->day = str;
}

string DayMonthYear::getDay () {
    return this->day;
}