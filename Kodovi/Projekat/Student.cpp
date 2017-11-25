//============================================================================
// File Name   : Student.cpp
// Authors     : Nemanja Jankovic
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#include "Student.h"
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