#pragma once
#include <vector>
#include "Class.h"

class Admin
{
private:
	vector<Class> classes;
	int students;
	int teachers;
	int income;

public:
    // Native
	Admin();
	~Admin();

    // Methods
    void addClass();
    void removeClass();
    void listClasses();
};

