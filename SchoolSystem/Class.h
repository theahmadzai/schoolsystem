#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Teacher.h"
#include "Student.h"

using namespace std;

class Class
{
private:
    int static total_classes;
    int id;
    int fee;
    char name[10];    
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

    // Getters
    int getId();
    int getFee();
    int getTotalFee();
    int getTotalStudents();
    int getTotalTeachers();
    string getName();

    // Setters
    void static setTotalClasses(int);    

    // File handling
    template <class T>
    void writeData(T&);
    template <class T>
    void rewriteData(T&);
    template <class T>
    void readData(T*&);
};
