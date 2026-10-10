#pragma once
#include <string>

struct CodingProblem
{
    std::string title;
    int topicID; // 1 to 6
    std::string description;
    std::string sampleInput;
    std::string sampleOutput;
    std::string hint;
    std::string referenceSolution;
};

class CodingPractice
{
private:
    static const int TOTAL_PRACTICE_PROBLEMS = 12;
    CodingProblem problems[TOTAL_PRACTICE_PROBLEMS];

    void initializeProblems();

public:
    CodingPractice();
    void startPracticeSession();
    void displayProblem(int index);
};