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
    cout<<"\n\n\n\t3--->Issue book to Student"<<endl;
    cout<<"\n\n\n\t4--->Back to Main Menu"<<endl;
    cout<<"\n\n\n\t5--->Exit"<<endl;

    int choice = 0;
    cout<<"\n\n\n\tEnter you Choice--->";
    cin>>choice;
    if(choice==1)
    {
        this->searchBook();
    }
    else if(choice==2)
    {
        //Add a book
    }
    else if(choice==3)
    {
        //Issue a book
    }
    else if(choice==4)
    {
       menu(); //Main Menu
    }
    else if(choice==5)
    {
        cout<<"\n\n\n\tThankyou for using our Library Managment System!"<<endl;//Exit
        system("Pause");
    }
}
