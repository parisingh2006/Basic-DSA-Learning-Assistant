#pragma once

struct CodingProblem
{
    const char *title;
    const char *topic;
    const char *difficulty;
    const char *description;
    const char *inputFormat;
    const char *outputFormat;
    const char *example;
    const char *hint;
    const char *referenceSolution;
    const char *practiceUrl;
};

class CodingPractice
{
private:
    static const int TOTAL_PROBLEMS = 18;

    CodingProblem problems[TOTAL_PROBLEMS];

    void initializeProblems();
    void showPracticeMenu();
    void showTopicProblems(int topicChoice);
    void displayProblem(int index);

public:
    CodingPractice();

    void startPracticeSession();
};