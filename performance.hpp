#pragma once
// #pragma once is used to ensure that this header file is included only once during compilation
class Performance
{
private:
    // these members are private to maintain encapsulation
    int score;
    int totalQuestions;
    bool performanceAvailable;

public:
    Performance();

    void setPerformance(int s, int total);
    // s is for storing students score's
    // total is for total number of questions
    void displayPerformance();
};
