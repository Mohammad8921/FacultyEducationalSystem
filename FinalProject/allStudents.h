#pragma once
#include <vector>
#include <iostream>
#include "Student.h"

using namespace std;

class allStudents
{
public:
	allStudents();
	void add(int, int, string, string, string, string, string, string, int);
	void setData_Student();
	bool removestudent(int);
	Student search(int);
	~allStudents();
private:
	vector<Student*> su;
};

