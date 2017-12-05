//============================================================================
// File Name   : main.cpp 
// Authors     : You
// Version     : 1.4
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "Menu.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 3 || argc > 4) { // argv[0] - ime programa, argv[1] - putanja do datoteke, argv[2] - tip podatka (B/T), argv[3] - putanja izlazne datoteke

		cout << "Neispravno pokretanje programa." << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Parametri pri pokretanju : " << endl;
		cout << "\t - Putanja fajla iz kojeg se ucitava" << endl;
		cout << "\t - Tip fajla pri ucitavanju (B / T)" << endl;
		cout << "\t - Putanja fajla u koji se ucitava (Nije neophodno)" << endl;
		cout << "-------------------------------------------" << endl;

	} else {
		Menu m;
		int option;
		m.display_menu();

		do
		{
			cout << "> ";
			while (!(cin >> option) || option < 1 || option > Menu::EXIT)
			{
				if (cin.fail())	// we found something that wasn’t an integer
				{
					cin.clear();	// we’d like to look at the characters
					char ch;
					while (cin >> ch && !isdigit(ch))
					{
						cerr << "Invalid input; please try again" << endl;
						cout << "> ";
					}
					cin.unget();
				}
				else
				{
					if (option < 1 || option > Menu::EXIT) {
						cerr << "Invalid input; please try again" << endl;
						cout << "> ";
					}
				}
			}

			switch (option)
			{
			case Menu::INFO:
				m.display_info();
				break;
			case Menu::READ_FILE:
				try
				{
					m.read_students();
				}
				catch (const Menu::InvalidFile& excp)
				{
					cerr << excp.what() << endl;
				}
				catch (const Menu::InvalidData& excp)
				{
					cerr << excp.what() << endl;
				}
				break;
			case Menu::DISPLAY_ALL:
				m.display_students();
				break;
			case Menu::DISPLAY_SORTED:
				m.display_students_sorted();
				break;
			case Menu::HIGHEST:
				m.display_highest_score();
				break;
			case Menu::DISPLAY_ONE:
				m.display_one_stud();
				break;
			case Menu::WRITE_FILE:
				m.write();
				break;
			}
			m.display_menu();
		} while (option != Menu::EXIT);
	}

	return 0;
}
