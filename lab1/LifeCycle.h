/*
Isabella Felaco, isf4rjk
1-25-2022
TestLifeCycle.cpp
*/

#include <iostream>
#include <string>
using namespace std;
#ifndef LIFECYCLE_H
#define LIFECYCLE_H

// Declare the MyObject class
class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
    MyObject(string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor
    ~MyObject();                   // destructor

    string getName() const;
    void setName(const string& newName);

    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

#endif
