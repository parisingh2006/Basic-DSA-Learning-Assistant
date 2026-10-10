#pragma once

class ProblemBank;

class Recommendation
{
public:
    void suggestTopic(int score, int totalQuestions, bool quizAttempted);
    void suggestTopic(const ProblemBank &p);
};