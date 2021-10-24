#pragma once
#include <vector>
#include <iostream>
#include "Instructor.h"
using namespace std;

inline Instructor searchInstructor(vector<Instructor> IN, int em)
{
	for (int j = 0; j < IN.size(); j++)
	{
		if (IN[j].getemID() == em)
		{
			return IN[j];
		}
	}
	return Instructor();
}