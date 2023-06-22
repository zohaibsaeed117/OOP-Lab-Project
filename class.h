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
    virtual void login()
    {
        cout<<"In person registration"<<endl;
    }
};
class Librarian : public Person
{
public:
    void Register();
    void login();
};
class Student : public Person
{
public:
    void Register();
    // void login();
};
#endif