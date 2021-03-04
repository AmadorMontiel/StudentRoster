#include <iostream>
#include <string>

using namespace std;

#include "student.h"
#include "roster.h"

int main()
{
    //Initial string of student data
    const string studentData[] =

    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Amador,Montiel,amont99@wgu.edu,28,0,60,60,SOFTWARE" };

    //Programmer and Course Information
    cout << "Course Title: Scripting and Programming - Applications" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "Student ID: 000990234" << endl;
    cout << "Name: Amador Montiel" << endl;
    cout << "******************************************************" << endl << endl;

    //Creation of new roster to store students
    Roster* classRoster = new Roster;
    
    //Loop through ParseAndAdd() reading the data from studentData and adding students to the roster
    for (int i = 0; i < classRoster->CLASS_ROSTER_SIZE; ++i)
    {
        classRoster->ParseAndAdd(studentData[i]);
    }

    //Print out starting student roster
    cout << "Printing Student Roster:" << endl;
    classRoster->PrintAll();
    cout << endl;

    //Loop thorough the roster, printing the average number of days in a course, per student
    cout << "Printing average number of days in course per student:" << endl;
    for (int i = 0; i < classRoster->CLASS_ROSTER_SIZE; ++i)
    {
        string tempID = classRoster->classRoster[i]->GetStudentID();
        classRoster->PrintAverageDaysInCourse(tempID);
    }

    //Prints a list of students based on degree program
    cout << endl;
    cout << "Printing students with degree program of Software:" << endl;
    classRoster->PrintByDegreeProgram(SOFTWARE);

    //Prints all invalid emails of students
    classRoster->PrintInvalidEmails();
    cout << endl;

    //Removes a student from the roster based on the Student ID
    cout << "Removing student A3.";
    classRoster->Remove("A3");

    //Roster re-print to show that remove() function above worked
    cout << "Re-printing Roster." << endl;
    classRoster->PrintAll();
    cout << endl;

    //Attempt to remove the same student from the roster that was already removed.
    cout << "Attempting to remove student A3 again." << endl;
    classRoster->Remove("A3");

    return 0;
}