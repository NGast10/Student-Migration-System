//
//  main.cpp
//  Demo
//
//  Created by Nyla Gaston on 5/15/23.
//

#include <iostream>
#include "roster.hpp"
#include "student.hpp"

/*int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}*/

int main() 
{
//system("Scripting and Programming - Applications - C867, C++, 004928444, Nyla Gaston");
    cout << "Course: Scripting and Programming - Applications - C867,Language: C++, ID: 004928444, Name: Nyla Gaston" << std::endl;


    student* daysArraySize[3];
    const string studentData[] =

    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Nyla,Gaston,ngast10@wgu.edu,25, 15,30,45,SOFTWARE"
    };
    
    
    
    
    const int numStudents = 5;
    roster classRoster;
    
    for (int i=0; i < numStudents; i++) classRoster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    classRoster.printAll();
    
    for (int i = 0; i < 3; i++)
    {
        cout << "Displaying the students by Degree Program: " << degreeTypeString[i] << std::endl;
        classRoster.printByDegreeType((DegreeType)i);
    }
    
    cout << "Displaying the students with invalid email addresses: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
    
    cout << "Displaying the average days to complete a course: " << std::endl;
   // roster.printAverageDaysInCourse();
    for (int i =0; i < numStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i] ->getID());
    }
        
    cout << "Removing student with ID A3: " << std::endl;
    classRoster.removeStudentByID("A3");
    cout << std::endl;
    
    cout << "Removing student with ID A3: " << std::endl;
    classRoster.removeStudentByID("A3");
    cout << std::endl;
    
    
    system("Pause!");
    return 0;
    
    
}
