#include <iostream>
#include "student.hpp"

using namespace std;

Student::Student()
{
    studentID = 0;
    studentName[0] = '\0';
    registered = false;
}

void Student::registerStudent()
{
    int id;

    cout << "\n============================================\n";
    cout << "             STUDENT REGISTRATION\n";
    cout << "============================================\n";

    cout << "Enter Student ID: ";

    while (!(cin >> id) || id <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid Student ID.\n";
        cout << "Enter a positive numeric Student ID: ";
    }

    cin.ignore(1000, '\n');

    cout << "Enter Student Name: ";

    cin.getline(studentName, 50);

    while (studentName[0] == '\0')
    {
        cout << "Name cannot be empty.\n";
        cout << "Enter Student Name: ";

        cin.getline(studentName, 50);
    }

    studentID = id;
    registered = true;

    cout << "\n--------------------------------------------\n";
    cout << "Registration successful.\n";
    cout << "Student ID   : " << studentID << "\n";
    cout << "Student Name : " << studentName << "\n";
    cout << "--------------------------------------------\n";
}

bool Student::isRegistered()
{
    return registered;
}

int Student::getStudentID()
{
    return studentID;
}

const char *Student::getStudentName()
{
    return studentName;
}