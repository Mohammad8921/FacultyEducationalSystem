#include "stdafx.h"
#include "takingCourse.h"


takingCourse::takingCourse(Student s, Course *c)
{
	this->s = s;
	this->c = c;
}

Student takingCourse::getstudent()
{
	return s;
}

Course* takingCourse::getcourse()
{
	return c;
}

takingCourse::~takingCourse()
{

}
