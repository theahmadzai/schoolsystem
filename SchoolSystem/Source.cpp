#include <iostream>
#include "Class.h"
#include "Admin.h"

using namespace std;

int main()
{
    system("Color F0");

    Admin admin;

    for (char ch = NULL; ch != 'c' || ch != 'C'; ch = admin.panel(ch))
    {
        switch (ch)
        {
        case 'a':
        case 'A':
            admin.addClass();
            break;

        case 'r':
        case 'R':
            admin.removeClass();
            break;

        case 'e':
        case 'E':
            admin.enterClass();
            break;

        case 'l':
        case 'L':
            admin.listClasses();
            break;

        case 'g':
        case 'G':
            admin.listLogs();
            break;

        default:            
            if (ch == NULL) continue;         
            cout << " >> Wrong choice!" << endl;
            admin.pushLog("Wrong Choice");
        }
    }

    system("pause");
    return 0;
}
