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
	student.display();
	cout << "Final score: " << courses.get_final_score() << endl;
	cout << "Grade: " << courses.get_letter_grade() << endl;
}
