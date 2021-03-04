#include <iostream>
#include <string>
#include <iomanip>
#include "student.h"

using namespace std;


Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->numDaysToComplete = new int[DAYS_TO_COMPLETE];
	this->age = -1;
	for (int i = 0; i < DAYS_TO_COMPLETE; i++)
	{
		this->numDaysToComplete[i] = 0;
	}
	this->degree = degree;
}
Student::Student(string studentID, string firstName, string lastName,
	string emailAddress, int age, int* numDaysToComplete, DegreeProgram degree)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->numDaysToComplete = new int[DAYS_TO_COMPLETE];
	for (int i = 0; i < DAYS_TO_COMPLETE; ++i)
	{
		this->numDaysToComplete[i] = numDaysToComplete[i];
	}
	this->degree = degree;
}

void Student::SetStudentID(string studentID)
{
	this->studentID = studentID;
	return;
}

void Student::SetFirstName(string firstName)
{
	this->firstName = firstName;
	return;
}

void Student::SetLastName(string lastName)
{
	this->lastName = lastName;
	return;
}

void Student::SetEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
	return;
}

void Student::SetAge(int age)
{
	this->age = age;
	return;
}

void Student::SetNumDaysToComplete(int numDaysToComplete[])
{
	this->numDaysToComplete = new int[DAYS_TO_COMPLETE];
	for (int i = 0; i < DAYS_TO_COMPLETE; ++i)
	{
		this->numDaysToComplete[i] = numDaysToComplete[i];
	}
	return;
}

void Student::SetDegree(DegreeProgram degree)
{
	this->degree = degree;
	return;
}

void Student::Print() const
{
	cout << GetStudentID() << '\t';
	cout << "First Name: " << GetFirstName() << '\t';
	cout << "Last Name: " << GetLastName() << '\t';
	cout << "Age: "	<< GetAge() << '\t';
	cout << "\tDays Left In Course: " << "{" << numDaysToComplete[0] << ", "
		 << numDaysToComplete[1] << ", " << numDaysToComplete[2] << "}	" << '\t';
	cout << "Degree Program: "      << degreeStrings[GetDegree()] << endl;

	return;
}

Student::~Student()
{
	if (numDaysToComplete != nullptr)
	{
		delete[] numDaysToComplete;
		numDaysToComplete = nullptr;
	}
}

string	Student::GetStudentID() const
{
	return studentID;
}

string  Student::GetFirstName() const
{
	return firstName;
}

string  Student::GetLastName() const
{
	return lastName;
}

string  Student::GetEmailAddress() const
{
	return emailAddress;
}

int		Student::GetAge() const
{
	return age;
}

int*	Student::GetNumDaysToComplete() const
{
	return numDaysToComplete;
}

DegreeProgram Student::GetDegree() const
{
	return degree;
}

