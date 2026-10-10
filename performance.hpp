#pragma once

class Performance
{
private:
    int score;
    int totalQuestions;
    bool performanceAvailable;

public:
    Performance();

    void setPerformance(int s, int total);
    void displayPerformance();
};