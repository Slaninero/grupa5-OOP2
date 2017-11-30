#include "GroupOfStudents.h"
//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : Milan Milovanovic
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

//  Your code starts here

GroupOfStudents::GroupOfStudents(const vector<StudentCourses>& v)
{
	st_vec = v;
}

void GroupOfStudents::display()
{
	for (StudentCourses sc : st_vec) {
		sc.get_student().display();
	}
}

void GroupOfStudents::display_highest()
{
	vector<Student> studenti;
	double max = 0;

	for (StudentCourses sc : st_vec) {
		double rezulat = sc.get_final_score();
		if (rezulat > max) {
			max = rezulat;
			studenti = { sc.get_student() };
		}
		else if (rezulat == max) {
			studenti.push_back(sc.get_student());
		}
	}

	for (Student s : studenti) {
		s.display();
	}
}
