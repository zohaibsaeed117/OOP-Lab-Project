#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>
#include "function.h"
#include "class.h"
using namespace std;
void Librarian::deleteBook()
{
    system("cls");
    string choice;
    do
    {
        bool isFound = false;
        string bookName;
        string temp;
        ifstream book("book.txt");
        ofstream file("temp.txt");
        cout << "\n\n\n\tEnter the name of the book you want to delete--->";
        cin.ignore();
        getline(cin, bookName);
        while (getline(book, temp))
        {
            if (temp != bookName)
            {
                file<< temp <<endl;
            }
            else
            {
                isFound = true;
            }
        }
        book.close();
        file.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
        if (isFound)
        {
            cout << "\n\n\n\tBook "
                 << "\"" << bookName << "\""
                 << " has been deleted successfully." << endl;
        }
        else
        {
            cout << "\n\n\n\tBook "
                 << "\"" << bookName << "\""
                 << " is not found in the list" << endl;
        }
        cout << "\n\n\n\tDo you want to delete another book?(y/n)";
        cin >> choice;
    } while (choice == "y"||choice == "Y");
    cout << "Redirecting to the home page..." << endl;
    sleep(3);
    this->homePage();
}