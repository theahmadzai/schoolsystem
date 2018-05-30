#include "Student.h"

Student::Student(): Person() {}

Student::Student(
    int _age,
    int _phone,
    const char *_name,
    const char *_father_name,
    const char *_address
):
    Person(_age, _phone, _name, _father_name, _address)
{}

Student::~Student() {}

int Student::getFine() const
{
    return fine;
}

bool Student::setFine(unsigned int _fine)
{
    fine = _fine;
    return (fine == _fine);
}
