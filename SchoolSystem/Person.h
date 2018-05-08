#pragma once
#include <string>

using namespace std;

class Person
{
private:
	static unsigned int count;
	unsigned int id;
	unsigned int age;
	unsigned long long int phone;
	string name;
	string father_name;
	string address;

public:
	Person();
	Person(int const, int const, string const, string const, string const);
	~Person();
	int const getId();
    int const getAge();
    long long int const getPhone();
    string const getName();
    string const getFatherName();
    string const getAddress();

	void input();
	void const display();
};

