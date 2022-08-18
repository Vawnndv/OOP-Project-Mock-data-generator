#include <string>
using namespace std;
#ifndef _EMAIL_H_
#define _EMAIL_H_
class Email {
private:
    string email;
    const string dns = "@student.hcmus.edu.vn"; 
public:
    Email ();
    Email (string);
    Email (string, string);
    string getMail ();
    Email& operator = (const Email&);
};
#endif