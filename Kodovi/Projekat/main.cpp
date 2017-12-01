//============================================================================
// File Name   : main.cpp 
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "Menu.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{

	Student A = Student("Ana", "Antic", "SW 52-2016");
	Student A1 = Student("Aleksa", "Aleksic", "SW 90-2008");
	Student B = Student();
	A.display();
	cout << A.get_first_name() << endl;
	cout << A.get_last_name() << endl;
	cout << A.get_id() << endl;
	B.display();

	Courses C = Courses();
	C.display();

	vector<int> quiz1 = { 75, 75, 75, 75, 75, 75, 100, 75, 100, 100 };
	vector<int> home1 = { 100, 75, 50, 50, 75, 50 };
	vector<int> test1 = { 75, 12, 75, 100 };

	Courses D = Courses(quiz1, home1, test1);
	D.calc_final_score();
	D.calc_letter_grade();
	D.display();

	StudentCourses sc = StudentCourses(A, D);
	StudentCourses sc2 = StudentCourses(A1, D);
	StudentCourses sc3 = StudentCourses(B, C);
	vector<StudentCourses> v;
	v.push_back(sc3);
	v.push_back(sc2);
	v.push_back(sc);
	GroupOfStudents gos = GroupOfStudents(v);
	cout << gos.get_student_courses().size() << endl;
	cout << &v << endl << &gos.get_student_courses() << endl;
	gos.display();

	cout << "Display najboljih" << endl;
	gos.display_highest();


	// Zakomentariasan je main.cpp, StudentCourses.cpp funkcija i konstante u Courses.cpp

	//Menu m;
	//int option;
	//m.display_menu();
	//
	//do
	//{
	//	cout << "> ";
	//	while (!(cin >> option) || option < 1 || option > Menu::EXIT)
	//	{
	//		if (cin.fail())	// we found something that wasn’t an integer
	//		{
	//			cin.clear();	// we’d like to look at the characters
	//			char ch;
	//			while (cin>>ch && !isdigit(ch))
	//			{
	//				cerr << "Invalid input; please try again" << endl;
	//				cout << "> ";
	//			}
	//			cin.unget();
	//		} 
	//		else
	//		{	// option < 1 || option > Menu::EXIT */
	//			cerr << "Invalid input; please try again" << endl;
	//			cout << "> ";
	//		}
	//	}
	//		
	//	switch(option)
	//	{
	//	case Menu::INFO:
	//		m.display_info();
	//		break;
	//	case Menu::READ_FILE:
	//		try
	//		{
	//			m.read_students();
	//		} catch (const Menu::InvalidFile& excp)
	//		{
	//			cerr << excp.what() << endl;
	//		} catch (const Menu::InvalidData& excp)
	//		{
	//			cerr << excp.what() << endl;
	//		}
	//		break;
	//	case Menu::DISPLAY:
	//		m.display_students();
	//		break;
	//	case Menu::DISPLAY_SORTED:
	//		m.display_students_sorted();
	//		break;   
	//	case Menu::HIGHEST:
	//		m.display_highest_score();
	//		break;
	//	}
	//	m.display_menu();
	//} while (option != Menu::EXIT);
	return 0;
}
