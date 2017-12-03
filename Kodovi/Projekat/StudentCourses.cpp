#include <iostream>
#include "StudentCourses.h"
//============================================================================
// File Name   : StudentCourses.cpp
// Authors     : Milan Milovanovic
// Version     : 1.3
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

using namespace std;

void StudentCourses::set_courses(Courses c)
{
	courses = c;
}

double StudentCourses::get_final_score()
{
	return courses.get_final_score();
}

void StudentCourses::display() const
{
	cout << student.get_id() << " " << student.get_first_name() << " " << student.get_last_name() << " " << courses.get_final_score() << " " << courses.get_letter_grade() << endl;
}

bool StudentCourses::lessThan(StudentCourses sc, int criteria)
{
	string s1;
	string s2;
	switch (criteria)
	{
	case 0: // prezime, ime, id
		s1 = student.get_last_name() + student.get_first_name() + student.get_id();
		s2 = sc.get_student().get_last_name() + sc.get_student().get_first_name() + sc.get_student().get_id();
		break;
	case 1: // id
		s1 = student.get_id();
		s2 = sc.get_student().get_id();
		break;
	default:
		break;
	}
	if (s1 < s2) {
		return true;
	}
	else {
		return false;
	}
}

istream & operator>>(istream & in, StudentCourses& sc)
{
	in >> sc.student;
	in >> sc.courses;
	return in;
}

ostream & operator<<(ostream & out, StudentCourses& sc)
{
	out << sc.get_student() << " " << sc.get_courses() << endl;
	return out;
}
