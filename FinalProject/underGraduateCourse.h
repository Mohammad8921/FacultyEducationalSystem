#pragma once
#include "Instructor.h"
#include "Course.h"
class underGraduateCourse:public Course
{
public:
	underGraduateCourse(Instructor, bool, string, int, int, string, bool);
	virtual void print();
	virtual Instructor getInstructor();
	virtual ~underGraduateCourse();
private:
	Instructor I;
	bool b;
};

