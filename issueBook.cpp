#include <iostream>
#include <unistd.h>
#include "class.h"
#include "function.h"
using namespace std;
void Librarian::issueBook()
{
    system("cls");
    char choice;
    do
    {
        string studentName;
        cout << "\n\n\n\tEnter the name of the Student you want to issue a book\t";
        cin.ignore();
        getline(cin, studentName);
        string fileName=studentName+".txt";
        ifstream student(fileName);
        ofstream tempFile("temp.txt");
        if (!student)
        {
            cout << "\n\n\n\tThe student not found!" << endl;
        }
        else
        {
            bool flag = false;
            string temp;
            string bookName;
            cout << "\n\n\n\tEnter the name of the book you want to issue to student"
                 << " \"" << studentName << "\":\t";
            getline(cin, bookName);

            while (getline(student, temp))
            {
                if (search(temp, bookName) > -1)
                {
                    temp.replace(0,8,"approved ");
                    flag = true;
                }
                tempFile << temp << endl;
            }
            student.close();
            tempFile.close();
            remove(fileName.c_str());
            rename("temp.txt",fileName.c_str());
            if (flag)
            {
                cout << "\n\n\n\tBook"
                     << "\"" << bookName << "\" for Student \"" << studentName << "\" is approved\n";
            }
            else
            {
                cout << "Book not found in the student directory to be approved" << endl;
            }
        }
        cout << "\n\n\n\tDo you want to issue book to another student?(y/n)";
        cin >> choice;
    } while (choice == 'y');
    system("Pause");
    cout << "Redirecting to the Home page...";
    sleep(3);
    this->homePage();
}