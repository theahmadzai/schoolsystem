#pragma once
#include "Person.h"

class Teacher : public Person
{
private:
	int salary;
	int *classes_id;

public:
    // Native
	Teacher();
	Teacher(int const, int const, string const, string const, string const);
	~Teacher();

    // Getters
    int getSalary() const;

    // Setters
    bool setSalary(unsigned int const);
};
