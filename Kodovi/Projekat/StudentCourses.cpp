#include <iostream>
#include "StudentCourses.h"
//============================================================================
// File Name   : StudentCourses.cpp
// Authors     : Milan Milovanovic
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

using namespace std;

double StudentCourses::get_final_score()
{
	return courses.get_final_score();
}

void StudentCourses::display()
{
	cout << student.get_id() << " " << student.get_first_name() << " " << student.get_last_name() << " " << courses.get_final_score() << " " << courses.get_letter_grade() << endl;
}
