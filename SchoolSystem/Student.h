#pragma once
#include "Person.h"

class Student : public Person
{
private:
	int fine;

public:
    // Native
	Student();
    Student(int const, int const, string const, string const, string const);
	~Student();

    // Getters
    int getFine() const;

    // Setters
    bool setFine(unsigned int const);
};
