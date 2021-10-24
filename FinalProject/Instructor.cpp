#include "stdafx.h"
#include <vector>
#include "Instructor.h"
using namespace std;


Instructor::Instructor()
{
	emID = 0;
}

Instructor::Instructor(int em, string d, string lec, string f, string l, string a, int p):Person(f,l,a,p)
{
	emID = em;
	Department = d;
	LEC = lec;
}


Instructor::~Instructor()
{
}

ostream & operator<<(ostream &output, const Instructor &in)
{
	output << in.firstname << " " << in.lastname << " " << in.address << " " << in.PhoneNumber << endl;
	output << in.emID << " " << in.Department << " " << in.LEC << endl;
	return output;
}

