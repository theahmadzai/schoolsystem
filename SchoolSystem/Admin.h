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

public:
    // Native
	Admin();
	~Admin();

    // Methods
    void panel();
    void add();
    void remove();
    void list();
    void enter();
    bool check(unsigned int);
    int getIndex(unsigned int);
    int totalCount();
    void notify(string);

    // File Handling
    void writeData(Class&);
    void rewriteData();
    void readData();
};
