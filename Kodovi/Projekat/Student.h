//============================================================================
// File Name   : Student.h
// Authors     : Nemanja Jankovic
// Version     : 1.2
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Student
{
private:
	string firstName;
	string lastName;
	string ID;

public:
	Student();
	Student(string firstName, string lastName, string ID);
	string get_first_name() const;
	string get_last_name() const;
	string get_id() const;
	void display() const;

	friend istream& operator>>(istream& in, Student& s);
};

istream& operator>>(istream& in, Student& s);
ostream& operator<<(ostream& out, Student& s);

#endif /*STUDENT_H_*/
