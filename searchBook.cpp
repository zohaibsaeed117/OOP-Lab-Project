#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "class.h"
#include "function.h"
using namespace std;
void Librarian:: searchBook()
{
    system("cls");
    string bookName;
    cout << "\n\n\n\tWhat book do you want to search?\t";
    cin.ignore();
    getline(cin,bookName);
    bool flag = false;
    fstream book;
    book.open("book.txt",ios::in);
    while (!book.eof())
    {
        string checkBook;
        getline(book, checkBook);
        if (bookName==checkBook)
        {
            cout << "\n\n\n\tBook "
                 << "\"" << bookName << "\""
                 << " found" << endl;
            flag = true;
            break;
        }
    }
    book.close();
    if (!flag)
    {
        cout << "\n\n\n\tBook Not Found!" << endl;
    }
    int choice = 0;
    cout << "\n\n\n\tPress 1 to find another Book" << endl;
    cout << "\n\n\n\tPress 2 to go to back to the interface" << endl;
    cout << "\n\n\n\tPress 3 to exit the Program-->" << endl;
    cout<<"\n\n\n\t Enter your Choice--->";
    cin >> choice;
    if (choice == 1)
    {
        this->searchBook();
    }
    else if (choice == 2)
    {
        cout<<"\n\n\n\tRedirecting to Menu..."<<endl;
        sleep(3);
        system("cls");
        this->homePage();
    }
    else
    {
        cout << "Thanks for using our program!" << endl;
        system("Pause");
        system("exit");
    }
}