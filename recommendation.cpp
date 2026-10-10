#include <iostream>
#include "recommendation.hpp"
#include "problembank.hpp"

using namespace std;

void Recommendation::suggestTopic(int score, int totalQuestions, bool quizAttempted)
{
    cout << "\n========== TOPIC RECOMMENDATION ==========\n";

    if (!quizAttempted)
    {
        cout << "Please attempt the quiz first!\n";
    }
    else if (totalQuestions <= 0)
    {
        cout << "Quiz information is invalid. Please try again.\n";
    }
    else
    {
        int percentage = (score * 100) / totalQuestions;

        cout << "Your Quiz Percentage: " << percentage << "%\n";

        if (percentage < 40)
        {
            cout << "Recommendation: Revise Arrays and Searching.\n";
            cout << "Action: Review the concepts and solve basic questions.\n";
        }
        else if (percentage < 70)
        {
            cout << "Recommendation: Practise Sorting and Linked Lists.\n";
            cout << "Action: Study the algorithms and practise coding.\n";
        }
        else
        {
            cout << "Recommendation: Practise Stack and Queue problems.\n";
            cout << "Action: Try more advanced questions on these topics.\n";
        }
    }

    cout << "==========================================\n";
}

void Recommendation::suggestTopic(const ProblemBank &p)
{
    ProblemBank nonConstP = p;
    suggestTopic(nonConstP.getScore(), nonConstP.getTotalQuestions(), nonConstP.hasAttemptedQuiz());
}