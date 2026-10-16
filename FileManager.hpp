#pragma once
// saving and loading student progress

class FileManager
{
public:
    void saveProgress(int studentID, const char studentName[],
                      int score, int totalQuestions);

    void saveProgress(int studentID, const char studentName[],
                      int score, int totalQuestions, const int topicScores[6]);

    void loadProgress();
};
