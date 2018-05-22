#include "Admin.h"

Admin::Admin()
{
}

Admin::~Admin()
{
}

void Admin::addClass()
{
    system("cls");
    string name;
    cout << " >> Enter class name: "; cin >> name;
    unsigned int fee;
    cout << " >> Enter class fee: "; cin >> fee;
    Class temp(name, fee);
    classes.emplace_back(temp);
    system("cls");
    cout << " --> CLASS ADDED SUCCESSFULLY!" << endl;
    pushLog("Added Class " + name);
}

void Admin::removeClass()
{
    
}

void Admin::listClasses()
{
    if (classes.size() < 1) return;
    cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
    cout << "| CLASS         | NAME          | STUDENTS      | TEACHERS      | PER FEE       | TOTAL FEE     |" << endl;
    cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
    for (int i = 0; i < classes.size(); i++) {
        classes[i].info();
    }
    pushLog("Listed Classes");
}

void Admin::enterClass()
{
    int c;
    cout << " >> Class ID: "; cin >> c;

    if (classes.size() < 1) {
        cout << "Enter classes first!" << endl;
        return;
    }
    for (int i = 0; i < classes.size(); i++) {
        if (classes[i].getId() == c) {
            c = i;
            break;
        }
        if (classes[i].getId() != c && i == classes.size() - 1) {
            cout << "Class " << c << " not found!" << endl;
            return;
        }
    }
    cout << "INDEX: "<< c << endl;
    cout << "VALUE: "<< classes[c].getId() << endl;
    *current = classes[c];

    cout << "Entered class " << current->getId() << endl;

    for (char ch = NULL; ch != 'b'; ch = this->current->panel(ch))
    {
      
    }
}

int Admin::totalClasses()
{
    return classes.size();
}

int Admin::totalLogs()
{
    return logs.size();
}

char Admin::panel(char ch)
{
    cout << endl << endl;
    cout << "\t\t\t+---------------------------------+" << endl;
    cout << "\t\t\t|                                 |" << endl;
    cout << "\t\t\t|       A  -  ADD CLASS           |" << endl;
    cout << "\t\t\t|       R  -  REMOVE CLASS        |" << endl;
    cout << "\t\t\t|       E  -  ENTER CLASS         |" << endl;
    cout << "\t\t\t|       L  -  LIST CLASSES (" << totalClasses() << ")\t  |" << endl;
    cout << "\t\t\t|       G  -  LIST LOGS (" << totalLogs() << ")\t  |" << endl;
    cout << "\t\t\t|                                 |" << endl;
    cout << "\t\t\t+---------------------------------+" << endl;
    cout << "\t\t\t| Last Action: " << getLastLog() << endl;
    cout << "\t\t\t+----------------------------------" << endl;
    cout << "\t\t\t>> "; cin >> ch;

    system("cls");
    return ch;
}

void Admin::pushLog(string text) {
    logs.push_back(getCurrentTime() + " - " + text);
}

void Admin::listLogs() {
    for (int i = 0; i < logs.size(); i++) {
        cout << i+1 << " - " << logs[i] << endl;
    }
    pushLog("Listed Logs");
}

string Admin::getLastLog() {
    if (logs.size() < 1) {
        return "No Actions Peformed Yet!";
    }
    return logs[logs.size() - 1];
}

string Admin::getCurrentTime() {
    return (
        "[" + to_string(((time(0) / 60 / 60) - 6) % 24)
        + ":" + to_string((time(0) / 60) % 60)
        + ":" + to_string((time(0)) % 60) + "]"
    );
}
