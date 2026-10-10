#include <iostream>
#include "Student.hpp"

using namespace std;

Student::Student()
{
    studentID = 0;
    studentName[0] = '\0';
    registered = false;
}

void Student::registerStudent()
{
    cout << "\nEnter Student ID (positive integer): ";
    cin >> studentID;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Student ID! Must be a valid number.\n";
        return;
    }

    if (studentID <= 0)
    {
        cin.ignore(1000, '\n');
        cout << "Student ID must be positive!\n";
        return;
    }

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