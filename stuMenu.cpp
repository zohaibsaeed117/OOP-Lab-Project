#include <iostream>
#include "class.h"
using namespace std;

void Student::menu()
{
    system("cls");

    int choice = 0;

    cout << "<----------------------->";
    cout << "\n\n\t Welcome" << endl;
    cout << "<----------------------->" << endl;

    cout << "\n\n\n\t  Student INTERFACE " << endl;

    cout << "\n\n\n\t What do you want???" << endl;

    cout << "\n\n\n\t 1--> Register a New Account " << endl;
    cout << "\n\n\n\t 2--> Login into Existing Account " << endl;
    cout << "\n\n\n\t 3--> Back to Main Menu " << endl;
    cout << "\n\n\n\t 4--> Exit" << endl;

    cout << "\n\n\n\t Enter your choice:--> ";
    cin >> choice;
    system("cls");
    if (choice == 1)
    {
        system("cls");
        this->Register();
    }
    else if (choice == 2)
    {
        system("cls");
        this->login();
    }
    else if (choice == 3)
    {
        system("cls");
        menu();
    }
    else
    {
        cout << "\n\n\n\tThankyou For Using our Program!" << endl;
        system("Pause");
    }
}