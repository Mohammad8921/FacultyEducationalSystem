// FinalProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include "Instructor.h"
#include "searchInstructor.h"
#include "graduateCourse.h"
#include "underGraduateCourse.h"
#include "allTakenCourses.h"
#include <fstream>
#include <string>
#include "readyCourses.h"
#include "allStudents.h"

using namespace std;
void reading_data_from_file(allStudents &S, readyCourses &C, allTakenCourses &A, vector<Instructor> &I)
{
	char notation;
	string firstname;
	string lastname;
	string address;
	int phoneNumber;
	int stnum;
	int enteringYear;
	string fieldOfStudy;
	string Oriention;
	string grade;
	int emID;
	string Department;
	string LEC;
	string courseName;
	string eventplace;
	int code;
	int unit;
	int capacity;
	bool b;
	
	ifstream ifile("information.txt", ios::in);
	while (!ifile.eof())
	{
		ifile >> notation;
		if (notation == '*')
		{
			ifile >> firstname >> lastname >> address >> phoneNumber;
			ifile >> stnum >> enteringYear >> fieldOfStudy >> Oriention >> grade;
			S.add(stnum, enteringYear, fieldOfStudy, Oriention, grade, firstname, lastname, address, phoneNumber);

		}
		if (notation == '&')
		{
			ifile >> firstname >> lastname >> address >> phoneNumber;
			ifile >> emID >> Department >> LEC;
			I.push_back(Instructor(emID, Department, LEC, firstname, lastname, address, phoneNumber));
		}
		if (notation == '#')
		{
			ifile >> courseName >> code >> unit >> capacity >> emID >> eventplace;
			Instructor i = searchInstructor(I, emID);
			C.addCourse(new graduateCourse(i, capacity, courseName, code, unit, eventplace, true));
		}
		if (notation == '%')
		{
			ifile >> courseName >> code >> unit >> b >> emID >> eventplace;
			Instructor i = searchInstructor(I, emID);
			C.addCourse(new underGraduateCourse(i, b, courseName, code, unit, eventplace, false));
		}

	}
}
void setData_Instructor(vector<Instructor> &I)
{
	string firstname;
	string lastname;
	string address;
	string Department;
	string LEC;
	int phoneNumber, emID;
	cout << "Enter instructor's firstname: ";
	cin >> firstname;
	cout << "Enter instructor's lastname: ";
	cin >> lastname;
	cout << "Enter instructor's address: ";
	cin >> address;
	cout << "Enter instructor's phone number: ";
	cin >> phoneNumber;
	cout << "Enter instructor's emID: ";
	cin >> emID;
	cout << "Enter inscructor's department: ";
	cin >> Department;
	cout << "enter instructor's certificate: ";
	cin >> LEC;
	if (searchInstructor(I, emID).getemID() == emID)
	{
		cout << "The instructor with this employment ID exists." << endl;
	}
	else {
		I.push_back(Instructor(emID, Department, LEC, firstname, lastname, address, phoneNumber));
		cout << "The Instructor added to the list." << endl;
	}
}
int main()
{
	allStudents S;
	vector<Instructor> I;
	readyCourses C;
	allTakenCourses A;
	reading_data_from_file(S, C, A, I);
	int stnum, emID, code;
	char ch, ch1, ch2;
	vector<Instructor>::iterator it;
	cout << "1.Student\n" << "2.Instructor\n" << "3.Course\n" << "4.Takingcourse\n" << "5.Report courses that a student has taken it.\n" << "6.Report students that has taken a course.\n" << "7.Exit\n";
	while (true)
	{
		cout << "Enter a number of menu above: ";
		ch = _getch();
		while ((int(ch) - 48 > 7) || (int(ch) - 48) < 1)
		{
			ch = _getch();
		}
		cout << ch << endl;
		if (ch == '1')
		{
			cout << "1.Add\n" << "2.Remove\n" << "3.Search\n";
			ch1 = _getch();
			while ((int(ch1) - 48 > 3) || (int(ch1) - 48) < 1)
			{
				ch1 = _getch();
			}
			cout << ch1 << endl;
			if (ch1 == '1')
			{
				S.setData_Student();
			}
			if (ch1 == '2')
			{
				cout << "Enter student number: ";
				cin >> stnum;
				if (S.search(stnum).getstnum() == stnum)
				{
					S.removestudent(stnum);
					A.deleteStudentCourses(stnum);
					cout << "The student removed from the list." << endl;
				}
				else
				{
					cout << "There is no student with this student number." << endl;
				}

			}
			if (ch1 == '3')
			{
				cout << "Enter student number: ";
				cin >> stnum;
				if (S.search(stnum).getstnum() == stnum)
				{
					cout << S.search(stnum);
				}
				else
				{
					cout << "There is no student with this student number." << endl;
				}
			}
		}
		if (ch == '2')
		{
			cout << "1.Add\n" << "2.Remove\n" << "3.Search\n";
			ch1 = _getch();
			while ((int(ch1) - 48 > 3) || (int(ch1) - 48) < 1)
			{
				ch1 = _getch();
			}
			cout << ch1 << endl;
			if (ch1 == '1')
			{
				setData_Instructor(I);
			}
			if (ch1 == '2')
			{
				cout << "Enter instructor's emID: ";
				cin >> emID;
				for (it = I.begin(); it != I.end(); it++)
				{
					if (it->getemID() == emID)
					{
						I.erase(it);
						C.deleteInstructorCourses(emID);
						A.deleteInstructorCourses(emID);
						cout << "The instructor removed from the list." << endl;
						break;
					}
				}
			}
			if (ch1 == '3')
			{
				cout << "Enter instructor's emID: ";
				cin >> emID;
				if (searchInstructor(I, emID).getemID() == emID)
				{
					Instructor in = searchInstructor(I, emID);
					cout << in;
				}
				else
				{
					cout << "There is no instructor with this employment ID." << endl;
				}
			}
		}
		if (ch == '3')
		{
			cout << "1.Add\n" << "2.Remove\n" << "3.Search\n";

			ch1 = _getch();
			while ((int(ch1) - 48 > 3) || (int(ch1) - 48) < 1)
			{
				ch1 = _getch();
			}
			cout << ch1 << endl;
			if (ch1 == '1')
			{
				cout << "1.graduate course\n" << "2.undergraduate course\n";
				ch2 = _getch();
				while (ch2 != '1' && ch2 != '2')
				{
					ch2 = _getch();
				}
				cout << ch2 << endl;
				if (ch2 == '1')
				{
					C.setData_GraduateCourse(I);
				}
				if (ch2 == '2')
				{
					C.setData_UnderGraduateCourse(I);
				}
				else
				{
					cout << "Adding this course to list is not allowed because instructor with this emID doesn't exist." << endl;
				}
								
			}
			if (ch1 == '2')
			{
				cout << "Enter code of course: ";
				cin >> code;
				if (C.search(code)->getcode() == code)
				{
					C.deleteCourse(code);
					A.deleteCourseForStudents(code);
					cout << "The course removed from the list." << endl;
				}
				else
				{
					cout << "Or there is no course with this code or its instructor has been removed." << endl;
				}
			}
			if (ch1 == '3')
			{
				cout << "Enter code of course: ";
				cin >> code;
				if (C.search(code)->getcode() == code)
				{
					C.search(code)->print();
				}
				else
				{
					cout << "Or there is no course with this code or its instructor has been removed." << endl;
				}
			}
		}
			if (ch == '4')
			{
				cout << "Enter student number: ";
				cin >> stnum;
				cout << "enter code of course: ";
				cin >> code;
				if (S.search(stnum).getGrade() == "bsc" && C.search(code)->getgu() == true)
				{
					cout << "Undergraduate student is not authorized to take this course." << endl;
				}
				else
				{
					try
					{
						if (S.search(stnum).getstnum() != stnum || C.search(code)->getcode() != code)
						{
							throw exception();
						}
						else
						{
							if (A.search(stnum, code))
							{
								cout << "the course was alraedy taken for this student." << endl;
							}
							else
							{
								A.takeCourse(S.search(stnum), C.search(code));
								cout << "The course was taken for this student." << endl;
							}
						}

					}
					catch (exception e)
					{
						cout << "Entered information is invalid." << endl;
					}
				}
			}
			if (ch == '5')
			{
				cout << "Enter student number: ";
				cin >> stnum;
				if (S.search(stnum).getstnum() == stnum)
				{
					A.report(stnum);
				}
				else
				{
					cout << "There is no student with this student number." << endl;
				}
			}
			if (ch == '6')
			{
				cout << "enter code of course: ";
				cin >> code;
				if (C.search(code)->getcode() == code)
				{
					A.report(code);
				}
				else
				{
					cout << "There is no course with this code." << endl;
				}
			}
			if (ch == '7')
			{
				exit(0);
			}
		}
		return 0;
	}
	

