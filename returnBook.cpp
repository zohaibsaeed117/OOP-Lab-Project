#include <iostream>
#include<unistd.h>
#include <string>
#include "class.h"
#include "function.h"
using namespace std;
void Student::returnBook()
{
    char choice;
    do
    {
        system("cls");
        string fileName = userName + ".txt";
        fstream user(fileName, ios::in);
        string book;
        string status;
        int i = 0;
        cout << "\n\n\n\t--------------------------Borrowed books--------------------------\n";
        while (user>>status&&getline(user,book))
        {
            i++;
            cout << i << "." << book << endl;
        }
        user.close(); 
        string bookName;
        cout << "\n\n\n\tWhich book do you want to return?\t";
        cin.ignore();
        getline(cin, bookName);
        string temp;
        ofstream tempFile("temp.txt");
        user.open(fileName);
        bool isFound = false;
        while (getline(user, temp))
        {
            if (search(temp, bookName) > -1)
            {
                isFound = true;
                continue;
            }
            tempFile << temp << endl;
        }
        if (isFound)
        {
            cout << "\n\n\n\tThanks for returning the book \"" << bookName << "\"" << endl;
        }
        else
        {
            cout << "\n\n\n\tBook not found in your list of books" << endl;
        }
        user.close();
        tempFile.close();
        remove(fileName.c_str());
        rename("temp.txt", fileName.c_str());
        cout << "Do you want to return another book?";
        cin >> choice;
    } while (choice == 'y');
    cout<<"Redirecting to the home page..." << endl;
    sleep(3);
}
