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
    bool setAge(unsigned int const);
    bool setPhone(unsigned long long int const);
    bool setName(string const);
    bool setFatherName(string const);
    bool setAddress(string const);

    // Methods
    void input();
    void display() const;
};

