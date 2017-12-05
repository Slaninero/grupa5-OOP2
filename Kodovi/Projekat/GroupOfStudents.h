//============================================================================
// File Name   : GroupOfStudents.h
// Authors     : Milan Milovanovic
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef GROUPOFSTUDENTS_H_
#define GROUPOFSTUDENTS_H_

#include <vector>
#include "StudentCourses.h"

using std::vector;

class GroupOfStudents
{
private:
	vector<StudentCourses> st_vec;
	void search_for_highest(vector<int>& indices_max) const; // utility

public:
	GroupOfStudents() {}
	GroupOfStudents(const vector< StudentCourses >& v);
	void display() const;
	void display_sorted() const;
	void display_highest() const;
	void write_to_file();
	const vector<StudentCourses>& get_student_courses() const { return st_vec; }
	vector<StudentCourses> merge(vector<StudentCourses> left, vector<StudentCourses> right, int criteria) const;
	vector<StudentCourses> mergeSort(vector<StudentCourses> vec, int criteria) const;
	void add_member(StudentCourses sc);
};


#endif /*GROUPOFSTUDENTS_H_*/
