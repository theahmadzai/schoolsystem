#include "Teacher.h"

// Native

Teacher::Teacher()
{
}

Teacher::Teacher(
    int _age,
    int _phone,
    string _name,
    string _father_name,
    string _address
) :
    Person(_age, _phone, _name, _father_name, _address)
{}

Teacher::~Teacher()
{
}

// Getters

int Teacher::getSalary() const
{
    return salary;
}

// Setters

bool Teacher::setSalary(unsigned int _salary)
{
    salary = _salary;
    return (salary == _salary);
}
