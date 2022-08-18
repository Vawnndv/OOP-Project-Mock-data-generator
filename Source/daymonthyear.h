#include <string>
using namespace std;
#ifndef _DAYMONTHYEAR_H_
#define _DAYMONTHYEAR_H_
class DayMonthYear {
private:
    string day;
public:
    DayMonthYear ();
    DayMonthYear (string);
    string getDay ();
};
#endif