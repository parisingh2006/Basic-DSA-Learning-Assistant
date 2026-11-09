#include <iostream>
#include "performance.hpp"

using namespace std;

Performance::Performance()
{
    score = 0;
    totalQuestions = 0;
    quizAttempted = false;

    for (int i = 0; i < 9; i++)
    {
        topicScore[i] = 0;
        topicQuestions[i] = 0;
    }
}

void Performance::setPerformance(int newScore, int newTotalQuestions)
{
    score = newScore;
    totalQuestions = newTotalQuestions;
    quizAttempted = true;
}

void Performance::setTopicPerformance(
    int topicIndex,
    int newScore,
    int newTotalQuestions)
{
    if (topicIndex < 0 || topicIndex >= 9)
    {
        return;
    }

    topicScore[topicIndex] = newScore;
    topicQuestions[topicIndex] = newTotalQuestions;
}

int Performance::calculatePercentage()
{
    if (totalQuestions == 0)
    {
        return 0;
    }

    return (score * 100) / totalQuestions;
}

void Performance::displayPerformance()
{
    cout << "\n========================================\n";
    cout << "          PERFORMANCE DASHBOARD\n";
    cout << "========================================\n";

    if (!quizAttempted || totalQuestions == 0)
    {
        cout << "No quiz performance available yet.\n";
        cout << "Attempt a quiz to view your performance.\n";
        cout << "========================================\n";
        return;
    }

    cout << "Total Questions : " << totalQuestions << "\n";
    cout << "Correct Answers : " << score << "\n";
    cout << "Overall Accuracy: "
         << calculatePercentage() << "%\n";

    cout << "\nPerformance Level: ";

    int percentage = calculatePercentage();

    if (percentage >= 80)
    {
        cout << "Excellent\n";
    }
    else if (percentage >= 60)
    {
        cout << "Good\n";
    }
    else if (percentage >= 40)
    {
        cout << "Needs Improvement\n";
    }
    else
    {
        cout << "Needs Stronger Practice\n";
    }

    cout << "\nTopic-wise Performance\n";
    cout << "----------------------------------------\n";

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

    for (int i = 0; i < 9; i++)
    {
        if (topicQuestions[i] > 0)
        {
            int percentage =
                (topicScore[i] * 100) / topicQuestions[i];

            cout << topics[i]
                 << " : "
                 << topicScore[i]
                 << "/"
                 << topicQuestions[i]
                 << " ("
                 << percentage
                 << "%)\n";
        }
    }

    int strongest = getStrongestTopic();
    int weakest = getWeakestTopic();

    if (strongest != -1)
    {
        cout << "\nStrongest Topic : "
             << topics[strongest] << "\n";
    }

    if (weakest != -1)
    {
        cout << "Weakest Topic   : "
             << topics[weakest] << "\n";
    }

    cout << "========================================\n";
}

int Performance::getWeakestTopic()
{
    int weakest = -1;
    int lowestPercentage = 101;

    for (int i = 0; i < 9; i++)
    {
        if (topicQuestions[i] > 0)
        {
            int percentage =
                (topicScore[i] * 100) / topicQuestions[i];

            if (percentage < lowestPercentage)
            {
                lowestPercentage = percentage;
                weakest = i;
            }
        }
    }

    return weakest;
}

int Performance::getStrongestTopic()
{
    int strongest = -1;
    int highestPercentage = -1;

    for (int i = 0; i < 9; i++)
    {
        if (topicQuestions[i] > 0)
        {
            int percentage =
                (topicScore[i] * 100) / topicQuestions[i];

            if (percentage > highestPercentage)
            {
                highestPercentage = percentage;
                strongest = i;
            }
        }
    }

    return strongest;
}