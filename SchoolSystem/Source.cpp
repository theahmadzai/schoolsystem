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
					}
				} while (option != 'c');
			break;
			case 't':
				cout << 3;
			break;
		}

	} while (option != 'c');



	system("pause");
	return 0;
}
