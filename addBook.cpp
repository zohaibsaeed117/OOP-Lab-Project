#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "class.h"
using namespace std;
void Librarian::addBook()
{
    system("cls");
    char choice;
    do
    {
        bool flag = true;
        string bookName;
        cout << "\n\n\n\tEnter the book Name you want to add--->\t";
        cin.ignore();
        getline(cin, bookName);
        fstream book;
        book.open("book.txt", ios::in);
        while (!book.eof())
        {
            string checkBook;
            getline(book, checkBook);
            if (bookName == checkBook)
            {
                cout << "\n\n\n\tBook "
                     << "\"" << bookName << "\" is already in the list" << endl;
                flag = false;
                break;
            }
        }
        book.close();
        if (flag)
        {
            fstream book;
            book.open("book.txt", ios::app);
            book << endl
                 << bookName;
            cout << "\n\n\n\tBook "
                 << "\"" << bookName << "\" is added in the list succesfully" << endl;
            book.close();
        }
        cout << "\n\n\n\tDo you want to add another book?";
        cin >> choice;
    } while (choice == 'y');
    cout << "Redirecting to the home page..." << endl;
    sleep(3);
    this->homePage();
}
