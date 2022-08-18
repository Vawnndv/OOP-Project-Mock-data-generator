#include <cstdlib>
#include <ctime>
#include <string>
#include "RandomIntegerGenerator.h"
#define FIRST_NAME_FILE "FirstName.txt"
#define MIDDLE_NAME_FILE "MiddleName.txt"
#define LAST_NAME_FILE "LastName.txt"
#ifndef _NAMEGENERATOR_H_
#define _NAMEGENERATOR_H_
using namespace std;
class NameGenerator;
class RandomIntegerGenerator;
class RandomVietnamFullnameGenerator;

class NameGenerator{
private:
    string name;
public:
    NameGenerator ();
    NameGenerator (string);
    void input(string name);
    void ouput();
    string getName ();
};

class RandomVietnamFullnameGenerator {
private:
	RandomIntegerGenerator _rng;
public:
    string readFile(string);
	string next(); 
};
#endif