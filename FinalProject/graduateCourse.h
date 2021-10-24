#pragma once
#include "Instructor.h"
#include "Course.h"
class graduateCourse:public Course 
{
public:
	graduateCourse(Instructor, int, string, int, int, string,bool);
	virtual void print();
	virtual Instructor getInstructor();
	virtual ~graduateCourse();
private:
	Instructor I;
	int Capacity;
};

