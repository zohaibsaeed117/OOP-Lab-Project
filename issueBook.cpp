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
        getline(cin, studentName);
        ifstream student(studentName + ".txt");
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
            cin.ignore();
            getline(cin, bookName);

            while (getline(student, temp))
            {
                tempFile << temp << endl;
                if (search(temp, bookName) > -1)
                {
                    flag = true;
                }
            }
            student.close();
            tempFile.close();
            if (!flag)
            {
                cout << "Book not found in the student directory to be approved" << endl;
            }
            else
            {
                ofstream student(studentName + ".txt");
                ifstream tempFile("temp.txt");
                string line;
                while (getline(tempFile, line))
                {
                    if (search(line, bookName) > -1)
                    {
                        line.replace(0, 8, "approved ");
                    }
                    student << line << endl;
                }
                cout << "\n\n\n\tBook"
                     << "\"" << bookName << "\" for Student \"" << studentName << "\" is approved\n";
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