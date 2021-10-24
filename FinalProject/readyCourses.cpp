#include "stdafx.h"
#include "searchInstructor.h"
#include "readyCourses.h"


readyCourses::readyCourses()
{
}

void readyCourses::addCourse(Course *c)
{
	this->c.push_back(c);
}

void readyCourses::deleteCourse(int a)
{
	vector<Course*>::iterator it;
	for (it = c.begin(); it != c.end(); it++)
	{
		if ((*it)->getcode() == a)
		{
			break;
		}
	}
	c.erase(it);
}

void readyCourses::deleteInstructorCourses(int emID)
{
	vector<Course*>::iterator it;
	while (IsInCoursesList_Instructor(emID))
	{
		for (it = c.begin(); it != c.end(); it++)
		{
			if ((*it)->getInstructor().getemID() == emID)
			{
				c.erase(it);
				break;
			}
		}
	}
}

bool readyCourses::IsInCoursesList_Instructor(int emID)
{
	vector<Course*>::iterator it;
	for (it = c.begin(); it != c.end(); it++)
	{
		if ((*it)->getInstructor().getemID() == emID)
		{
			return true;
		}
	}
	return false;
}

void readyCourses::setData_GraduateCourse(vector<Instructor> &I)
{
	string courseName, eventPlace;
	int code, unit, capacity, emID;
	cout << "Enter course name: ";
	cin >> courseName;
	cout << "Enter code of course: ";
	cin >> code;
	cout << "Enter unit of course: ";
	cin >> unit;
	cout << "Enter capacity: ";
	cin >> capacity;
	cout << "Enter Instructor's employment ID that present this course: ";
	cin >> emID;
	cout << "Enter event place: ";
	cin >> eventPlace;
	if (searchInstructor(I, emID).getemID() == emID)
	{
		if (search(code)->getcode() == code)
		{
			cout << "The course with this code exists." << endl;
		}
		else {
			Instructor i = searchInstructor(I, emID);
			addCourse(new graduateCourse(i, capacity, courseName, code, unit, eventPlace, true));
			cout << "The course added to the list." << endl;
		}

	}
	else
	{
		cout << "Adding this course to list is not allowed because instructor with this emID doesn't exist." << endl;
	}
}

void readyCourses::setData_UnderGraduateCourse(vector<Instructor> &I)
{
	string courseName, eventPlace;
	int code, unit, emID;
	bool b;
	cout << "Enter course name: ";
	cin >> courseName;
	cout << "Enter code of course: ";
	cin >> code;
	cout << "Enter unit of course: ";
	cin >> unit;
	cout << "does this course need video projector?(enter 0 or 1) ";
	cin >> b;
	cout << "Enter Instructor's employment ID that present this course: ";
	cin >> emID;
	cout << "Enter event place: ";
	cin >> eventPlace;
	if (searchInstructor(I, emID).getemID() == emID)
	{
		if (search(code)->getcode() == code)
		{
			cout << "The course with this code exists." << endl;
		}
		else
		{
			Instructor i = searchInstructor(I, emID);
			addCourse(new underGraduateCourse(i, b, courseName, code, unit, eventPlace, false));
			cout << "The course added to the list." << endl;
		}

	}
}

Course* readyCourses::search(int a)
{
	vector<Course*>::iterator it;
	for (it = c.begin(); it != c.end(); it++)
	{
		if ((*it)->getcode() == a)
		{
			return (*it);
		}
	}
	return &Course();
	
}


readyCourses::~readyCourses()
{
	for (int i = 0; i < c.size(); i++)
	{
		delete c[i];
	}
}
