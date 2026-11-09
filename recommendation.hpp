#pragma once

class Recommendation
{
private:
    const char *getTopicName(int topicIndex);
    void showStudyAdvice(int topicIndex);
    void showPracticeAdvice(int topicIndex);

public:
    void suggestTopic(
        int score,
        int totalQuestions,
        bool quizAttempted,
        int weakestTopic);
};