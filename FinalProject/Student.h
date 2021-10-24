#pragma once
#include "Person.h"
class Student:public Person
{
	friend ostream& operator <<(ostream &, const Student &);
public:
	Student();
	Student(int, int, string, string,string, string, string, string, int);
	string getGrade();
	int getstnum();
	~Student();
private:
	int stnum;
	int enteringYear;
	string fieldOfStudy;
	string Oriention;
	string grade;
};

