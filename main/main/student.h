#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

using namespace std;

class Student
{
	public:

		const static int DAYS_TO_COMPLETE = 3;
		Student();
		Student(string studentID, string firstName, string lastName, string emailAddress,
			int age, int* numDaysToComplete, DegreeProgram degree);
		
		//getters for each instance variable
		string	GetStudentID() const;
		string  GetFirstName() const;
		string  GetLastName() const;
		string  GetEmailAddress() const;
		int		GetAge() const;
		int*    GetNumDaysToComplete()const;
		DegreeProgram  GetDegree() const;

		//setters for each instance variable
		void SetStudentID(string studentID);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmailAddress(string emailAddress);
		void SetAge(int age);
		void SetNumDaysToComplete(int daysToComplete[]);
		void SetDegree(DegreeProgram degree);
		void Print() const;

		~Student();
		


	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int* numDaysToComplete;
		DegreeProgram degree;
};

#endif

