#include <iostream>
#include "Person.h"

unsigned int Person::count = 0;

int const Person::getId()
{
    return id;
}

int const Person::getAge()
{
    return age;
}

long long int const Person::getPhone()
{
    return phone;
}

string const Person::getName()
{
    return name;
}

string const Person::getFatherName()
{
    return father_name;
}

string const Person::getAddress()
{
    return address;
}

Person::Person() : id(++count)
{
}

Person::Person(
	int const _age = 0,
	int const _phone = 0,
	string const _name = NULL,
	string const _father_name = NULL,
	string const _address = NULL
) :
	id(++count),
	age(_age),
	phone(_phone),
	name(_name),
	father_name(_father_name),
	address(_address)
{
}

Person::~Person()
{
}

string faker(int range) {
	int limit = (rand() % 5 + range);
	char *name = new char[limit];
	for (int j = 0; j<limit; j++)
	{
		name[j] = (char)(rand() % 60 + 60);
	}
	name[limit] = NULL;
	return name;
}


void Person::input()
{
	age = rand() % 30 + 18;
	phone = rand() % 100 + 300514155;
	name = ::faker(15);
	father_name = ::faker(15);
	address = ::faker(25);
}

void const Person::display()
{
	cout << "| " << id << "\t| " << name << "\t| " << father_name << "\t| " << age << "\t| " << phone << "\t| " << address << "\t|" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}
