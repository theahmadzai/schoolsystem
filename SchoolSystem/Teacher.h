#pragma once
#include "Person.h"

class Teacher : public Person
{
private:
    int salary;

public:
    // Native
    Teacher();
    Teacher(const int, const int, const char*, const char*, const char*);
    ~Teacher();

    // Getters
    int getSalary() const;

    // Setters
    bool setSalary(const unsigned int);

    // Methods
    void input();
};
