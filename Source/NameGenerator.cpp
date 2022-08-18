#include <iostream>
#include <sstream>
#include <fstream>
#include "NameGenerator.h"
using namespace std;
NameGenerator::NameGenerator () {
    RandomVietnamFullnameGenerator rvfg;
    this->name = rvfg.next();
}

NameGenerator::NameGenerator (string str) {
    this->name = str;
}

string NameGenerator::getName () {
    return this->name;
}
// Class NameGenerator
void NameGenerator::input(string name){
    this->name = name;
}
void NameGenerator::ouput(){
    cout << "Name: " << this->name << endl;
}
// Class RandomVietnamFullnameGenerator
string RandomVietnamFullnameGenerator::readFile(string FileName){
    ifstream f;
    string str;
    int n;
    f.open(FileName);
    f >> n;
    int index = _rng.next(1,n);
    for (int i = 0; i < n; i++){
        f >> str;
        if (i == index - 1)
            break;
    }
    f.close();
    return str;
}

string RandomVietnamFullnameGenerator::next(){
    stringstream sstr;
    sstr << readFile(FIRST_NAME_FILE) << " " << readFile(MIDDLE_NAME_FILE) << " " << readFile(LAST_NAME_FILE);
    return sstr.str();
}