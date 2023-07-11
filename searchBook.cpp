#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "class.h"
#include "function.h"
using namespace std;
void Person::searchBook()
{
    string choice;
    do
    {
        system("cls");
        string bookName;
        cout << "\n\n\n\tWhat book do you want to search?\t";
        cin.ignore();
        getline(cin, bookName);
        int flag = 0;
        fstream book;
        book.open("book.txt", ios::in);
        string checkBook;
        while (getline(book, checkBook))
        {
            if (bookName == checkBook)
            {
                flag = 1;
                break;
            }
            else if (search(checkBook, bookName) > -1)
            {
                flag = 2;
                break;
            }
        }
        book.close();
        if (flag == 1)
        {
            cout << "\n\n\n\tBook "
                 << "\"" << bookName << "\""
                 << " found" << endl;
        }
        else if (flag == 2)
        {
            char check;
            cout << "\n\n\n\tDid you mean \"" << checkBook << "\" ?(y/n)";
            cin >> check;
            if (check == 'y')
            {
                cout << "\n\n\n\tBook "
                     << "\"" << checkBook << "\""
                     << " found" << endl;
            }
            else
            {
                cout << "\n\n\n\tBook Not Found!" << endl;
            }
        }
        else
        {
            cout << "\n\n\n\tBook Not Found!" << endl;
        }
        cout << "\n\n\n\tDo you want to find another book?(y/n)";
        cin >> choice;
    } while (choice == "y"||choice=="Y");
    this->homePage();
}