#include "MockStudentDataGenerator.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
Student ::Student (){
    this->id = ID();
    this->name = NameGenerator();
    RandomIntegerGenerator rig;
    this->gpa = (float)rig.next(10,100) / 10;
    this->telephone = Telephone();
    this->address = Address ();
    this->DOB = DayMonthYear();
    this->email = Email(this->id.getID(), "");
}
Student::Student (ID id, NameGenerator name, float gpa, Telephone phone, Email email, DayMonthYear dob, Address addr){
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    this->telephone = phone;
    this->email = email;
    this->DOB = dob;
    this->address = addr;
}
float Student::getGPA (){
    return this->gpa;
}
tuple <string, string, float, string, string, string, string> Student::getData (){
    tuple <string, string, float, string, string, string, string> temp;
    temp = make_tuple(this->id.getID(), this->name.getName(), this->gpa, this->telephone.getTel(), this->email.getMail(), this->DOB.getDay(), this->address.getAdd());
    return temp;
}
void Student::printStudent (){
    cout << "Student: " << this->id.getID() << " - " << this->name.getName() << endl;
    cout << "GPA=" << this->gpa << ", Telephone=" << this->telephone.getTel() << endl;
    cout << "Email=" << this->email.getMail() << endl;
    cout << "DOB=" << this->DOB.getDay() << endl;
    cout << "Address=" << this->address.getAdd() << endl << endl; 
}
void Student::print () {
    cout << this->id.getID() << " - " << this->name.getName() << ", GPA: " << this->gpa << endl;
}

MockStudentDataGenerator::MockStudentDataGenerator (){

}
void MockStudentDataGenerator::getDataInFile (string fileName){
    ifstream reader;
    reader.open(fileName, ios::in);

    while (!reader.eof()) {
        string buffer, id, name, phone, email, dob, addr, gpa;
        getline(reader, buffer);
        stringstream ss(buffer);
        getline(ss, id, ' ');
        getline(ss, id, ' '); // get id 
        getline(ss, name, ' ');
        getline(ss, name, '\n'); // get name
        getline(reader, buffer);
        stringstream ss1(buffer);
        getline(ss1, gpa, '=');
        getline(ss1, gpa, ','); // get gpa
        getline(ss1, phone, '=');
        getline(ss1, phone, '\n'); // get phone
        getline(reader, buffer);
        stringstream ss2(buffer);
        getline(ss2, email, '=');
        getline(ss2, email, '\n'); // get email
        getline(reader, buffer);
        stringstream ss3(buffer);
        getline(ss3, dob, '=');
        getline(ss3, dob, '\n'); // get day of birth
        getline(reader, buffer);
        stringstream ss4(buffer);
        getline(ss4, addr, '=');
        getline(ss4, addr, '\n'); // get address
        Student temp (ID(id), NameGenerator(name), stof(gpa), Telephone(phone), Email(email), DayMonthYear(dob), Address(addr));
        this->listStudent.push_back(temp);
    }

    reader.close();
}
void MockStudentDataGenerator::dataToFile (string fileName){
    ofstream writer;
    writer.open(fileName, ios::out);
    for (int i = 0; i < this->listStudent.size();  i++){
        tuple <string, string, float, string, string, string, string> temp = this->listStudent[i].getData();
        writer << "Student: " << get<0>(temp) << " - " << get<1>(temp) << endl;
        writer << "GPA=" << get<2>(temp) << ", Telephone=" << get<3>(temp) << endl;
        writer << "Email=" << get<4>(temp) << endl;
        writer << "DOB=" << get<5>(temp) << endl;
        writer << "Address=" << get<6>(temp);
        if (this->listStudent.size() - 1 != i)
            writer << endl;
    }
    writer.close();
}
void MockStudentDataGenerator::addStudent (int n){
    for (int i = 0; i < n; i++)
        this->listStudent.push_back(Student());
}
float MockStudentDataGenerator::averageGPA (){
    float avg = 0;
    for (int i = 0; i < this->listStudent.size(); i++)
        avg += this->listStudent[i].getGPA();
    return avg / this->listStudent.size();
}
void MockStudentDataGenerator::printAllStudent (){
    for (int i = 0; i < this->listStudent.size(); i++)
        this->listStudent[i].printStudent();   
}
void MockStudentDataGenerator::printGPAGreaterThanAverageGPA (){
    cout << "Average GPA is " << this->averageGPA() << endl;
    for (int i = 0; i < this->listStudent.size(); i++)
        if (this->averageGPA() <= this->listStudent[i].getGPA())
            this->listStudent[i].print();   
}