#pragma once
#include "Instructor.h"
#include <string>
#include <iostream>
using namespace std;
class Course
{
	
public:
	Course();
	Course(string, int, int, string, bool);
	int getcode() { return code; }
	bool getgu(){ return gu; }
	void setgu(bool b) { gu = b; }
	virtual Instructor getInstructor() { return Instructor(); }
	virtual void print();
	virtual ~Course();
private:
	string name;
	int code;
	int unit;
	string eventPlace;
	bool gu;
};

