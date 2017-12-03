
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

void GroupOfStudents::display_sorted() const
{
	const vector<StudentCourses> sorted = mergeSort(st_vec, 0); // 0,1 - sorting criteria
	for (int i = 0; i < sorted.size(); i++) {
		sorted.at(i).display();
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

vector<StudentCourses> GroupOfStudents::merge(vector<StudentCourses> left, vector<StudentCourses> right, int criteria) const {
	vector<StudentCourses> ret(left.size() + right.size()); // construct vector with left.size() + right.size() elements assigned to -1
	int left_position = 0;
	int right_position = 0;
	int ret_position = 0;
	while (left_position < left.size() && right_position < right.size()) {
		StudentCourses left_value = left[left_position];
		StudentCourses right_value = right[right_position];
		if (left_value.lessThan(right_value, criteria)) {
			ret[ret_position++] = left_value;
			left_position++;
		}
		else {
			ret[ret_position++] = right_value;
			right_position++;
		}
	}
	while (left_position < left.size()) {
		ret[ret_position++] = left[left_position++];
	}
	while (right_position < right.size()) {
		ret[ret_position++] = right[right_position++];
	}
	return ret;
}

vector<StudentCourses> GroupOfStudents::mergeSort(vector<StudentCourses> vec, int criteria) const {
	if (vec.size() < 2) {
		return vec;
	}
	int middle = vec.size() / 2;
	vector<StudentCourses> left(vec.begin(), vec.begin() + middle);
	vector<StudentCourses> right(vec.begin() + middle, vec.end());

	left = mergeSort(left, criteria);
	right = mergeSort(right, criteria);
	std::vector<StudentCourses> ret = merge(left, right, criteria);
	return ret;
}
