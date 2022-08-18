#include <string>
using namespace std;
#ifndef _ADDRESS_H_
#define _ADDRESS_H_
class Address {
private:
    string addr;
    const string dns = "Ho Chi Minh city";
public:
    Address ();
    Address (string);
    string getAdd ();
    Address& operator = (const Address&);
};
#endif