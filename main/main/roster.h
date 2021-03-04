#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

using namespace std;


class Roster
{
public:
	const static int CLASS_ROSTER_SIZE = 5; //non-changing roster size
	Student* classRoster[CLASS_ROSTER_SIZE];

	void ParseAndAdd(string data);
	void Add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void Remove(string studentID);
	void PrintAll();
	void PrintAverageDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degreeProgram);
	~Roster(); //Destructor that gets rid of the Roster 



private:
	
	int lastIndex = -1; //index of the last student in the roster
};

#endif
