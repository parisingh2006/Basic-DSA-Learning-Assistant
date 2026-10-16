#pragma once

class ProblemBank; // forward declaration because of ';' usage
// we are not defining it here but this class exists

class Recommendation
{
public:
    void suggestTopic(int score, int totalQuestions, bool quizAttempted);
    void suggestTopic(const ProblemBank &p); // function overloading : as has same function name but different parameters
};

// I used foward declaration as the function suggest topic uses the reference to it
