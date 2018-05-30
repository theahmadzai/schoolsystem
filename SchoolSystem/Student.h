#pragma once
#include "Person.h"

class Student : public Person
{
private:
    int fine;

public:
    // Native
    Student();
    Student(const int, const int, const char*, const char*, const char*);
    ~Student();

    // Getters
    int getFine() const;

    // Setters
    bool setFine(const unsigned int);
};
