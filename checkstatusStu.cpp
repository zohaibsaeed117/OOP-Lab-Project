#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <cctype>
#include "class.h"
using namespace std;
void Student::checkStatus()
{
    system("cls");
    cout << "check" << endl;
    fstream status;
    status.open("status.txt", ios::in);
    int i = 0;
    while (!status.eof())
    {
        string name, checkStatus, book;
        status >> name;
        status >> checkStatus;
        getline(status, book);
        if (userName == name)
        {
            i++;
            cout << i << "."
                 << "\"" << book << "\""
                 << "\t" << checkStatus << endl;
        }
    }
    status.close();
    system("Pause");
    cout << "Redirecting to the Home page...";
    sleep(3);
    this->homePage();
}