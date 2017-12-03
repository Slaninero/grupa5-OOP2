
//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : Milan Milovanovic
// Version     : 1.3
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

using namespace std;

#include "GroupOfStudents.h"
#include <string>
#include <fstream>

GroupOfStudents::GroupOfStudents(const vector<StudentCourses>& v)
{
	st_vec = v;
}

void GroupOfStudents::display() const
{
	for (StudentCourses sc : st_vec) {
		sc.get_student().display();
	}
}

void GroupOfStudents::display_highest() const
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

void GroupOfStudents::write_to_file()
{
	string path /*= "Test_output01.txt"*/;
	ofstream ofs(path);

	if (!ofs) cout << "Unable to open file!" << endl;

	for (int i = 0; i < st_vec.size(); i++) {
		ofs << st_vec[i];
	}	
}

void GroupOfStudents::add_member(StudentCourses sc)
{
	st_vec.insert(st_vec.end(), sc);
}
