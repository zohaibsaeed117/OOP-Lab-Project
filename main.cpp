#include <iostream>
#include "class.h"
#include "function.h"
using namespace std;

int menu()
{
    Person *ptr;
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
        ptr=new Librarian; // Move user to Librarian Menu
        libMenu(ptr);
    }

    else if (choice == 2)
    {
        ptr=new Student; // Move user to stumenu Menu
        stuMenu(ptr);
    }
    else
    {
        cout<<"\n\n\n\tThankyou for using our Library Managment System!"<<endl;
        system("Pause");
        return 1; // Exit Menu
    }

    return 0;
}
int main()
{
    menu();
    return 0; // Exit Menu
}