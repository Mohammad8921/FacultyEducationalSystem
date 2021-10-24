#pragma once
#include "Student.h"
#include "Course.h"
class takingCourse
{
public:
	takingCourse(Student , Course*);
	Student getstudent();
    Course* getcourse();
	~takingCourse();
private:
	Student s;
	Course *c;
};

