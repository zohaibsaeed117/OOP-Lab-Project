#include <iostream>
#include <unistd.h>
#include "class.h"
using namespace std;
void Librarian::Register()
{
    bool flag = true;
    cout << "\n\n\n\t To Register Enter given details:" << endl;
    do
    {

        cout << "\n\n\n\t Enter User Name:--> \t";
        cin >> this->userName;

        cout << "\n\n\n\t Enter Password:--> ";
        cin >> this->password;

        // These statments are to check whether the user name is already taken or not
        fstream File;
        File.open("Librarian.txt", ios::in);
        while (!File.eof())
        {
            string checkName = "";
            string checkPassword = "";
            File >> checkName >> checkPassword;
            if (checkName == userName)
            {

                cout << "Warning! User Name is already taken!" << endl;
                cout << "\n\n\n\t Enter Details Again:" << endl;
                system("Pause");
                flag = false;
                break;
            }
            else
            {
                flag = true;
            }
        }

    } while (flag == false);
    fstream File;
    File.open("Librarian.txt", ios::app);
    File << userName << " " << password << endl;
    cout << "User "
         << "\"" << userName << "\""
         << " registerd Successfully" << endl;
    File.close();
    cout<<"Redirecting to Login Page" << endl;
    sleep(3);
    system("cls");
    this->login();
}