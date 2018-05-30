#include "Teacher.h"

Teacher::Teacher(): Person() {}

Teacher::Teacher(
    int _age,
    int _phone,
    const char *_name,
    const char *_father_name,
    const char *_address
):
    Person(_age, _phone, _name, _father_name, _address)
{}

Teacher::~Teacher() {}

int Teacher::getSalary() const
{
    return salary;
}

bool Teacher::setSalary(unsigned int _salary)
{
    salary = _salary;
    return (salary == _salary);
}
