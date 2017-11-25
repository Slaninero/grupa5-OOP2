//============================================================================
// File Name   : Courses.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "Courses.h"
#include <string>
#include <iostream>

using namespace std;

static const double QUIZ_WEIGHT = 0.05;
static const double HOMEWORK_WEIGHT = 0.5;
static const double TEST_WEIGHT = 0.45;

double Courses::get_final_score() const {
	return final_score;
}

void Courses::display() const {
	cout << "Quizes : " << endl;
	for (int i : quiz)
		cout << i << ", ";

	cout << "\nHomework" << endl;
	for (int i : homework)
		cout << i << ", ";

	cout << "\nTests" << endl;
	for (int i : homework)
		cout << i << ", ";

	cout << "\n Final grade : " << final_score << endl;
	cout << "Grade letter : " << letter_grade << endl;
}

void Courses::calc_final_score()
{
	double quiz_score = 0, homework_score = 0, test_score = 0;

	for (int i : quiz)
		quiz_score += i;

	for (int i : homework)
		homework_score += i;

	for (int i : test)
		test_score += i;

	final_score = (quiz_score / (NUM_QUIZZES * 100)) * 100 * QUIZ_WEIGHT + (homework_score / (NUM_HW * 100)) * 100 * HOMEWORK_WEIGHT + (test_score / (NUM_TESTS * 100)) * 100 * TEST_WEIGHT;
}

void Courses::calc_letter_grade()
{
	if (final_score < 60)
		letter_grade = 'F';
	else if (final_score < 70)
		letter_grade = 'D';
	else if (final_score < 80)
		letter_grade = 'C';
	else if (final_score < 90)
		letter_grade = 'B';
	else
		letter_grade = 'A';
}
