#include "Student.h"

Student::Student()
{
}


Student::Student(
	int const _age,
	int const _phone,
	string const _name,
	string const _father_name,
	string const _address
) :
	Person(_age, _phone, _name, _father_name, _address)
{
}


Student::~Student()
{
}
