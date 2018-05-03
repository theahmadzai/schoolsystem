#include <iostream>
#include <string>
#include "Student.h"
#include "Teacher.h"
#include "Class.h"
#include "Admin.h"

using namespace std;

int main()
{
	Class c[10];
	int cn = 3;

	char option;

	do {
		system("Color F9");
		cout << "------------------------------" << endl;
		cout << "S - Student Info" << endl;
		cout << "T - Teacher Teacher Info" << endl;
		cout << "------------------------------" << endl;

		cin >> option;

		switch (option) {
			case 's':
		        do {
					cout << "------------------------------" << endl;
					cout << "A - Add Student" << endl;
					cout << "R - Remove Student" << endl;
					cout << "D - Display Students" << endl;
					cout << "------------------------------" << endl;

					cin >> option;

					switch (option) {
						case 'a':
							c[cn].addStudent();
						break;
						case 'r':
							int a;
							cout << "Enter id: ";  cin >> a;
							c[cn].removeStudent(a);
						break;
						case 'd':
							c[cn].displayStudent();
						break;
						default:
							cout << "<--------" << endl;
						break;
					}
				} while (option != 'b');
			break;
			case 't':
				do {
					cout << "------------------------------" << endl;
					cout << "A - Add Teacher" << endl;
					cout << "R - Remove Teacher" << endl;
					cout << "D - Display Teacher" << endl;
					cout << "------------------------------" << endl;

					cin >> option;

					switch (option) {
					case 'a':
						c[cn].addTeacher();
						break;
					case 'r':
						int a;
						cout << "Enter id: ";  cin >> a;
						c[cn].removeTeacher(a);
						break;
					case 'd':
						c[cn].displayTeacher();
						break;
					default:
						cout << "<--------" << endl;
					break;
					}
				} while (option != 'b');
			break;
		}

	} while (option != 'c');



	system("pause");
	return 0;
}
