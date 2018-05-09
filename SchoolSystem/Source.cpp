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
    int cn = 1;

    char option;

    do {
        system("Color F9");
        cout << "Chose class: "; cin >> cn;
        cout << "Class Set to: " << cn << endl;

        cout << "------------------------------" << endl;
        cout << "S - Student Info" << endl;
        cout << "T - Teacher Teacher Info" << endl;
        cout << "F - Set Class Fee" << endl;
        cout << "I - Class Info" << endl;
        cout << "------------------------------" << endl;

        cin >> option;

        switch (option) {
        case 'f':
            int fee;
            cout << "Enter fee: "; cin >> fee;
            c[cn].setFee(fee);
            break;
        case 'i':
            c[cn].info();
            break;
        case 's':
            do {
                system("Color F0");

                cout << "------------------------------" << endl;
                cout << "A - Add Student" << endl;
                cout << "R - Remove Student" << endl;
                cout << "D - Display Students" << endl;
                cout << "B - Main Menu" << endl;
                cout << "------------------------------" << endl;

                cin >> option;

                switch (option) {
                case 'a':
                    c[cn].addStudent();
                    break;
                case 'r':
                    int id;
                    cout << "Enter id: ";  cin >> id;
                    c[cn].removeStudent(id);
                    break;
                case 'd':
                    c[cn].displayStudent();
                    break;
                default:
                    cout << "<--------" << endl;
                    system("cls");
                    break;
                }
            } while (option != 'b');
            break;
        case 't':
            do {
                system("Color F0");

                cout << "------------------------------" << endl;
                cout << "A - Add Teacher" << endl;
                cout << "R - Remove Teacher" << endl;
                cout << "D - Display Teacher" << endl;
                cout << "B - Main Menu" << endl;
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
                    system("cls");
                    break;
                }
            } while (option != 'b');
            break;
        }

    } while (option != 'c');


    system("pause");
    return 0;
}
