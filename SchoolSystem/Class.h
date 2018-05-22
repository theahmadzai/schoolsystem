#pragma once
#include "Person.h"
#include "Teacher.h"
#include "Student.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class Class
{
private:
    int static total_classes;
    int id;
    string name;
    int fee;
    int total_fee;
    int total_students;
    int total_teachers;
    Student *students;
    Teacher *teachers;

public:
    Class();
    Class(string, unsigned int);
    ~Class();
    void addStudent();
    void removeStudent(int);
    void displayStudent(int = NULL);
    void addTeacher();
    void removeTeacher(int);
    void displayTeacher(int = NULL);
    void info();
    int getFee();
    int getId();
    void setFee(unsigned int);
    int getTotalFee();
    char panel(char);
};
