#pragma once
#include <vector>
#include <time.h>
#include "Class.h"

class Admin
{
private:
	vector<Class> classes;
    vector<string> logs;
    Class *current;
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
    void enterClass();
    char panel(char);
    string getCurrentTime();
    int totalClasses();
    int totalLogs();
    void pushLog(string);
    void listLogs();
    string getLastLog();
};
