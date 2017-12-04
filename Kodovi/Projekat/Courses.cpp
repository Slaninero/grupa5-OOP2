//============================================================================
// File Name   : Courses.cpp
// Authors     : You
// Version     : 1.2
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

char Courses::get_letter_grade() const {
	return letter_grade;
}

void Courses::display() const {
	cout << "Quizes : " << endl;
	for (int i : quiz)
		cout << i << ", ";

	cout << "\nHomework" << endl;
	for (int i : homework)
		cout << i << ", ";

	cout << "\nTests" << endl;
	for (int i : test)
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

	final_score = 100 * ((quiz_score * QUIZ_WEIGHT / (NUM_QUIZZES * 100)) + (homework_score * HOMEWORK_WEIGHT / (NUM_HW * 100)) + (test_score * TEST_WEIGHT / ((NUM_TESTS * 100))));
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

istream & operator>>(istream & in, Courses & c)
{
	int i = 0;
	int num = 0;

	while (i < 6) {
		if (!(in >> num)) {
			// nije double
			throw std::invalid_argument("Invalid input format!");
		}
		else {
			if (num < 0 || num > 100) {
				// nalazi se izvan opsega
				throw std::invalid_argument("Invalid input format!");
		}
			c.homework[i] = num;
		}
		i++;
	}

	if (in.peek() != '\n') {
		// proverava da li je kraj reda
		throw std::invalid_argument("Invalid input fomrat!");
	}
	
	i = 0;

	while (i < 4) {
		if (!(in >> num)) {
			throw std::invalid_argument("Invalid input format!");
		}
		else {
			if (num < 0 || num > 100) {
				throw std::invalid_argument("Invalid input format!");
			}
			c.test[i] = num;
		}
		i++;
	}

	if (in.peek() != '\n') {
		throw std::invalid_argument("Invalid input fomrat!");
	}

	i = 0;

	while (i < 10) {
		if (!(in >> num)) {
			throw std::invalid_argument("Invalid input format!");
		}
		else {
			if (num < 0 || num > 100) {
				throw std::invalid_argument("Invalid input format!");
			}
			c.quiz[i] = num;
		}
		i++;
	}

	if (!in.eof() && in.peek() != '\n') {
		// proverava da li je kraj reda
		throw std::invalid_argument("Invalid input fomrat!");
	}

	return in;
}

ostream & operator<<(ostream & out, Courses& c)
{
	out << c.get_final_score() << " " << c.get_letter_grade();
	return out;
}
