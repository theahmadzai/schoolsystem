#include <iostream>
#include "Person.h"

unsigned int Person::count = 0;

// Native

Person::Person() : id(++count)
{
    input();
}

Person::Person(
    int _age = 0,
    int _phone = 0,
    string _name = NULL,
    string _father_name = NULL,
    string _address = NULL
) :
    id(++count),
    age(_age),
    phone(_phone),
    name(_name),
    father_name(_father_name),
    address(_address)
{}

Person::~Person()
{
}

// Getters

int Person::getId() const
{
    return id;
}

int Person::getAge() const
{
    return age;
}

long long int Person::getPhone() const
{
    return phone;
}

string Person::getName() const
{
    return name;
}

string Person::getFatherName() const
{
    return father_name;
}

string Person::getAddress() const
{
    return address;
}

// Setters

bool Person::setAge(unsigned int _age)
{
    age = _age;
    return (age == _age);
}

bool Person::setPhone(unsigned long long int _phone)
{
    phone = _phone;
    return (phone == _phone);
}

bool Person::setName(string _name)
{
    name = _name;
    return (name == _name);
}

bool Person::setFatherName(string _father_name)
{
    father_name = _father_name;
    return (father_name == _father_name);
}

bool Person::setAddress(string _address)
{
    address = _address;
    return (address == _address);
}

// Methods

string faker(int range) {
    int limit = (rand() % 5 + range);
    char *name = new char[limit];
    for (int j = 0; j<limit; j++)
    {
        name[j] = (char)(rand() % 10 + 97);
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

void Person::display() const
{
    cout << "| " << getId() << "\t| " << getName() << "\t| " << getFatherName() << "\t| " << getAge() << "\t| " << getPhone() << "\t| " << getAddress() << "\t|" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}
