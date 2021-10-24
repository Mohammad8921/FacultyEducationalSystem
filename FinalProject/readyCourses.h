#pragma once
#include "Course.h"
#include "graduateCourse.h"
#include "underGraduateCourse.h"
#include <iostream>
#include <vector>
using namespace std;
class readyCourses
{
public:
	readyCourses();
	void addCourse(Course*);
	void deleteCourse(int);
	void deleteInstructorCourses(int);
	bool IsInCoursesList_Instructor(int);
	void setData_GraduateCourse(vector<Instructor> &);
	void setData_UnderGraduateCourse(vector<Instructor> &);
	Course* search(int a);
	~readyCourses();
private:
	vector<Course*> c;

};

