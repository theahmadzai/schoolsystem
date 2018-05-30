#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Teacher.h"
#include "Student.h"

using namespace std;

class Class
{
private:
    int static total_classes;
    int id;
    char name[10];
    int fee;
    int total_fee;
    int total_students;
    int total_teachers;
    Student *students;
    Teacher *teachers;

public:
    // Native
    Class();
    Class(const char*, unsigned int);
    ~Class();

    // Methods
    void panel();
    void addStudent();
    void removeStudent(unsigned int = NULL);
    void displayStudent(unsigned int = NULL);
    void addTeacher();
    void removeTeacher(unsigned int = NULL);
    void displayTeacher(unsigned int = NULL);
    string getName();
    int getId();
    int getFee();
    int getTotalFee();
    int getTotalStudents();
    int getTotalTeachers();
    void static setTotalClasses(int);
    void info();

    // File handling
    template <class T>
    void writeData(T&);
    void readDataS();
    void readDataT();
};
