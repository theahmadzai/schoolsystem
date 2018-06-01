#include "Class.h"

int Class::total_classes = 0;

Class::Class() : fee(0), total_students(0), total_teachers(0) {}

Class::Class(const char *_name, unsigned int _fee) : id(++total_classes), fee(_fee), total_students(0), total_teachers(0)
{
    for (int i = 0; i < 10; i++) {
        name[i] = _name[i];
    }
}

Class::~Class() {}

void Class::panel()
{
    readData(students);
    readData(teachers);

    char ch = NULL;
    do {
        cout << endl << endl;
        cout << "\t\t\t+---------------------------------+---------------------+" << endl;
        cout << "\t\t\t|                                 |                     |" << endl;
        cout << "\t\t\t|       OPTIONS                   |  INFO               |" << endl;
        cout << "\t\t\t|                                 |                     |" << endl;
        cout << "\t\t\t|       B  -  MAIN MENU           |                     |" << endl;
        cout << "\t\t\t|       Q  -  ADD STUDENT         |  ID: \t" << getId() << "\t|" << endl;
        cout << "\t\t\t|       W  -  REMOVE STUDENT      |  NAME: \t" << getName() << "\t|" << endl;
        cout << "\t\t\t|       E  -  DISPLAY STUDENTS    |  FEE: \t" << getFee() << "\t|" << endl;
        cout << "\t\t\t|       A  -  ADD TEACHER         |  INCOME: \t" << getTotalFee() << "\t|" << endl;
        cout << "\t\t\t|       S  -  REMOVE TEACHER      |  STUDENTS: \t" << getTotalStudents() << "\t|" << endl;
        cout << "\t\t\t|       D  -  DISPLAY TEACHERS    |  TEACHERS: \t" << getTotalTeachers() << "\t|" << endl;
        cout << "\t\t\t|                                 |                     |" << endl;
        cout << "\t\t\t+---------------------------------+---------------------+" << endl;
        cout << "\t\t\t>> "; cin >> ch;

        system("cls");

        switch (ch)
        {
        case 'q':
        case 'Q':
            addStudent();
            break;
        case 'w':
        case 'W':
            int sid;
            cout << "Enter student id:"; cin >> sid;
            removeStudent(sid);
            break;
        case 'e':
        case 'E':
            displayStudent();
            break;
        case 'a':
        case 'A':
            addTeacher();
            break;
        case 's':
        case 'S':
            int tid;
            cout << "Enter Teacher id:"; cin >> tid;
            removeTeacher(tid);
            break;
        case 'd':
        case 'D':
            displayTeacher();
            break;
        }

    } while (ch != 'b' && ch != 'B');
}

void Class::addStudent()
{
    Student s;
    s.input();

    int size = ++total_students;

    Student *temp = new Student[size];

    for (int i = 0; i < size - 1; i++) {
        temp[i] = students[i];
    }

    temp[size - 1] = s;

    students = temp;

    writeData(s);
}

void Class::removeStudent(unsigned int _id)
{
    bool exists = false;
    int index;

    for (int i = 0; i < total_students; i++) {
        if (students[i].getId() == _id) {
            exists = true;
            index = i;
        }
    }

    if (exists == false) {
        cout << "Students does't exist!" << endl;
        return;
    }

    Student *temp = new Student[--total_students];

    for (int i = 0, j = 0; j <= total_students; i++, j++) {
        if (i == index) {
            if (j == total_students) {
                break;
            }
            j++;
        }
        temp[i] = students[j];
    }

    students = temp;

    rewriteData(students);
}

void Class::displayStudent()
{
    cout << "+-------------------------------------" << endl;
    cout << "| Total Students: " << getTotalStudents() << endl;
    for (int i = 0; i < getTotalStudents(); i++) {
        cout << "+------------------------------------" << endl;
        cout << "| ID: \t\t\t" << students[i].getId() << endl;
        cout << "| Name: \t\t" << students[i].getName() << endl;
        cout << "| Father Name: \t\t" << students[i].getFatherName() << endl;
        cout << "| Age: \t\t\t" << students[i].getAge() << endl;
        cout << "| Phone: \t\t" << students[i].getPhone() << endl;
        cout << "| Address: \t\t" << students[i].getAddress() << endl;
    }
    cout << "+-------------------------------------" << endl;
}

void Class::addTeacher()
{
    Teacher t;
    t.input();

    int size = ++total_teachers;

    Teacher *temp = new Teacher[size];

    for (int i = 0; i < size - 1; i++) {
        temp[i] = teachers[i];
    }

    temp[size - 1] = t;

    teachers = temp;

    writeData(t);
}

void Class::removeTeacher(unsigned int _id)
{
    bool exists = false;
    int index;

    for (int i = 0; i < total_teachers; i++) {
        if (teachers[i].getId() == _id) {
            exists = true;
            index = i;
        }
    }

    if (exists == false) {
        cout << "Teacher does't exist!" << endl;
        return;
    }

    Teacher *temp = new Teacher[--total_teachers];

    for (int i = 0, j = 0; j <= total_teachers; i++, j++) {
        if (i == index) {
            if (j == total_teachers) {
                break;
            }
            j++;
        }
        temp[i] = teachers[j];
    }

    teachers = temp;

    rewriteData(teachers);
}

void Class::displayTeacher()
{
    cout << "+-------------------------------------" << endl;
    cout << "| Total Students: " << getTotalTeachers() << endl;
    for (int i = 0; i < getTotalTeachers(); i++) {
        cout << "+------------------------------------" << endl;
        cout << "| ID: \t\t\t" << teachers[i].getId() << endl;
        cout << "| Name: \t\t" << teachers[i].getName() << endl;
        cout << "| Father Name: \t\t" << teachers[i].getFatherName() << endl;
        cout << "| Age: \t\t\t" << teachers[i].getAge() << endl;
        cout << "| Phone: \t\t" << teachers[i].getPhone() << endl;
        cout << "| Address: \t\t" << teachers[i].getAddress() << endl;
        cout << "| Salary: \t\t" << teachers[i].getSalary() << endl;
    }
    cout << "+-------------------------------------" << endl;
}

string Class::getName()
{
    return name;
}

int Class::getId()
{
    return id;
}

int Class::getTotalStudents()
{
    return total_students;
}

int Class::getTotalTeachers()
{
    return total_teachers;
}

int Class::getFee()
{
    return fee;
}

int Class::getTotalFee()
{
    return fee*total_students;
}

void Class::setTotalClasses(int n)
{
    total_classes = n;
}

template <class T>
void Class::writeData(T &p)
{
    ofstream file;

    string filename = "storage/students_class" + to_string(id) + ".dat";

    if (typeid(p) == typeid(Teacher)) {
        filename = "storage/teachers_class" + to_string(id) + ".dat";
    }

    file.open(filename, ios::binary | ios::out | ios::app);

    file.write((char*)&p, sizeof(T));

    file.close();
}

template <class T>
void Class::rewriteData(T &p)
{
    ofstream file;

    string filename = "storage/students_class" + to_string(id) + ".dat";
    int total = total_students;

    if (typeid(*p) == typeid(Teacher)) {
        filename = "storage/teachers_class" + to_string(id) + ".dat";
        total = total_teachers;
    }

    if (total == 0) {
        int l = filename.length();
        char *f = new char[l];
        for (int i = 0; i < l; i++) {
            f[i] = filename[i];
        }
        f[l] = NULL;
        remove(f);
        return;
    }

    file.open(filename, ios::binary | ios::out);

    for (int i = 0; i < total; i++) {
        file.write((char*)&p[i], sizeof(*p));
    }
    
    file.close();
}

template <class T>
void Class::readData(T *&p)
{
    ifstream file;

    string filename = "storage/students_class" + to_string(id) + ".dat";

    if (typeid(*p) == typeid(Teacher)) {
        filename = "storage/teachers_class" + to_string(id) + ".dat";
    }

    file.open(filename, ios::binary | ios::in);

    if (!file.is_open()) {
        return;
    }

    file.seekg(0, ios::end);
    int total = file.tellg() / sizeof(T);
    file.seekg(ios::beg);

    if (typeid(*p) == typeid(Student)) {
        total_students = total;
    }
    else {
        total_teachers = total;
    }

    p = new T[total];

    T *temp = new T;

    int i = 0;
    while (file.read((char*)temp, sizeof(T))) {
        p[i] = *temp;
        i++;
    }

    delete temp;
    file.close();
}
