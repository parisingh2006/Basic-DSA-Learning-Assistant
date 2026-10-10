#include <iostream>
#include "problembank.hpp"

using namespace std;

ProblemBank::ProblemBank()
{
    score = 0;
    totalQuestions = 5;
    quizAttempted = false;
}

void ProblemBank::startQuiz()
{
    int answer;
    score = 0;
    quizAttempted = true;

    cout << "\n========== DSA QUIZ ==========\n";
    cout << "Enter 1, 2, or 3 for each question.\n";

    // Question 1
    cout << "\n1. Which data structure follows LIFO?\n";
    cout << "1. Queue\n2. Stack\n3. Array\n";
    cout << "Enter your answer: ";
    while (!(cin >> answer) || answer < 1 || answer > 3)
    {
        cout << "Invalid input! Enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    if (answer == 2)
    {
        cout << "Correct!\n";
        score++;
    }
    else
    {
        cout << "Incorrect! Correct answer: Stack\n";
    }

    // Question 2
    cout << "\n2. Which data structure follows FIFO?\n";
    cout << "1. Queue\n2. Stack\n3. Tree\n";
    cout << "Enter your answer: ";
    while (!(cin >> answer) || answer < 1 || answer > 3)
    {
        cout << "Invalid input! Enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    if (answer == 1)
    {
        cout << "Correct!\n";
        score++;
    }
    else
    {
        cout << "Incorrect! Correct answer: Queue\n";
    }

    // Question 3
    cout << "\n3. What is the index of the first array element in C++?\n";
    cout << "1. 1\n2. -1\n3. 0\n";
    cout << "Enter your answer: ";
    while (!(cin >> answer) || answer < 1 || answer > 3)
    {
        cout << "Invalid input! Enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    if (answer == 3)
    {
        cout << "Correct!\n";
        score++;
    }
    else
    {
        cout << "Incorrect! Correct answer: 0\n";
    }

    // Question 4
    cout << "\n4. Which search algorithm works on a sorted array by repeatedly dividing the search range?\n";
    cout << "1. Linear Search\n2. Binary Search\n3. Bubble Sort\n";
    cout << "Enter your answer: ";
    while (!(cin >> answer) || answer < 1 || answer > 3)
    {
        cout << "Invalid input! Enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    if (answer == 2)
    {
        cout << "Correct!\n";
        score++;
    }
    else
    {
        cout << "Incorrect! Correct answer: Binary Search\n";
    }

    // Question 5
    cout << "\n5. Which sorting algorithm compares adjacent elements?\n";
    cout << "1. Binary Search\n2. Linear Search\n3. Bubble Sort\n";
    cout << "Enter your answer: ";
    while (!(cin >> answer) || answer < 1 || answer > 3)
    {
        cout << "Invalid input! Enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    if (answer == 3)
    {
        cout << "Correct!\n";
        score++;
    }
    else
    {
        cout << "Incorrect! Correct answer: Bubble Sort\n";
    }

    displayScore();
}

void ProblemBank::displayScore()
{
    cout << "\n========== QUIZ RESULT ==========\n";
    cout << "Correct Answers: " << score << "\n";
    cout << "Total Questions: " << totalQuestions << "\n";
    cout << "Percentage: " << (score * 100) / totalQuestions << "%\n";
    cout << "=================================\n";
}

int ProblemBank::getScore()
{
    return score;
}

int ProblemBank::getTotalQuestions()
{
    return totalQuestions;
}

bool ProblemBank::hasAttemptedQuiz()
{
    return quizAttempted;
}