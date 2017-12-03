//============================================================================
// File Name   : Menu.cpp
// Authors     : Kristina Djereg
// Version     : 1.4
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

using namespace std;

#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

Menu::Menu() {}

void Menu::display_menu() const
{
	cout << "\n[1] Prikazi osnovne informacije o autorima" << endl;
	cout << "[2] Ucitaj studente iz datoteke" << endl;
	cout << "[3] Prikazi informacije o studentu" << endl;
	cout << "[4] Prikazi studente sa najboljim prosekom" << endl;
	cout << "[5] Sortiraj" << endl;
	cout << "[6] Prikazi informacije o svim studentima" << endl;
	cout << "[7] Upisi studente u izlaznu datoteku" << endl;
	cout << "[8] Izlaz iz programa" << endl; 
}

void Menu::display_info() const
{
	cout << "\n- Informacije o autorima -" << endl;
	cout << "SW52/2016 Nemanja Jankovic" << endl;
	cout << "SW16/2016 Milan Milovanovic" << endl;
	cout << "SW36/2016 Kristina Djereg" << endl;
}

void Menu::read_students()
{
	string path = "../../Testovi/Test01.txt";
	ifstream ifs(path);

	if (!ifs) cout << "Unable to open file!" << endl;

	try {
		while (!ifs.eof()) {
			StudentCourses sc;
			ifs >> sc;

			Courses courses = sc.get_courses();
			courses.calc_final_score();
			courses.calc_letter_grade();
			sc.set_courses(courses);

			gs.add_member(sc);
		}
	}
	catch (const std::invalid_argument e) {
		cout << "Invalid input data format!" << endl;
	}

}

void Menu::display_students() const
{
	 gs.display();
}

void Menu::display_students_sorted() const
{
	gs.display_sorted();
}

void Menu::display_highest_score() const
{
	gs.display_highest();
}

void Menu::write()
{
	gs.write_to_file();
}