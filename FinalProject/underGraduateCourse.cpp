#include "stdafx.h"
#include "underGraduateCourse.h"


underGraduateCourse::underGraduateCourse(Instructor i , bool b,string n,int co,int u,string ep,bool gu):Course(n,co,u,ep,gu)
{
	I = i;
	this->b = b;
}

void underGraduateCourse::print()
{
	Course::print();
	cout << I.getfirstname() << " " << I.getlastname() << endl;
	if (b == false)
	{
		cout << "this course doesn't need video projector." << endl;
	}
	else
	{
		cout << "this course need video projector." << endl;
	}
}

Instructor underGraduateCourse::getInstructor()
{
	return I;
}


underGraduateCourse::~underGraduateCourse()
{
}
