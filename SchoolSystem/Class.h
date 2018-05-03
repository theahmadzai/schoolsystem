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
	int id;
	int fee;
	int total_fee;
	int total_students;
	Student proctor;
	Student *students;
	Teacher teachers;

public:
	Class();
	~Class();
	void addStudent();
	void removeStudent(int);
	void displayStudent(int = NULL);
};

