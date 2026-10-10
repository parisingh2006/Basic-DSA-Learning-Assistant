#pragma once

class Student
{
private:
    int studentID;
    char studentName[50];
    bool registered;

public:
    Student();

    void registerStudent();
    void displayStudent() const;
    bool isRegistered() const;

    int getStudentID() const;
    const char *getStudentName() const;
};