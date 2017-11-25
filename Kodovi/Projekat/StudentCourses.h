//============================================================================
// File Name   : StudentCourses.h
// Authors     : Milan Milovanovic
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef _STUDENTCOURSES_H_
#define _STUDENTCOURSES_H_

#include "Student.h"
#include "Courses.h"

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
	double get_final_score();
	void display();
};

#endif
