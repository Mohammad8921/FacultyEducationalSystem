#pragma once
#include "Student.h"
#include "readyCourses.h"
#include "allStudents.h"
#include "searchInstructor.h"
#include "takingCourse.h"

class allTakenCourses
{
public:
	allTakenCourses();
	void takeCourse(Student, Course *);
	bool deleteCourseForAstudent(Student , Course *);
	void deleteCourseForStudents(int);
	void deleteStudentCourses(int);
	void deleteInstructorCourses(int);
	bool IsInList_Course(int);
	bool IsInList_Student(int);
	bool IsInList_Instructor(int);
	bool search(int, int);
	void report(int);
	~allTakenCourses();
private:
	vector<takingCourse*> tc;
};

