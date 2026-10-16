#pragma once
#include <string>

// created a structure first so that can group related variables together.
struct CodingProblem
{
    std::string title;
    int topicID;
    // std::string means that string belongs to standard namespace
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
    // 12 problems for now will be changing later 

    CodingProblem problems[TOTAL_PRACTICE_PROBLEMS];// array of objects

    void initializeProblems();
    void showTopicProblems(int topicID);
    void showPracticeLink(int index);

public:
    CodingPractice();

    void startPracticeSession();
    void displayProblem(int index);
};
