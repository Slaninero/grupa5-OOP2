//============================================================================
// File Name   : Menu.cpp
// Authors     : Kristina Djereg, Nemanja Jankovic
// Version     : 1.5
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

void write_input_file(GroupOfStudents& gs) {
	string file_path = __argv[1];
	string path_name = file_path.substr(0, file_path.find_last_of("/\\"));  // Direktorijum u kojem je fajl
	string file_name = file_path.substr(file_path.find_last_of("/\\") + 1); // Ime fajla zajedno sa ekstenzijom
	string path = path_name + "/\\" + file_name.substr(0, file_name.find_last_of(".") + 1) + "bin"; // Konacno ime fajla

	ofstream ofs(path, std::ios::binary);
	if (!ofs) cout << "Unable to open file!" << endl;
	
	for (StudentCourses sc : gs.get_student_courses()) {
		Student student = sc.get_student();
		Courses courses = sc.get_courses();

		// Prvo se snima broj znakova koji se ucitavaju, nakon toga znakovi u stringu
		// Snimanje imena studenta
		unsigned size = student.get_first_name().size();
		ofs.write(reinterpret_cast<char *>(&size), sizeof(unsigned));
		ofs.write(student.get_first_name().c_str(), size * sizeof(char));

		// Snimanje prezimena studenta
		size = student.get_last_name().size();
		ofs.write(reinterpret_cast<char *>(&size), sizeof(unsigned));
		ofs.write(student.get_last_name().c_str(), size * sizeof(char));

		// Snimanje id-a studenta
		size = student.get_id().size();
		ofs.write(reinterpret_cast<char *>(&size), sizeof(unsigned));
		ofs.write(student.get_id().c_str(), size * sizeof(char));

		// Snimanje domacih
		for (int i : courses.get_homework()) {
			ofs.write((char*)&i, sizeof(int));
		}

		// Snimanje testova
		for (int i : courses.get_test()) {
			ofs.write((char*)&i, sizeof(int));
		}

		// Snimanje kvizova
		for (int i : courses.get_quiz()) {
			ofs.write((char*)&i, sizeof(int));
		}

	}

	ofs.close();
}

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
	string path = __argv[1];
	string file_type = __argv[2];
	if (file_type == "T") {
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

			write_input_file(gs); // Funkcija za racunarsko generisanje ulazne binarne datoteke, radi konstruisanja testova
		}
		catch (const std::invalid_argument e) {
			cout << "Invalid input data format!" << endl;
		}
	}
	else {
		ifstream ifs(path, std::ios::binary);

		if (!ifs) cout << "Unable to open file!" << endl;
		Student student;
		Courses courses;
		vector<StudentCourses> sc_v;

		try {
			while (!ifs.eof()) {
				
				// Ucitavanje imena studenta
				// Ucitavanje snimljenje duzine imena
				unsigned stringsize;
				ifs.read(reinterpret_cast<char *>(&stringsize), sizeof(unsigned));
				// Ucitavanje niza znakova koje cini ime studenta
				vector<char> temp1(stringsize);
				ifs.read(reinterpret_cast<char *>(&temp1[0]), stringsize * sizeof(char));
				string student_name(temp1.begin(), temp1.end());

				// Ucitavanje prezimena studenta
				// Ucitavanje snimljenje duzine prezimena
				unsigned stringsize2;
				ifs.read(reinterpret_cast<char *>(&stringsize2), sizeof(unsigned));
				// Ucitavanje niza znakova koje cini prezime studenta
				vector<char> temp2(stringsize2);
				ifs.read(reinterpret_cast<char *>(&temp2[0]), stringsize2 * sizeof(char));
				string student_lastname(temp2.begin(), temp2.end());

				// Ucitavanje id-a studenta
				// Ucitavanje snimljenje duzine id-a
				unsigned stringsize3;
				ifs.read(reinterpret_cast<char *>(&stringsize3), sizeof(unsigned));
				// Ucitavanje niza znakova koje cini id studenta
				vector<char> temp3(stringsize3);
				ifs.read(reinterpret_cast<char *>(&temp3[0]), stringsize3 * sizeof(char));
				string student_id(temp3.begin(), temp3.end());

				Student stud = Student(student_name, student_lastname, student_id);


				// Ucitavanje vektora za domaci
				vector<int> homework_vector;
				int read;
				for (int i = 0; i < 6; i++) {
					ifs.read((char*)(&read), sizeof(int));
					homework_vector.push_back(read);
				}

				// Ucitavanje vektora za testove
				vector<int> test_vector;
				for (int i = 0; i < 4; i++) {
					ifs.read((char*)(&read), sizeof(int));
					test_vector.push_back(read);
				}

				// Ucitavanje vektora za kvizove
				vector<int> quiz_vector;
				for (int i = 0; i < 10; i++) {
					ifs.read((char*)(&read), sizeof(int));
					quiz_vector.push_back(read);
				}

				Courses course = Courses(quiz_vector, homework_vector, test_vector);
				course.calc_final_score();
				course.calc_letter_grade();

				sc_v.push_back(StudentCourses(stud, course));
			}

			// Brisanje lose unetog poslednjeg clana
			for(int i = 0; i < sc_v.size() - 1; i++)
				gs.add_member(sc_v[i]);

			ifs.close();
		}
		catch (const std::invalid_argument e) {
			cout << "Invalid input data format!" << endl;
		}
	}
}

void Menu::display_students() const
{
	 gs.display();
}

void Menu::display_students_sorted() const
{
	//gs.display_sorted();
}

void Menu::display_highest_score() const
{
	gs.display_highest();
}

void Menu::write()
{
	gs.write_to_file();
}

