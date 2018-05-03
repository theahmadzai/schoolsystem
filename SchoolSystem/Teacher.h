#pragma once
#include "Person.h"

class Teacher : public Person
{
private:
	int id;
	int salary;
	int *classes_id;

public:
	Teacher();
	Teacher(int const, int const, string const, string const, string const);
	~Teacher();
};
