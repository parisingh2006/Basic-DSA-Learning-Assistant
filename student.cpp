#include <iostream>
#include "Student.hpp"
// included Student.hpp as the class declaration and implementation of functions.

using namespace std;

// :: => scope resolution operator used for defining outside the class

Student::Student() // Constructor defination of Student class
{
    studentID = 0;
    studentName[0] = '\0';
    registered = false;
}

void Student::registerStudent()
{
    cout << "\nEnter Student ID (positive integer): ";
    cin >> studentID;

    if (cin.fail()) // gives true if input fails
    {
        cin.clear();            // unfreezes cin or sets error state back to normal
        cin.ignore(1000, '\n'); // deletes the leftover wrong input
        // it will ignore upto 1000 characters , \n represents new line
        cout << "Invalid Student ID! Must be a valid number.\n";
        return;
    }

    if (studentID <= 0)
    {
        cin.ignore(1000, '\n');
        cout << "Student ID must be positive!\n";
        return;
    }
    
    // after reading integer , using cin.ignore again to remove remaining newline
    cin.ignore(1000, '\n');

    cout << "Enter Student Full Name: ";
    cin.getline(studentName, 50);

    if (studentName[0] == '\0')
    {
        cout << "Name cannot be empty!\n";
        return;
    }

    registered = true;
    cout << "\nRegistration Successful!\n";
}

void Student::displayStudent() const
{
    if (!registered)
    {
        cout << "\nPlease register first!\n";
        return;
    }

    cout << "\n================= STUDENT PROFILE =================\n";
    cout << "Student ID   : " << studentID << "\n";
    cout << "Student Name : " << studentName << "\n";
    cout << "===================================================\n";
}

// const use because we dont want to modify any further
bool Student::isRegistered() const
{
    return registered;
}

int Student::getStudentID() const
{
    return studentID;
}

const char *Student::getStudentName() const
{
    return studentName;
}
