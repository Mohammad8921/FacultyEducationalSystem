#include "stdafx.h"
#include "Person.h"


Person::Person()
{
}

Person::Person(string f, string l, string a, int p)
{
	firstname = f;
	lastname = l;
	address = a;
	PhoneNumber = p;
}

string Person::getfirstname()
{
	return firstname;
}

string Person::getlastname()
{
	return lastname;
}


Person::~Person()
{
}

