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
    virtual void Register()
    {
        this->userName = userName;
        this->password = password;
    }
};
class Librarian : public Person
{
public:
    void Register();
};
class Student : public Person
{
    public:
    void Register();
};
#endif