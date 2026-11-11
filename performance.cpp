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
    if (newTotalQuestions <= 0 ||
        newScore < 0 ||
        newScore > newTotalQuestions)
    {
        quizAttempted = false;
        return;
    }

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

    if (newTotalQuestions < 0 ||
        newScore < 0 ||
        newScore > newTotalQuestions)
    {
        return;
    }

    topicScore[topicIndex] = newScore;
    topicQuestions[topicIndex] = newTotalQuestions;
}

int Performance::calculatePercentage()
{
    if (!quizAttempted || totalQuestions <= 0)
    {
        return 0;
    }

    return (score * 100) / totalQuestions;
}

void Performance::displayPerformance()
{
    cout << "\n====================================================\n";
    cout << "                 PERFORMANCE DASHBOARD\n";
    cout << "====================================================\n";

    if (!quizAttempted)
    {
        cout << "No quiz performance available yet.\n";
        cout << "Please attempt the MCQ quiz first.\n";
        cout << "====================================================\n";
        return;
    }

    int percentage = calculatePercentage();

    cout << "Overall Score : " << score
         << " / " << totalQuestions << "\n";

    cout << "Accuracy      : " << percentage << "%\n";

    if (percentage < 40)
    {
        cout << "Level         : Needs Improvement\n";
    }
    else if (percentage < 70)
    {
        cout << "Level         : Developing\n";
    }
    else if (percentage < 90)
    {
        cout << "Level         : Good\n";
    }
    else
    {
        cout << "Level         : Excellent\n";
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

    cout << "\n----------------------------------------------------\n";
    cout << "                 TOPIC PERFORMANCE\n";
    cout << "----------------------------------------------------\n";

    for (int i = 0; i < 9; i++)
    {
        cout << topicNames[i] << " : ";

        if (topicQuestions[i] == 0)
        {
            cout << "Not Attempted\n";
        }
        else
        {
            int percentage =
                (topicScore[i] * 100) / topicQuestions[i];

            cout << topicScore[i]
                 << "/" << topicQuestions[i]
                 << " (" << percentage << "%)\n";
        }
    }

    int weakest = getWeakestTopic();
    int strongest = getStrongestTopic();

    if (weakest != -1)
    {
        cout << "\nWeakest Topic  : "
             << topicNames[weakest] << "\n";
    }

    if (strongest != -1)
    {
        cout << "Strongest Topic: "
             << topicNames[strongest] << "\n";
    }

    cout << "====================================================\n";
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