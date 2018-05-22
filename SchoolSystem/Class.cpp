#include "Class.h"

int Class::total_classes = 0;

Class::Class() : total_students(0), total_teachers(0), id(++total_classes), fee(0), total_fee(0)
{
}

Class::Class(string _name, unsigned int _fee) : name(_name), fee(_fee), id(++total_classes)
{
}

Class::~Class()
{
}

void Class::addStudent()
{
    total_fee += fee;

    Student s;

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
    int const size = total_students--;

    Student *temp = new Student[size - 1];

    for (int i = 0, j = 0; j < size; i++, j++) {
        if (students[j].getId() == id) {
            if (size - 1 == j) {
                break;
            }
            j++;
        }
        temp[i] = students[j];
    }

    students = temp;
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

    int const size = total_students;

    for (int i = 0; i < size; i++) {
        students[i].display();
    }
}

void Class::addTeacher()
{
    Teacher t;

    int size = ++total_teachers;

    Teacher *temp = new Teacher[size];

    for (int i = 0; i < size - 1; i++) {
        temp[i] = teachers[i];
    }

    temp[size - 1] = t;

    teachers = temp;
}

void Class::removeTeacher(int id)
{
    int const size = total_teachers--;

    Teacher *temp = new Teacher[size - 1];

    for (int i = 0, j = 0; j < size; i++, j++) {
        if (teachers[j].getId() == id) {
            if (size - 1 == j) {
                break;
            }
            j++;
        }
        temp[i] = teachers[j];
    }

    teachers = temp;
}

void Class::displayTeacher(int n)
{
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| ID\t|" << " Name\t\t\t|" << " Father Name\t\t|" << " Age\t|" << " Phone\t\t|" << " Address\t\t\t|" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

    if (n != NULL) {
        teachers[n].display();
        return;
    }

    for (int i = 0; i < total_teachers; i++) {
        teachers[i].display();
    }
}

void Class::info()
{
    cout << "| " << id << " \t\t| " << name << " \t\t| " << total_students << " \t\t| " << total_teachers << " \t\t| " << fee << " \t\t| " << total_fee << " \t\t|"<< endl;
    cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
}

int Class::getFee()
{
    return fee;
}

void Class::setFee(unsigned int _fee)
{
    fee = _fee;
}

int Class::getTotalFee()
{
    return total_fee;
}

int Class::getId()
{
    return id;
}

char Class::panel(char ch)
{
    cout << endl << endl;
    cout << "\t\t\t+---------------------------------+" << endl;
    cout << "\t\t\t|                                 |" << endl;
    cout << "\t\t\t|       R  -  CLASS INFO          |" << endl;
    cout << "\t\t\t|       F  -  SET FEE             |" << endl;
    cout << "\t\t\t|       Q  -  ADD STUDENT         |" << endl;
    cout << "\t\t\t|       W  -  REMOVE STUDENT      |" << endl;
    cout << "\t\t\t|       E  -  DISPLAY STUDENTS    |" << endl;
    cout << "\t\t\t|       A  -  ADD TEACHER         |" << endl;
    cout << "\t\t\t|       S  -  REMOVE TEACHER      |" << endl;
    cout << "\t\t\t|       D  -  DISPLAY TEACHERS    |" << endl;
    cout << "\t\t\t|                                 |" << endl;
    cout << "\t\t\t+---------------------------------+" << endl;
    cout << "\t\t\t>> "; cin >> ch;

    system("cls");
    return ch;
}
