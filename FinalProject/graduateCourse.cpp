#include "stdafx.h"
#include "graduateCourse.h"


graduateCourse::graduateCourse(Instructor i, int c, string n, int co, int u, string ep,bool gu):Course(n,co,u,ep,gu)
{
	I = i;
	Capacity = c;
}

void graduateCourse::print()
{
	Course::print();
	cout << I.getfirstname() << " " << I.getlastname() << " " << Capacity << endl;
}

Instructor graduateCourse::getInstructor()
{
	return I;
}

graduateCourse::~graduateCourse()
{
}
