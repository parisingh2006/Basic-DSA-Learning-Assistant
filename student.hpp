#pragma once

class Student
{
    // kept it private to achieve data hiding and encapsulation
private:
    int studentID;
    char studentName[50]; // array having space of 50 char for a name
    bool registered;      // registration status

public:
    // public functions are accessible outside the class
    Student(); // constructor declaration

    void registerStudent(); // function to register student
    void displayStudent() const;
    bool isRegistered() const;

    // const taken as the function does NOT modify the object

    int getStudentID() const;
    const char *getStudentName() const;
    // name is stored in character array and it can be accessed by a pointer
};
