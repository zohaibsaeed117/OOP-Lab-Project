#include <iostream>
#include <fstream>
#include<unistd.h> 
#include "class.h"
using namespace std;
void Student::borrowBook()
{
    char choice;
    do
    {
        system("cls");
        string bookName;
        cout << "\n\n\n\tWhat book do you want to borrow?\t";
        cin.ignore();
        getline(cin, bookName);
        bool flag = false;
        fstream book;
        book.open("book.txt", ios::in);
        while (!book.eof())
        {
            string checkBook;
            getline(book, checkBook);
            if (bookName == checkBook)
            {
                flag = true;
                break;
            }
        }
        book.close();
        if (!flag)
        {
            cout << "\n\n\n\tBook is not present in the library!" << endl;
        }
        else
        {
            cout << "\n\n\n\tBook"
                 << "\"" << bookName << "\" is on pending status till approved by a librarian." << endl;
            fstream book;
            book.open("status.txt", ios::app);
            book << userName << "\t"
                 << "pending"
                 << "\t" << bookName << endl;
        }
        cout<<"Do you want to borrow another book?(y/n)"<<endl;
        cin>>choice;
    } while (choice == 'y');
    cout<<"Redirecting to the homepage..."<<endl;
    sleep(3);
    this->homePage();
    
}