#include <iostream>
#include <fstream>
#include <unistd.h>
#include "class.h"
#include "function.h"
using namespace std;
void Student::borrowBook()
{
    char choice;
    do
    {
        system("cls");
        fstream book;
        book.open("book.txt", ios::in);
        int i = 0;
        cout << "\t---------------------------Books Name------------------------" << endl;
        string temp;
        while (getline(book, temp))
        {
            i++;
            cout << i << ". " << temp << endl;
        }
        book.close();
        book.open("book.txt", ios::in);
        string bookName;
        cout << "\n\n\n\tWhat book do you want to borrow?\t";
        cin.ignore();
        getline(cin, bookName);
        int flag = 0;
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
        fstream user;
        if (flag == 1)
        {
            bool isFound = false;
            user.open(userName + ".txt", ios::in);
            string tempString;
            while (getline(user, tempString))
            {
                if (search(tempString, bookName) > -1)
                {
                    isFound = true;
                }
            }
            user.close();
            if (!isFound)
            {
                user.open(userName + ".txt", ios::app);
                cout << "\n\n\n\tBook"
                     << "\"" << checkBook << "\" is on pending status till approved by a librarian." << endl;
                user << "pending"
                     << "\t" << checkBook << endl;
                user.close();
            }
            else
            {
                cout << "\n\n\n\tBook is already in the list" << endl;
            }
        }
        else if (flag == 2)
        {
            char check;
            cout << "\n\n\n\tDid you mean \"" << checkBook << "\"?(y/n)" << endl;
            cin >> check;
            if (check == 'y')
            {
                user.open(userName + ".txt", ios::in);
                bool isFound = false;
                string tempString;
                while (getline(user, tempString))
                {
                    if (search(tempString, bookName) > -1)
                    {
                        isFound = true;
                    }
                }
                user.close();
                if (!isFound)
                {
                    user.open(userName + ".txt", ios::app);
                    cout << "\n\n\n\tBook"
                         << "\"" << checkBook << "\" is on pending status till approved by a librarian." << endl;
                    user << "pending"
                         << "\t" << checkBook << endl;
                    user.close();
                }
                else
                {
                    cout << "\n\n\n\tBook is already in the list" << endl;
                }
                user.close();
            }
            else
            {
                cout << "\n\n\n\tBook is not present in the library!" << endl;
            }
        }
        else
        {
            cout << "\n\n\n\tBook is not present in the library!" << endl;
        }
        cout << "Do you want to borrow another book?(y/n)" << endl;
        cin >> choice;
    } while (choice == 'y');
    cout << "Redirecting to the homepage..." << endl;
    sleep(3);
    this->homePage();
}