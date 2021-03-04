#include <iostream>
#include <string>

using namespace std;

#include "student.h"
#include "roster.h"

/*Reads in comma-seperated string data and parses the information into temporary variables to be 
* passed to the add() function. Also increments lastIndex to the next spot in which a Student will
* be added
*/
void Roster::ParseAndAdd(string data)
{
	if (lastIndex < CLASS_ROSTER_SIZE)
	{
		DegreeProgram degree;
		++lastIndex;

		int rhs = data.find(",");
		string sID = data.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string fName = data.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string lName = data.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string eAddress = data.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int age = stoi(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int tempDays1 = stoi(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int tempDays2 = stoi(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int tempDays3 = stoi(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		if (data.substr(lhs, rhs - lhs) == "SECURITY")
		{
			degree = SECURITY;
		}
		else if (data.substr(lhs, rhs - lhs) == "NETWORK")
		{
			degree = NETWORK;
		}
		else if (data.substr(lhs, rhs - lhs) == "SOFTWARE")
		{
			degree = SOFTWARE;
		}

		Add(sID, fName, lName, eAddress, age, tempDays1, tempDays2, tempDays3, degree);


	}
	else
	{
		cout << "Error";
	}

	return;
}
/*Using the data from the ParseAndAdd() function, creates a new pointer to a Student object and adds
* it to the classRoster at the current (last) index. 
*/

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, 
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	Student* nStudent = new Student (studentID, firstName, lastName, emailAddress,
		age, daysArray, degreeProgram);


	classRoster[lastIndex] = nStudent;

	return;
	
}
/*Takes a studentID and checks through the current roster and removes the student  
*/
void Roster::Remove(string studentID)
{

	for (int i = 0; i <= lastIndex; ++i)
	{
		if (classRoster[i]->GetStudentID() == studentID)
		{
			if (i < CLASS_ROSTER_SIZE - 1)
			{
				Student* temp = classRoster[i];
				classRoster[i] = classRoster[CLASS_ROSTER_SIZE-1];
				classRoster[CLASS_ROSTER_SIZE-1] = temp;
			}
			lastIndex--;
			cout << endl << "Student with ID number " << studentID << " removed." << endl;
			break;
		}
		else if (i == lastIndex)
		{
			cout << "Student with ID number " << studentID << " not found." << endl;
		}
	}
	return;
}
//Calls the Print() function for each individual student in the roster
void Roster::PrintAll()
{
	for (int i = 0; i <= lastIndex; ++i)
	{
		classRoster[i]->Print();
	}

	return;
}
//Checks the roster for a given student ID and prints the average amount of days in their courses for that student
void Roster::PrintAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (classRoster[i]->GetStudentID() == studentID)
		{
			cout << "Average Number of Days in Course for Student "
				<< classRoster[i]->GetStudentID()
				<< ": "
				<< (classRoster[i]->GetNumDaysToComplete()[0] + classRoster[i]->GetNumDaysToComplete()[1]
					+ classRoster[i]->GetNumDaysToComplete()[2]) / 3 << endl;
			break;
		}
			
	}

}
//Checks through the roster and prints student email addresses that are invalid
void Roster::PrintInvalidEmails()
{
	string check = "";
	cout << endl << "Invalid student email addresses:" << endl;
	for (int i = 0; i <= lastIndex;)
	{
		check = classRoster[i]->GetEmailAddress();

		if (check.find(' ') != string::npos) //Any email with a space is automatically considered invalid
		{
			cout << check << endl;
			++i;
		}
		else if (check.find('@') != string::npos && check.find('.') != string::npos) //An email address must contain at least one period and an @ sign
		{
			++i;
		}
		else
		{
			cout << check << endl;
			++i;
		}
		
	}

}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i < CLASS_ROSTER_SIZE; ++i)
	{
		if (classRoster[i]->GetDegree() == degreeProgram)
		{
			classRoster[i]->Print();
		}
	}
	
}


Roster::~Roster()
{
	if (classRoster != nullptr)
	{
		delete[] classRoster;
		for (int i = 0; i < CLASS_ROSTER_SIZE; ++i)
		{
			classRoster[i] = nullptr;
		}
	}
	
}
