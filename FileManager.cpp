#include "FileManager.hpp"
#include <iostream>
#include <fstream> // file reading & writing
#include <string>  // store student name while loading

using namespace std;

void FileManager::saveProgress(int studentID, const char studentName[], int score, int totalQuestions)
{
    ofstream outFile("data/progress.txt");
    if (!outFile.is_open())
        outFile.open("progress.txt");

    if (outFile.is_open())
    {
        outFile << studentID << "\n";
        outFile << studentName << "\n";
        outFile << score << "\n";
        outFile << totalQuestions << "\n";
        outFile.close();
        cout << "Progress successfully saved!\n";
    }
    else
    {
        cout << "Error: Could not save progress.\n";
    }
}

void FileManager::saveProgress(int studentID, const char studentName[],
                               int score, int totalQuestions, const int topicScores[6])
{
    ofstream outFile("data/progress.txt");
    if (!outFile.is_open())
        outFile.open("progress.txt");

    if (outFile.is_open())
    {
        outFile << studentID << "\n";
        outFile << studentName << "\n";
        outFile << score << "\n";
        outFile << totalQuestions << "\n";
        for (int i = 0; i < 6; i++)
        {
            outFile << topicScores[i] << " ";
        }
        outFile << "\n";
        outFile.close();
        cout << "Progress successfully saved!\n";
    }
    else
    {
        cout << "Error: Could not save progress.\n";
    }
}

void FileManager::loadProgress()
{
    ifstream inFile("data/progress.txt");
    if (!inFile.is_open())
        inFile.open("progress.txt");

    if (inFile.is_open())
    {
        int studentID = 0;
        string studentName = "";
        int score = 0;
        int totalQuestions = 0;

        inFile >> studentID;
        inFile.ignore(1000, '\n');
        getline(inFile, studentName);
        inFile >> score;
        inFile >> totalQuestions;

        cout << "\n========== LOADED PROGRESS ==========\n";
        cout << "Student ID: " << studentID << "\n";
        cout << "Student Name: " << studentName << "\n";
        cout << "Score: " << score << " / " << totalQuestions << "\n";
        cout << "=====================================\n";
        inFile.close();
    }
    else
    {
        cout << "No previous progress file found.\n";
    }
}
