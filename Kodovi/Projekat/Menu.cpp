//============================================================================
// File Name   : Menu.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

using namespace std;

#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdlib>

Menu::Menu() {}

void Menu::display_menu() const
{
	cout << "\n[1] Prikazi osnovne informacije o autorima" << endl;
	cout << "[2] Ucitaj studente iz datoteke" << endl;
	cout << "[3] Prikazi informacije o svim studentima" << endl;
	cout << "[4] Sortiraj" << endl;
	cout << "[5] Prikazi studente sa najboljim prosekom" << endl;
	cout << "[6] Prikazi informacije o studentu" << endl;
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

void Menu::display_students() const
{
	//gs.display();
}

void Menu::display_students_sorted() const
{
	//gs.display_sorted();
}

void Menu::display_highest_score() const
{
	//gs.display_highest();
}

void Menu::write()
{
	//gs.write_to_file();
}