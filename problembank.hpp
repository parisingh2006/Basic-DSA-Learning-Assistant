#pragma once

class ProblemBank
{
private:
    static const int TOPIC_COUNT = 9;
    static const int TOTAL_QUESTIONS = 27;

    struct Question
    {
        int topicIndex;
        const char *topic;
        const char *question;
        const char *option1;
        const char *option2;
        const char *option3;
        const char *option4;
        int correctAnswer;
        const char *explanation;
        int difficulty;
    };

    int score;
    int totalQuestions;
    bool quizAttempted;

    int topicScore[TOPIC_COUNT];
    int topicQuestions[TOPIC_COUNT];

    Question questionBank[TOTAL_QUESTIONS];
    int questionCount;

    void createQuestionBank();
    void resetPerformance();

    void showQuizMenu();
    void runTopicQuiz(int topicIndex);
    void runMixedQuiz();

    int getTopicIndex(int choice);
    const char *getTopicName(int topicIndex);

    int askQuestion(const Question &question, int questionNumber, int total);

public:
    ProblemBank();

    void startQuiz();
    void displayScore();

    int getScore();
    int getTotalQuestions();
    bool hasAttemptedQuiz();

    int getTopicScore(int topicIndex);
    int getTopicQuestions(int topicIndex);
};