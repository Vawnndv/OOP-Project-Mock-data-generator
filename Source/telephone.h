#include <string>
using namespace std;
#ifndef _TELEPHONE_H_
#define _TELEPHONE_H_
class Telephone {
private:
    string tel;
public:
    Telephone ();
    Telephone (string);
    string getTel();
};
#endif