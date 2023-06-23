#include <iostream>
#include <cstring>
#include "class.h"
#include "function.h"
using namespace std;
void Student::homePage()
{
    system("cls");
    cout << "\n\t----------------------Student Home Page --------------------" << endl;
    cout << "\n\n\n\tWhat do you want to do?" << endl;
    cout << "\n\n\n\t1--->Search for a book" << endl;
    cout << "\n\n\n\t2--->Borrow a book" << endl;
    cout << "\n\n\n\t3--->Check status of your borrowed books" << endl;
    cout << "\n\n\n\t4--->Logout of your account" << endl;
    cout << "\n\n\n\t5--->Exit" << endl;

    int choice = 0;
    cout << "\n\n\n\tEnter you Choice--->";
    cin >> choice;
    if (choice == 1)
    {
        this->searchBook();
    }
    else if (choice == 2)
    {
        this->borrowBook(); // Borrow a book
    }
    else if (choice == 3)
    {
        this->checkStatus(); // Check status
    }
    else if (choice == 4)
    {
        system("cls");
        char ans;
        cout << "\n\n\n\tAre you sure you want to logout?(y/n)";
        cin >> ans;
        if (ans == 'y')
            menu(); // Main Menu
        else
            this->homePage();
    }
    else if (choice == 5)
    {
        cout << "\n\n\n\tThankyou for using our Library Managment System!" << endl; // Exit
        system("Pause");
    }
}
