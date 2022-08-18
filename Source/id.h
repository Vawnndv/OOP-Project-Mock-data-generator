#include <string>
using namespace std;
#ifndef _ID_H_
#define _ID_H_
class ID {
private:
    string id;
public:
    ID ();
    ID (string);
    string getID ();
};
#endif