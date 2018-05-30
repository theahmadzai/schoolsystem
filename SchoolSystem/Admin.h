#pragma once
#include "Logger.h"
#include "Class.h"

using namespace std;

class Admin
{
private:
	vector<Class> classes;
    Class *current;
    Logger *logger;
	int students;
	int teachers;

public:
    // Native
	Admin();
	~Admin();

    // Methods
    void panel();
    void addClass();
    void removeClass();
    void listClasses();
    void enterClass();
    bool existClass(unsigned int);
    int getClassIndex(unsigned int);
    int totalClasses();
    void notify(string);

    // File Handling
    void writeData(Class&);
    void rewriteData();
    void readData();
};
