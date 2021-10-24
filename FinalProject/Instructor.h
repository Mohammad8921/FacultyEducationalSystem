#pragma once
#include "Person.h"
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

class Instructor :public Person
{
public:
	friend ostream& operator << (ostream&, const Instructor &);
	Instructor();
	Instructor(int, string, string, string, string, string, int);
	int getemID() { return emID; }
	~Instructor();
private:
	int emID;
	string Department;
	string LEC; //last educational certificate
};
#endif // !INSTRUCTOR_H


