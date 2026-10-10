#include <iostream>
#include "performance.hpp"

using namespace std;

Performance::Performance()
{
    score = 0;
    totalQuestions = 0;
    performanceAvailable = false;
}

void Performance::setPerformance(int s, int total)
{
    if (total <= 0 || s < 0 || s > total)
    {
        performanceAvailable = false;
        return;
    }

    score = s;
    totalQuestions = total;
    performanceAvailable = true;
}

void Performance::displayPerformance()
{
    cout << "\n========== STUDENT PERFORMANCE ==========\n";

    if (!performanceAvailable)
    {
        cout << "No valid quiz result available yet.\n";
    }
    else
    {
        int percentage = (score * 100) / totalQuestions;

        cout << "Correct Answers: " << score << "\n";
        cout << "Total Questions: " << totalQuestions << "\n";
        cout << "Percentage: " << percentage << "%\n";

        if (percentage < 40)
        {
            cout << "Performance Level: Needs Improvement\n";
        }
        else if (percentage < 70)
        {
            cout << "Performance Level: Average\n";
        }
        else
        {
            cout << "Performance Level: Good\n";
        }
    }

    cout << "=========================================\n";
}