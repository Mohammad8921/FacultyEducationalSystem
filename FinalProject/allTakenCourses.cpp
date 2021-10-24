#include "stdafx.h"
#include "allTakenCourses.h"


allTakenCourses::allTakenCourses()
{
}

void allTakenCourses::takeCourse(Student s, Course *c)
{
	tc.push_back(new takingCourse(s, c));
}

bool allTakenCourses::deleteCourseForAstudent(Student s, Course *c)
{
	vector<takingCourse*>::iterator it;
	for (it = tc.begin(); it != tc.end(); it++)
	{
		if (((*it)->getstudent().getstnum() == s.getstnum()) && ((*it)->getcourse()->getcode() == c->getcode()))
		{
			tc.erase(it);
			return true;
		}
	}
	return false;
}

void allTakenCourses::deleteCourseForStudents(int code)
{
	vector<takingCourse*>::iterator it;
	while (IsInList_Course(code))
	{
		for (it = tc.begin(); it != tc.end(); it++)
		{
			if ((*it)->getcourse()->getcode() == code)
			{
				tc.erase(it);
				break;
			}
		}
	}
}

void allTakenCourses::deleteStudentCourses(int stnum)
{
	vector<takingCourse*>::iterator it;
	while (IsInList_Student(stnum))
	{
		for (it = tc.begin(); it != tc.end(); it++)
		{
			if ((*it)->getstudent().getstnum() == stnum)
			{
				tc.erase(it);
				break;
			}
			
		}
	}
}

void allTakenCourses::deleteInstructorCourses(int emID)
{
	vector<takingCourse*>::iterator it;
	while (IsInList_Instructor(emID))
	{
		for (it = tc.begin(); it != tc.end(); it++)
		{
			if ((*it)->getcourse()->getInstructor().getemID() == emID)
			{
				tc.erase(it);
				break;
			}
		}
	}
}

bool allTakenCourses::IsInList_Course(int code)
{
	vector<takingCourse*>::iterator it;
	for (it = tc.begin(); it != tc.end(); it++)
	{
		if ((*it)->getcourse()->getcode() == code)
		{
			return true;
		}
	}
	return false;
}

bool allTakenCourses::IsInList_Student(int stnum)
{
	vector<takingCourse*>::iterator it;
	for (it = tc.begin(); it != tc.end(); it++)
		{
			if ((*it)->getstudent().getstnum() == stnum)
			{
				return true;
			}
		}
	return false;
}

bool allTakenCourses::IsInList_Instructor(int emID)
{
	vector<takingCourse*>::iterator it;
	for (it = tc.begin(); it != tc.end(); it++)
	{
		if ((*it)->getcourse()->getInstructor().getemID() == emID)
		{
			return true;
		}
	}
	return false;
}

bool allTakenCourses::search(int stnum, int code)
{
	vector<takingCourse*>::iterator it;
	for (it = tc.begin(); it != tc.end(); it++)
	{
		if (((*it)->getstudent().getstnum() == stnum) && ((*it)->getcourse()->getcode() == code))
		{
			return true;
		}
	}
	return false;
}

void allTakenCourses::report(int a)
{
	vector<takingCourse*>::iterator it;
	vector<takingCourse*>::iterator it1;
	vector<takingCourse*>::iterator it2;
	vector<takingCourse*>::iterator it3;
	for (it = tc.begin(); it != tc.end(); it++)
	{
		if ((*it)->getstudent().getstnum() == a)
		{
			break;
		}
	}
	if (it != tc.end())
	{
		for (it1 = tc.begin(); it1 != tc.end(); it1++)
		{
			if ((*it1)->getstudent().getstnum() == (*it)->getstudent().getstnum())
			{
				(*it1)->getcourse()->print();
			}
		}
	}
	else {
		for (it2 = tc.begin(); it2 != tc.end(); it2++)
		{
			if (((*it2)->getcourse()->getcode() == a))
			{
				break;
			}
		}
		if (it2 != tc.end())
		{
			for (it3 = tc.begin(); it3 != tc.end(); it3++)
			{
				if ((*it3)->getcourse()->getcode() == (*it2)->getcourse()->getcode())
				{
					cout << (*it3)->getstudent();
				}
			}
		}
	}
	
}

allTakenCourses::~allTakenCourses()
{
	for (int i = 0; i < tc.size(); i++)
	{
		delete tc[i]->getcourse();
	}
}
