//
//  roster.cpp
//  Demo
//
//  Created by Nyla Gaston on 5/16/23.
//

#include "roster.hpp"
#include "student.hpp"

void roster::parse(string studentData)
{
    /*DegreeType dt = SECURITY;
    if (studentData.at(0) == 'SO' ) dt = SOFTWARE;
    else if (studentData.at(0) == 'N') dt = NETWORK;*/
    
    
    int rsc = studentData.find(",");
    string studentID = studentData.substr(0,rsc); /*student id*/
    
    int lsc = rsc + 1;
    rsc = studentData.find(",",lsc);
    string firstname = studentData.substr(lsc, rsc - lsc); /*first name*/
    
    lsc = rsc + 1;
    rsc = studentData.find(",",lsc);
    string lastname = studentData.substr(lsc, rsc - lsc); /*last name*/
    
    lsc = rsc + 1;
    rsc = studentData.find(",",lsc);
    string email = studentData.substr(lsc, rsc - lsc); /*email*/
    
    lsc = rsc + 1;
    rsc = studentData.find(",",lsc);
    int age = stoi(studentData.substr(lsc, rsc - lsc)); /*age*/
    
    lsc = rsc + 1;
    rsc = studentData.find(",",lsc);
    int d1 = stod(studentData.substr(lsc,rsc - lsc));
    lsc = rsc + 1;
    rsc = studentData.find(",",lsc);
    int d2 = stod(studentData.substr(lsc,rsc - lsc));
    lsc = rsc + 1;
    rsc = studentData.find(",",lsc);
    int d3 = stod(studentData.substr(lsc,rsc - lsc));
    
    lsc = rsc + 1;
    rsc = studentData.find(",");
    string strDT = (studentData.substr(lsc,rsc - lsc));
    
    DegreeType dt = DegreeType::SECURITY;
    if (strDT == "SECURITY") {
        dt = DegreeType::SECURITY;
    }
    else if (strDT == "NETWORK")
    {
        dt = DegreeType::NETWORK;
    }
    else if (strDT == "SOFTWARE" )
    {
        dt = DegreeType::SOFTWARE;
    }
    
    
    add(studentID,firstname, lastname, email, age, d1, d2, d3, dt);
    

}

void roster::add(string studentID, string firstName, string lastName, string email, int age, int days1,int days2, int days3, DegreeType degreeType)
{
    int parr[3] = {days1,days2,days3};
    classRosterArray[++lastIndex] = new student(studentID,firstName,lastName,email,age,parr,degreeType);
}

void roster::printAll()
{
    student::printHeader();
    for (int i = 0; i<=roster::lastIndex; i++)
    {
        //classRosterArray[i] -> getID();
        //classRosterArray[i] -> getFirstName();
        classRosterArray[i] -> print();
       /* cout << classRosterArray[i] -> getID(); cout << '\t';
        cout << classRosterArray[i] -> getFirstName(); cout << '\t';
        cout << classRosterArray[i] -> getLastName(); cout << '\t';
        cout << classRosterArray[i] -> getEmail(); cout << '\t';
        cout << classRosterArray[i] -> getAge(); cout << '\t';
        cout << classRosterArray[i] -> days[0]; cout << '\t';
        cout << classRosterArray[i] -> days[1]; cout << '\t';
        cout << classRosterArray[i] -> days[2]; cout << '\t';
        cout << degreeTypeString[classRosterArray[i]->getDegreeType()] << std::endl;*/
    }
}



void roster::printByDegreeType(DegreeType dt)
{
    student::printHeader();
    for (int i = 0; i <= roster::lastIndex; i++) {
        if (roster::classRosterArray[i] ->getDegreeType() == dt) classRosterArray[i] ->print();
    }
}

void roster::printInvalidEmails()
{
    bool any = false;
    for (int i =0; i <= roster::lastIndex; i++)
    {
        
        
        string sEmail = (classRosterArray[i] ->getEmail());
        if (sEmail.find('@') == string::npos || (sEmail.find('.') == string::npos)){
            any = true;
            cout << sEmail << ": " << classRosterArray[i] ->getEmail() << std::endl;
        }
        
        if (sEmail.find(' ') == string::npos){
            any = false;
            cout << sEmail << ": " << classRosterArray[i] ->getEmail() << std::endl;
        }
        
    }
    if (!any) cout << "NONE" << std::endl;
}

void roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= roster::lastIndex; i++)
    {
       if (classRosterArray[i] ->getID() == studentID)
        {
            cout << studentID << ":";
            cout << ((classRosterArray[i] ->days[0])
                     + (classRosterArray[i] ->days[1])
                     + (classRosterArray[i] ->days[2])
                     )/3 << std::endl;
        }
    }
}

void roster::removeStudentByID(string studentID)
{
    bool success = false;
    for (int i=0; i <= roster::lastIndex; i++)
    {
        if (classRosterArray[i] ->getID() == studentID)
        {
            success = true;
            if (i < numStudents - 1)
            {
                student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents -1];
                classRosterArray[numStudents-1] = temp;
            }
            roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << studentID << "The student was removed from the roster. " << std::endl;
        this ->printAll();
    }
    else cout << studentID << "The student was not found." << std::endl;
}


roster::~roster()
{
    cout << "The Destructor has been called!" << std::endl << std::endl;
    for (int i =0; i < numStudents; i++)
    {
        cout << "The student number will be destroyed." << i+1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}






























