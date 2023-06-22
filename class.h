#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class Person
{
protected:
    string userName;
    string password;

public:
    virtual void Register() = 0;
    virtual void login()=0;
    virtual void homePage()
    {
        cout<<"this is my home page"<<endl;
    }
    virtual void searchBook()
    {
        cout<<"this is my search page"<<endl;
    }
};
class Librarian : public Person
{
public:
    void Register();
    void login();
    void homePage();
    void searchBook();
};
class Student : public Person
{
public:
    void Register();
    void login();
    // void homePage();
};
#endif