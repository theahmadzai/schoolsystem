#include "Student.h"

// Native

Student::Student()
{
}

Student::Student(
	int _age,
	int _phone,
	string _name,
	string _father_name,
	string _address
):
	Person(_age, _phone, _name, _father_name, _address)
{}

Student::~Student()
{
}

// Getters

int Student::getFine() const
{
    return fine;
}

// Setters

bool Student::setFine(unsigned int _fine)
{
    fine = _fine;
    return (fine == _fine);
}
