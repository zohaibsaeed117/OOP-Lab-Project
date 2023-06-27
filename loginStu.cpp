#include <iostream>
#include <fstream>
#include <unistd.h>
#include "function.h"
#include "class.h"
using namespace std;
void Student::login()
{
    bool flag = false;
    do
    {
        cout << "\n\n\n\tLogin Page" << endl;
        cout << "\n\n\n\tEnter UserName and Password" << endl;

        cout << "\n\n\n\tEnter UserName----->\t";
        cin >> userName;
        cout << "\n\n\n\tEnter Password----->\t";
        cin >> password;
        fstream File;
        File.open("Student.txt", ios::in);
        while (!File.eof())
        {
            string checkName, checkPassword;
            File >> checkName >> checkPassword;
            if (checkName == userName && checkPassword == password)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << "\n\n\n\tWrong Credentials!" << endl;
            char ans;
            cout<<"\n\n\n\tDo you want to try again or not?(y/n)";
            cin>>ans;
            if(ans!='y')
            {
                menu();
            }
        }
    } while (!flag);
    if (flag)
    {
        cout << "\n\n\n\t You are Logged In!" << endl;
        cout << "\n\n\n\tRedirecting to the Home Page..." << endl;
        sleep(3);
        this->homePage();
    }
}