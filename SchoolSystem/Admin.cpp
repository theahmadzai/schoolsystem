#include "Admin.h"

Admin::Admin()
{
}

Admin::~Admin()
{
}

void Admin::addClass()
{
    classes.push_back({});
    classes[0].addStudent();
}

void Admin::removeClass()
{
    
}

void Admin::listClasses()
{
    for (int i = 0; i < classes.size(); i++) {
        classes[i].info();
    }
}
