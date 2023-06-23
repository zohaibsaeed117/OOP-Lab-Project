#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "class.h"
using namespace std;
void Student::checkStatus()
{
    system("cls");
    fstream status;
    status.open(userName+".txt", ios::in);
    int i = 0;
    while (!status.eof())
    {
        string name, checkStatus, book;
        status >> name;
        status >> checkStatus;
        getline(status, book);
        i++;
        cout << i << "."
             << "\"" << book << "\""
             << "\t" << checkStatus << endl;
    }
    status.close();
    system("Pause");
    cout << "Redirecting to the Home page...";
    sleep(3);
    this->homePage();
}