#pragma once

class Performance
{
private:
    int score;
    int totalQuestions;
    bool quizAttempted;

    int topicScore[9];
    int topicQuestions[9];

public:
    Performance();

    void setPerformance(int score, int totalQuestions);

    void setTopicPerformance(
        int topicIndex,
        int score,
        int totalQuestions);

    void displayPerformance();

    int calculatePercentage();

    int getWeakestTopic();
    int getStrongestTopic();
};