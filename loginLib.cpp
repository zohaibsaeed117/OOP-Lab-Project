#include <iostream>
#include <fstream>
#include <unistd.h>
#include "class.h"
using namespace std;
void Librarian::login()
{
    bool flag = false;
    do
    {
        cout << "\n\n\n\tEnter UserName and Password" << endl;

        cout << "\n\n\n\tEnter UserName----->\t";
        cin >> userName;
        cout << "\n\n\n\tEnter Password----->\t";
        cin >> password;
        fstream File;
        File.open("Librarian.txt", ios::in);
        while (!File.eof())
        {
            string checkName, checkPassword;
            File >> checkName >> checkPassword;
            if (checkName == userName && checkPassword == password)
            {
                cout << "\n\n\n\t You are Logged In!" << endl;
                cout << "\n\n\n\tRedirecting to the Home Page..." << endl;
                sleep(3);
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            cout<<"\n\n\n\tWrong Credentials!"<<endl;
        }
    } while (!flag);
    
}