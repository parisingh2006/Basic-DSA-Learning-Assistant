#include <iostream>
#include <fstream>
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
    ofstream outFile("progress.txt");

    if (!outFile.is_open())
    {
        cout << "Error: Could not save progress.\n";
        return;
    }

    const char *topicNames[9] =
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

    outFile << "SMART_DSA_PROGRESS\n";
    outFile << "StudentID " << studentID << "\n";
    outFile << "StudentName " << studentName << "\n";
    outFile << "OverallScore "
            << score << " "
            << totalQuestions << "\n";

    outFile << "TOPIC_PERFORMANCE\n";

    for (int i = 0; i < 9; i++)
    {
        outFile << topicNames[i]
                << " "
                << topicScores[i]
                << " "
                << topicQuestions[i]
                << "\n";
    }

    outFile.close();

    cout << "Progress saved successfully to progress.txt\n";
}

void FileManager::loadProgress()
{
    ifstream inFile("progress.txt");

    if (!inFile.is_open())
    {
        cout << "No saved progress file found.\n";
        return;
    }

    char line[200];

    cout << "\n====================================================\n";
    cout << "                 SAVED PROGRESS\n";
    cout << "====================================================\n";

    while (inFile.getline(line, 200))
    {
        cout << line << "\n";
    }

    inFile.close();

    cout << "====================================================\n";
}