
//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : Milan Milovanovic, Nemanja Jankovic
// Version     : 1.4
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
	cout << st_vec.size() << endl;
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
	string path;  // putanja ka fajlu za upis iste ekstenzije
	string path2; // putanja ka fajlu za upis tekstualne ekstenzije, koristi se pri binarnom zapisu

	if (__argc == 4) {
		// Ako je zadata izlazna datoteka
		path = __argv[3];
		string path_name = path.substr(0, path.find_last_of("/\\"));  // Direktorijum u kojem je datoteka
		string file_name = path.substr(path.find_last_of("/\\") + 1); // Ime datoteke
		path2 = path_name + "/\\" + file_name.substr(0, file_name.find_last_of(".") + 1) + "txt"; // Putanja za tekstualni fajl, pri binarnom zapisu
	} else {
		// Ako putanja nije zadata, fajl se kreira na istom mestu gde je pocetni iz kojeg se cita
		string file_path = __argv[1];
		string path_name = file_path.substr(0, file_path.find_last_of("/\\"));  // Direktorijum u kojem je datoteka
		string file_name = file_path.substr(file_path.find_last_of("/\\") + 1); // Ime datoteke
		// Fajl ce imati OUTPUT pridodat na ime fajla iz kojeg se citalo
		path = path_name + "/\\OUTPUT" + file_name;
		path2 = path_name + "/\\OUTPUT" + file_name.substr(0, file_name.find_last_of(".") + 1) + "txt"; // Putanja za tekstualni fajl, pri binarnom zapisu
	}

	string filetype = __argv[2];
	if (filetype == "T") {
		// Pisanje teksta
		ofstream ofs(path);

		if (!ofs) cout << "Unable to open file!" << endl;

		for (int i = 0; i < st_vec.size(); i++) {
			ofs << st_vec[i];
		}

		ofs.close();
	} else {
		// Binarno pisanje
		ofstream ofs(path, std::ios::binary);

		if (!ofs) cout << "Unable to open file!" << endl;

		for (int i = 0; i < st_vec.size(); i++) {
			double final_score = st_vec[i].get_courses().get_final_score();
			char grade_letter = st_vec[i].get_courses().get_letter_grade();

			ofs.write((char*)&st_vec[i].get_student().get_id(), sizeof(st_vec[i].get_student().get_id()));                 // Zapis id-a
			ofs.write((char*)&st_vec[i].get_student().get_first_name(), sizeof(st_vec[i].get_student().get_first_name())); // Zapis imena
			ofs.write((char*)&st_vec[i].get_student().get_last_name(), sizeof(st_vec[i].get_student().get_last_name()));   // Zapis prezimena
			ofs.write(reinterpret_cast<char*>(&final_score), sizeof(final_score));                                         // Zapis konacnog rezulata
			ofs.write((char*)&grade_letter, sizeof(grade_letter));                                                         // Zapis ocene
		}
		ofs.close();

		ofstream ofs2(path2);
		cout << path2 << endl;
		if (!ofs2) cout << "Unable to open file!" << endl;

		for (int i = 0; i < st_vec.size(); i++) {
			ofs2 << st_vec[i];
		}
		
		ofs2.close();
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
