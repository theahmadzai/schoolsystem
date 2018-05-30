#pragma once
#include <iostream>

using namespace std;

class Person
{
private:
    static unsigned int total;
    unsigned int id;
    unsigned int age;
    unsigned long long int phone;
    char name[20];
    char father_name[20];
    char address[30];

public:
    // Native
    Person();
    Person(const int, const int, const char*, const char*, const char*);
    ~Person();

    // Getters
    int getId() const;
    int getAge() const;
    long long int getPhone() const;
    char* getName();
    char* getFatherName();
    char* getAddress();

    // Setters
    bool setAge(const unsigned int);
    bool setPhone(const unsigned long long int);
    bool setName(const char);
    bool setFatherName(const char);
    bool setAddress(const char);

    // Methods
    void input();
    void display();
};

