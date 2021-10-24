#include "stdafx.h"
#include "Course.h"


Course::Course()
{
}

Course::Course(string n, int c, int u, string ep,bool gu)
{
	name = n;
	code = c;
	unit = u;
	eventPlace = ep;
	this->gu = gu;
}

void Course::print()
{
	cout << name << " " << code << " " << unit << " " << eventPlace << endl;
}

Course::~Course()
{

}


