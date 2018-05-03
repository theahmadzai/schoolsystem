#include "Class.h"

Class::Class(): total_students(0)
{
}

Class::~Class()
{
}

void Class::addStudent()
{
	Student s;

	s.input();

	int size = ++total_students;

	Student *ns = new Student[size];

	for (int i = 0; i < size - 1; i++) {
		ns[i] = students[i];
	}

	ns[size - 1] = s;

	students = ns;
}

void Class::removeStudent(int id)
{
	int size = --total_students;

	Student *ns = new Student[size];

	for (int i = 0, j = 0; j <= size; i++,j++) {
		if (students[j].getId() == id) {
			if (size == j) {
				break;
			}
			j++;
		}
		ns[i] = students[j];
	}

	students = ns;
}

void Class::displayStudent(int n)
{
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| ID\t|" << " Name\t\t\t|" << " Father Name\t\t|" << " Age\t|" << " Phone\t\t|" << " Address\t\t\t|" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

	if (n != NULL) {
		students[n].display();
		return;
	}

	for (int i = 0; i < total_students; i++) {
		students[i].display();
	}
}