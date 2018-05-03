#pragma once
#include <string>

using namespace std;

class Person
{
private:
	static int count;
	int id;
	int age;
	int phone;
	string name;
	string father_name;
	string address;

public:
	Person();
	Person(int const, int const, string const, string const, string const);
	~Person();
	int const getId();
	void input();
	void const display();
};

