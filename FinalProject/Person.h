#pragma once
#include <string>
#include <iostream>
using namespace std;
class Person
{
	
public:
	Person();
	Person(string, string, string, int);
	string getfirstname();
	string getlastname();
	~Person();
protected:
	string firstname;
	string lastname;
	string address;
	int PhoneNumber;
};

