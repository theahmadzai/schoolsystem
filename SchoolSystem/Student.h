#pragma once
#include "Person.h"

class Student : public Person
{
private:
	int id;
	int *class_id;
	int fine;

public:
	Student();
	Student(int const, int const, string const, string const, string const);
	~Student();
};
