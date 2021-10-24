#include "stdafx.h"
#include "Student.h"


Student::Student()
{
}

Student::Student(int st, int ey, string fs, string o, string g,string f,string l,string a,int p):Person(f,l,a,p)
{
	stnum = st;
	enteringYear = ey;
	fieldOfStudy = fs;
	Oriention = o;
	grade = g;
}

string Student::getGrade()
{
	return grade;
}

int Student::getstnum()
{
	return stnum;
}

Student::~Student()
{

}

ostream & operator<<(ostream &output,const Student &s)
{
	output << s.firstname << " " << s.lastname << " " << s.address << " " << s.PhoneNumber << endl;
	cout << s.stnum << " " << s.enteringYear << " " << s.grade << " " << s.fieldOfStudy << " " << s.Oriention << endl;
	return output;
}
