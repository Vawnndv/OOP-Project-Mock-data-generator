#include <string>
#include <vector>
#include <tuple>
#include "RandomIntegerGenerator.h"
#include "NameGenerator.h"
#include "telephone.h"
#include "daymonthyear.h"
#include "id.h"
#include "email.h"
#include "address.h"
using namespace std;
#ifndef _MOCKSTUDENTDATAGENERATOR_H_
#define _MOCKSTUDENTDATAGENERATOR_H_
class Student {
private:
    ID id;
    NameGenerator name;
    float gpa;
    Telephone telephone;
    Email email;
    DayMonthYear DOB;
    Address address;
public:
    Student ();
    static Student studentRandom ();
    Student (ID, NameGenerator, float, Telephone , Email, DayMonthYear, Address);
    tuple <string, string, float, string, string, string, string> getData ();
    float getGPA ();
    void printStudent ();
    void print();
};
class MockStudentDataGenerator {
private:
    vector <Student> listStudent;
public:
    MockStudentDataGenerator ();
    void getDataInFile (string fileName);
    void addStudent (int n);
    float averageGPA ();
    void dataToFile (string fileName);
    void printAllStudent ();
    void printGPAGreaterThanAverageGPA ();
};
#endif