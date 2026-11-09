#pragma once

class FileManager
{
public:
    void saveProgress(
        int studentID,
        const char studentName[],
        int score,
        int totalQuestions,
        const int topicScores[9],
        const int topicQuestions[9]);

    void loadProgress();
};