//
//  student.hpp
//  Demo
//
//  Created by Nyla Gaston on 5/16/23.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
using std::array;



class student
{
public:
    const static int dayArraySize = 3;
    //student*days[dayArraySize];
    
    
public:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int* days;
    DegreeType degreeType;
    
public:
    student(); /*parameterless contructor*/
    student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeType degreeType); /*full constructor*/
    ~student(); /*destructor*/
   
    /*accessors*/
    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeType getDegreeType();
    
    /*mutators*/
    void setID(string ID);
    void setFirstname(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeType(DegreeType dt);
    
    
    static void printHeader();
    
    void print();
    
};

























#endif /* student_hpp */
