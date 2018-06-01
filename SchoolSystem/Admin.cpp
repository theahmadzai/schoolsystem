#include "Admin.h"

Admin::Admin(): logger(new Logger)
{
    readData();
}

Admin::~Admin()
{
    delete current;
    delete logger;
}

void Admin::panel()
{
    char ch = NULL;
    do { 
        cout << endl << endl;
        cout << "\t\t\t+---------------------------------+" << endl;
        cout << "\t\t\t|                                 |" << endl;
        cout << "\t\t\t|       C  -  QUIT                |" << endl;
        cout << "\t\t\t|       A  -  ADD CLASS           |" << endl;
        cout << "\t\t\t|       R  -  REMOVE CLASS        |" << endl;
        cout << "\t\t\t|       E  -  ENTER CLASS         |" << endl;
        cout << "\t\t\t|       L  -  LIST CLASSES (" << totalCount() << ")\t  |" << endl;
        cout << "\t\t\t|       G  -  LIST LOGS (" << logger->totalLogs() << ")\t  |" << endl;
        cout << "\t\t\t|                                 |" << endl;
        cout << "\t\t\t+---------------------------------+" << endl;
        cout << "\t\t\t| Last Action: " << logger->getLastLog() << endl;
        cout << "\t\t\t+----------------------------------" << endl;
        cout << "\t\t\t>> "; cin >> ch;

        system("cls");

        switch (ch)
        {
        case 'a':
        case 'A':
            add();
            break;

        case 'r':
        case 'R':
            remove();
            break;

        case 'e':
        case 'E':
            enter();
            break;

        case 'l':
        case 'L':
            list();
            break;

        case 'g':
        case 'G':
            logger->listLogs();
            break;

        default:
            if (ch == NULL) continue;
            cout << " >> Wrong choice!" << endl;
            logger->pushLog("Wrong Choice");
        }

    } while (ch != 'c' && ch != 'C');
}

void Admin::add()
{
    char name[10];
    cout << " >> Enter class name: "; cin >> name;
    unsigned int fee;
    cout << " >> Enter class fee: "; cin >> fee;

    Class temp(name, fee);
    classes.push_back(temp);

    writeData(temp);

    notify("Added class: " + string(name));
}

void Admin::remove()
{
    unsigned int cid;
    cout << "Enter class id to remove: "; cin >> cid;

    if(!check(cid)){
        cout << "Class id: [" << cid  << "] not found!" << endl;
        return;
    }

    classes.erase(classes.begin() + getIndex(cid));

    rewriteData();

    notify("Removed class: " + to_string(cid));
}

void Admin::list()
{
    if (totalCount() < 1) return;

    notify("Listed classes: " + to_string(totalCount()));

    cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
    cout << "| CLASS         | NAME          | STUDENTS      | TEACHERS      | PER FEE       | TOTAL FEE     |" << endl;
    cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
    for (int i = 0; i < totalCount(); i++) {
        cout << "| " << classes[i].getId() << " \t\t| " << classes[i].getName() << " \t\t| " << classes[i].getTotalStudents() << " \t\t| " << classes[i].getTotalTeachers() << " \t\t| " << classes[i].getFee() << " \t\t| " << classes[i].getTotalFee() << " \t\t|" << endl;
    }
    cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;    
}

void Admin::enter()
{
    int cid;
    cout << " >> Class ID: "; cin >> cid;

    if (totalCount() < 1) {
        cout << "Empty classes!" << endl;
        return;
    }

    if (!check(cid)) {
        cout << "Class id [" << cid << "] not found!" << endl;
        return;
    }

    current = &classes[getIndex(cid)];

    notify("Entered class: " + to_string(cid));

    current->panel();
}

bool Admin::check(unsigned int _id)
{
    for (int i = 0; i < classes.size(); i++) {
        if (classes[i].getId() == _id) {
            return true;
        }
    }
    return false;
}

int Admin::getIndex(unsigned int _id)
{
    unsigned int index = NULL;

    for (int i = 0; i < classes.size(); i++) {
        for (int i = 0; i < classes.size(); i++) {
            if (classes[i].getId() == _id) {
                index = i;
                break;
            }
        }
    }

    return index;
}

int Admin::totalCount()
{
    return classes.size();
}

void Admin::notify(string txt)
{
    logger->pushLog(txt);

    system("cls");
    cout << "**************************************************" << endl;
    cout << " --> " + txt << endl;
    cout << "**************************************************" << endl;
}

void Admin::writeData(Class &c)
{
    ofstream file;

    file.open("storage/classes.dat", ios::binary | ios::out | ios::app);

    file.write((char*)&c, sizeof(Class));

    file.close();
}

void Admin::rewriteData()
{
    ofstream file;

    if (classes.size() == 0) {
        std::remove("storage/classes.dat");
        return;
    }

    file.open("storage/classes.dat", ios::binary | ios::out);

    for (int i = 0; i < classes.size(); i++) {
        file.write((char*)&classes[i], sizeof(Class));
    }

    file.close();
}

void Admin::readData()
{
    ifstream file;

    file.open("storage/classes.dat", ios::binary | ios::in);

    if (!file.is_open()) {
        return;
    }

    Class c;

    while (file.read((char*)&c, sizeof(Class)))
    {
        classes.push_back(c);
    }

    int prev = classes[0].getId();
    int tid = prev;
    for (int i = 0; i < classes.size(); i++) {
        if (classes[i].getId() > prev) {
            tid = classes[i].getId();
        }
    }
    Class::setTotalClasses(tid);

    file.close();
}
