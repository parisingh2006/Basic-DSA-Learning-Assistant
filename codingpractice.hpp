#pragma once
#include <string>

struct CodingProblem
{
    std::string title;
    int topicID;
    std::string description;
    std::string sampleInput;
    std::string sampleOutput;
    std::string hint;
    std::string referenceSolution;
    std::string practiceUrl;
};

class CodingPractice
{
private:
    static const int TOTAL_PRACTICE_PROBLEMS = 12;

    CodingProblem problems[TOTAL_PRACTICE_PROBLEMS];

    void initializeProblems();
    void showTopicProblems(int topicID);
    void showPracticeLink(int index);

public:
    CodingPractice();

    void startPracticeSession();
    void displayProblem(int index);
};
