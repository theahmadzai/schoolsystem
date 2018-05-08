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
    // Native
	Person();
	Person(int const, int const, string const, string const, string const);
	~Person();

    // Getters
	int getId() const;
    int getAge() const;
    long long int getPhone() const;
    string getName() const;
    string getFatherName() const;
    string getAddress() const;

    // Setters
    bool setAge(const unsigned int);
    bool setPhone(const unsigned long long int);
    bool setName(const string);
    bool setFatherName(const string);
    bool setAddress(const string);

    // Methods
	void input();
	void display() const;
};

