#include <iostream>
#include <fstream>
#include <string>
#include "FileManager.hpp"

using namespace std;

void FileManager::saveProgress(
    int studentID,
    const char studentName[],
    int score,
    int totalQuestions,
    const int topicScores[9],
    const int topicQuestions[9])
{
    ofstream file("progress.txt");

    if (!file.is_open())
    {
        cout << "\nError: Unable to open progress.txt for saving.\n";
        return;
    }

    const char *topics[9] =
        {
            "Arrays",
            "Strings",
            "Searching",
            "Sorting",
            "Linked Lists",
            "Stack",
            "Queue",
            "Binary Search Tree",
            "Recursion"};

    file << "SMART_DSA_PROGRESS\n";
    file << "StudentID: " << studentID << "\n";
    file << "StudentName: " << studentName << "\n";
    file << "OverallScore: " << score << "\n";
    file << "TotalQuestions: " << totalQuestions << "\n";
    file << "TOPIC_PERFORMANCE\n";

    for (int i = 0; i < 9; i++)
    {
        file << topics[i] << ": "
             << topicScores[i] << "/"
             << topicQuestions[i] << "\n";
    }

    file.close();

    cout << "\nProgress saved successfully.\n";
    cout << "File: progress.txt\n";
}

void FileManager::loadProgress()
{
    ifstream file("progress.txt");

    if (!file.is_open())
    {
        cout << "\nNo saved progress was found.\n";
        cout << "Attempt a quiz and save your progress first.\n";
        return;
    }

    cout << "\n============================================\n";
    cout << "          SAVED STUDENT PROGRESS\n";
    cout << "============================================\n";

    string line;

    while (getline(file, line))
    {
        cout << line << "\n";
    }

    file.close();

    cout << "============================================\n";
}