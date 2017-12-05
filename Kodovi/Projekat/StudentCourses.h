//============================================================================
// File Name   : StudentCourses.h
// Authors     : Milan Milovanovic
// Version     : 1.3
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef _STUDENTCOURSES_H_
#define _STUDENTCOURSES_H_

#include "Student.h"
#include "Courses.h"

using std::istream;
using std::ostream;

class StudentCourses
{
private:
	Student student;
	Courses courses;
public:
	StudentCourses() {};
	StudentCourses(Student student, Courses courses) : student(student), courses(courses) {};
	Student get_student() const { return student; }
	Courses get_courses() const { return courses; }
	void set_courses(Courses c);
	double get_final_score();
	void display() const;
	bool lessThan(StudentCourses sc, int criteria);
	friend istream& operator>>(istream& in, StudentCourses& sc);
};

istream& operator>>(istream& in, StudentCourses& sc);
ostream& operator<<(ostream& out, StudentCourses& sc);

#endif
