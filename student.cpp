//
//  student.cpp
//  Demo
//
//  Created by Nyla Gaston on 5/16/23.
//

#include "student.hpp"

student::student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    days = new int [dayArraySize];
    for (int i=0; i < dayArraySize; i++) this->days[i] = 0;
    //this->degreeType = DegreeType::SECURITY;
}


student::student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeType degreetype)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this ->days = new int [dayArraySize];
    for (int i=0; i < dayArraySize; i++) this->days[i] = days[i];
    this->degreeType = degreetype;
}

student::~student() {}

string student::getID() { return this->studentID;}
string student::getFirstName() {return this->firstName;}
string student:: getLastName() {return this->lastName;}
string student:: getEmail() {return this->email;}
int student:: getAge() {return this->age;}
int* student:: getDays() {return days;}
DegreeType student:: getDegreeType() {return this-> degreeType;}


void student::setID(string ID) {this->studentID = ID;}
void student::setFirstname(string firstName) {this->firstName = firstName;}
void student::setLastName(string lastName) {this->lastName = lastName;}
void student::setEmail(string email) {this->email = email;}
void student::setAge(int age) {this->age = age;}
void student::setDays(int days[])
{
    days = new int [dayArraySize];
    for (int i = 0; i < dayArraySize; i++) this->days[i] = days[i];
}
void student::setDegreeType(DegreeType dt) {this->degreeType = dt;}

void student::printHeader()
{
    cout <<"Output format: ID|FirstName|LastName|Email|Age|DaysToCompleteCourses|DegreeProgramType\n";
}


void student::print()
{
    cout<<this->getID() << '\t';
    cout<<this->getFirstName() << '\t';
    cout<<this->getLastName() << '\t';
    cout<<this->getEmail() << '\t';
    cout<<this->getAge() << '\t';
    cout<<this->days[0] << ',';
    cout<<this->days[1] << ',';
    cout<<this->days[2] << '\t';
    cout<< degreeTypeString[this->getDegreeType()] << '\n';
    
}































