//
//  roster.hpp
//  Demo
//
//  Created by Nyla Gaston on 5/16/23.
//

#ifndef roster_hpp
#define roster_hpp

#include <stdio.h>
#include "student.hpp"

#endif /* roster_hpp */

class roster
{
public:
    int lastIndex = -1;
    const static int numStudents = 5;
    student* classRosterArray[numStudents];
    
public:
    void parse(string row);
    void add(string sID,
             string sFirstName,
             string sLastName,
             string sEmail,
             int sAge,
             int sDays1,
             int sDays2,
             int sDays3,
             DegreeType dt);
    
    void removeStudentByID(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeType(DegreeType dt);
    ~roster();
    
};

























