#include <iostream>
#include <fstream>
#include <unistd.h>
#include "function.h"
#include "class.h"
using namespace std;
void Librarian::deleteBook()
{
    system("cls");
    char choice;
    do
    {
        bool isFound = false;
        string bookName;
        string temp;
        fstream tempBook("book.txt");
        fstream tempFile("temp.txt");
        cout << "\n\n\n\tEnter the name of the book you want to delete--->";
        cin.ignore();
        getline(cin, bookName);
        while (getline(tempBook, temp))
        {
            tempFile << temp << endl;
            if (bookName == temp)
            {
                isFound = true;
            }
        }
        tempBook.close();
        tempFile.close();
        fstream book("book.txt");
        fstream file("temp.txt");
        if (isFound == true)
        {
            while (getline(file, temp))
            {
                if (bookName == temp)
                {
                    cout << "\n\n\n\tThe book "
                         << "\"" << bookName << "\""
                         << " has been deleted succesfully." << endl;
                    continue;
                }
                book << temp << endl;
            }
        }
        else
        {
            cout << "\"" << bookName << "\""
                 << "is not found in the list." << endl;
        }
        book.close();
        file.close();
        cout << "\n\n\n\tDo you want to delete another book?(y/n)";
        cin >> choice;
    } while (choice == 'y');
    system("Pause");
    cout << "Redirecting to the home page..." << endl;
    this->homePage();
    sleep(3);
}