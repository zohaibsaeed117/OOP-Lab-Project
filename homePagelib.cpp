#include <iostream>
#include<cstring>
#include "class.h"
#include "function.h"
using namespace std;
void Librarian::homePage()
{
    cout << "\n\t----------------------Librarian Home Page --------------------" << endl;
    cout<<"\n\n\n\tWhat do you want to do?" << endl;
    cout<<"\n\n\n\t1--->Search for a book"<<endl;
    cout<<"\n\n\n\t2--->Add a book"<<endl;
    cout<<"\n\n\n\t3--->Delete a book"<<endl;
    cout<<"\n\n\n\t4--->Issue book to Student"<<endl;
    cout<<"\n\n\n\t5--->Logout of your account"<<endl;
    cout<<"\n\n\n\t6--->Exit"<<endl;

    int choice = 0;
    cout<<"\n\n\n\tEnter you Choice--->";
    cin>>choice;
    if(choice==1)
    {
        this->searchBook();
    }
    else if(choice==2)
    {
        this->addBook();//Add a book
    }
    else if(choice==3)
    {
        this->deleteBook();//Delete a book
    }
    else if(choice==4)
    {
        this->issueBook();//Issue a book
    }
    else if(choice==5)
    {
        system("cls");
        char ans;
        cout<<"\n\n\n\tAre you sure you want to logout?(y/n)";
        cin>>ans;
        if(ans=='y')
            menu(); //Main Menu
        else
        this->homePage();
    }
    else
    {
        cout<<"\n\n\n\tThankyou for using our Library Managment System!"<<endl;//Exit
        system("exit");
    }
}
