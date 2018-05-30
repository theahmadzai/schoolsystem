#include "Person.h"

unsigned int Person::total = 0;

Person::Person(): id(++total), age(0), phone(0) {}

Person::Person(
    int _age,
    int _phone,
    const char *_name,
    const char *_father_name,
    const char *_address
):
    id(++total), age(_age), phone(_phone)
{
    for (int i = 0; i < 20 || name[i] != NULL; i++) {
        name[i] = _name[i];
    }

    for (int i = 0; i < 20 || father_name[i] != NULL; i++) {
        father_name[i] = _father_name[i];
    }

    for (int i = 0; i < 30 || address[i] != NULL; i++) {
        address[i] = _address[i];
    }
}

Person::~Person() {}

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

char* Person::getName()
{
    return name;
}

char* Person::getFatherName()
{
    return father_name;
}

char* Person::getAddress()
{
    return address;
}

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

bool Person::setName(char _name)
{
    *name = _name;
    return (*name == _name);
}

bool Person::setFatherName(char _father_name)
{
    *father_name = _father_name;
    return (*father_name == _father_name);
}

bool Person::setAddress(char _address)
{
    *address = _address;
    return (*address == _address);
}

void Person::input()
{
    cout << "Age: "; cin >> age;
    cout << "Phone: "; cin >> phone;
    cin.ignore();
    cout << "Name: "; cin.getline(name, 20);
    cout << "Father Name: "; cin.getline(father_name, 20);
    cout << "Address: "; cin.getline(address, 30);
}

void Person::display()
{
    cout << "| " << getId() << "\t| " << getName() << "\t\t\t| " << getFatherName() << "\t\t\t| " << getAge() << "\t| " << getPhone() << "\t| " << getAddress() << "\t\t\t|" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}
