#pragma once

class ProblemBank
{
private:
    int score;
    int totalQuestions;
    bool quizAttempted;

public:
    ProblemBank();

    void startQuiz();
    void displayScore();

    int getScore();
    int getTotalQuestions();
    bool hasAttemptedQuiz();
};