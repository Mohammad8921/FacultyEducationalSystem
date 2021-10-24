#include "stdafx.h"
#include "allStudents.h"

allStudents::allStudents()
{

}
void allStudents::add(int a, int b, string s1, string s2, string s3, string s4, string s5, string s6, int c)
{
	su.push_back(new Student(a, b, s1, s2, s3, s4, s5, s6, c));
}

void allStudents::setData_Student()
{
	string firstname;
	string lastname;
	string address;
	int phoneNumber;
	int stnum;
	int enteringYear;
	string fieldOfStudy;
	string Oriention;
	string grade;
	cout << "Enter student's firstname: ";
	cin >> firstname;
	cout << "Enter student's lastname: ";
	cin >> lastname;
	cout << "Enter student's address: ";
	cin >> address;
	cout << "Enter student's phone number: ";
	cin >> phoneNumber;
	cout << "Enter student number: ";
	cin >> stnum;
	cout << "Enter student entering year: ";
	cin >> enteringYear;
	cout << "Enter student's field of study: ";
	cin >> fieldOfStudy;
	cout << "Enter student's oriention: ";
	cin >> Oriention;
	cout << "Enter student's garde: ";
	cin >> grade;
	if (search(stnum).getstnum() == stnum)
	{
		cout << "The student with this student number exists." << endl;
	}
	else
	{
		add(stnum, enteringYear, fieldOfStudy, Oriention, grade, firstname, lastname, address, phoneNumber);
		cout << "The student added to the list." << endl;
	}
}

bool allStudents::removestudent(int a)
{
	vector<Student *>::iterator it;
	for (it = su.begin(); it != su.end(); it++)
	{
		if (((*it)->getstnum() == a))
		{
			su.erase(it);
			return true;
		}
	}
	return false;
}

Student allStudents::search(int a)
{
	vector<Student *>::iterator it;
	for (it = su.begin(); it != su.end(); it++)
	{
		if (((*it)->getstnum() == a))
		{
			return *(*it);
		}
	}
	return Student();
}


allStudents::~allStudents()
{
	for (int i = 0; i < su.size(); i++)
	{
		delete su[i];
	}
}
