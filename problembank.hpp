#pragma once

class ProblemBank
{
private:
    int score;
    int totalQuestions;
    bool quizAttempted;

public:
    ProblemBank(); // this constructor initializes the quiz variables when object of ProblemBank class is created.

    void startQuiz();
    void displayScore();

    int getScore();
    int getTotalQuestions();
    bool hasAttemptedQuiz();
};
