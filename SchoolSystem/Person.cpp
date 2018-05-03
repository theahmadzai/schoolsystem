#include <iostream>
#include "Person.h"

int Person::count = 0;

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

int const Person::getId() 
{
	return id;
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
