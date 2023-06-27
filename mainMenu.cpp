#include <iostream>
#include "class.h"
#include "stdlib.h"
using namespace std;
int Library::mainMenu()
{
    system("cls");
    cout << "<----------------------->" << endl;
    cout << "\n\n\t Welcome" << endl;
    cout << "<----------------------->" << endl;

    cout << "\n\n\n\t How do you want to Continue???" << endl;

    cout << "\n\n\n\t MAIN MENU" << endl;
    cout << "\n\n\n\t1--> LIBRARIAN" << endl;
    cout << "\n\n\n\t2--> STUDENT" << endl;
    cout << "\n\n\n\t3--> EXIT" << endl;
    cout << "\n\n\n\t PLEASE SELECT YOUR OPTION:--> ";
    int choice;
    cin >> choice;
    system("cls");
    if (choice == 1)
    {
        ptr = new Librarian; // Move user to Librarian Menu
        ptr->menu();
        return 1;
    }

    else if (choice == 2)
    {
        ptr = new Student; // Move user to stumenu Menu
        ptr->menu();
        return 1;
    }
    else
    {
        cout << "\n\n\n\tThankyou for using our Library Managment System!" << endl;
        system("Pause");
        return 0; // Exit Menu
    }
    delete ptr;
}
