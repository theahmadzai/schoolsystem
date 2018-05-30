#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class Logger
{
private:
    vector<string> logs;

public:
    // Native
    Logger();
    ~Logger();

    // Methods
    int totalLogs();
    void pushLog(string);
    void listLogs();
    string getLastLog();
    string getCurrentTime();

    // File Handling
    void writeData(string);
    void readData();
};

