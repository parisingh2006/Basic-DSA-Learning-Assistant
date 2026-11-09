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

    bool isRegistered();

    int getStudentID();

    const char *getStudentName();
};