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

void StudentCourses::display()
{
	cout << student.get_id() << " " << student.get_first_name() << " " << student.get_last_name() << " " << courses.get_final_score() << " " << courses.get_letter_grade() << endl;
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
