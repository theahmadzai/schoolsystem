#include "Logger.h"

Logger::Logger()
{
    readData();
}

Logger::~Logger() {}

int Logger::totalLogs()
{
    return logs.size();
}

void Logger::pushLog(string log)
{
    string txt = getCurrentTime() + " - " + log;
    logs.push_back(txt);
    writeData(txt);
}

void Logger::listLogs()
{
    for (int i = 0; i < logs.size(); i++) {
        cout << i + 1 << " - " << logs[i] << endl;
    }
}

string Logger::getLastLog()
{
    if (logs.size() < 1) {
        return "No Logs yet!";
    }
    return logs[logs.size() - 1];
}

string Logger::getCurrentTime()
{
    return (
        "[" + to_string(((time(0) / 60 / 60) - 6) % 24)
        + ":" + to_string((time(0) / 60) % 60)
        + ":" + to_string((time(0)) % 60) + "]"
        );
}

void Logger::writeData(string log)
{
    ofstream file;

    file.open("storage/logs.txt", ios::binary | ios::out | ios::app);

    file << log + "\n";

    file.close();
}

void Logger::readData()
{
    ifstream file;

    file.open("storage/logs.txt", ios::binary | ios::in );

    string log;

    if (!file.is_open()) {
        return;
    }

    while (!file.eof())
    {
        getline(file, log, '\n');
        if (log == "") continue;
        logs.push_back(log);
    }

    file.close();
}
