//============================================================================
// File Name   : Student.cpp
// Authors     : Nemanja Jankovic
// Version     : 1.2
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#include "Student.h"
#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student() {};

Student::Student(string first, string last, string index) {
	firstName = first;
	lastName = last;
	ID = index;
}

string Student::get_first_name() const {
	return firstName;
}

string Student::get_last_name() const {
	return lastName;
}

string Student::get_id() const {
	return ID;
}

void Student::display() const {
	cout << "Student : " << firstName << " " << lastName << " " << ID << endl;
}

istream& operator>>(istream& in, Student& s)
{
	in >> s.firstName >> s.lastName >> s.ID;

	if (in.peek() != '\n') {
		// proverava da li je kraj reda
		throw Menu::InvalidData();
	}

	return in;
}

ostream & operator<<(ostream & out, Student& s)
{
	out << s.get_id() << " " << s.get_first_name() << " " << s.get_last_name();
	return out;
}
