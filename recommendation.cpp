#include <iostream>
#include "recommendation.hpp"

using namespace std;

const char *Recommendation::getTopicName(int topicIndex)
{
    const char *topics[9] =
        {
            "Arrays",
            "Strings",
            "Searching",
            "Sorting",
            "Linked Lists",
            "Stack",
            "Queue",
            "Binary Search Tree",
            "Recursion"};

    if (topicIndex < 0 || topicIndex >= 9)
    {
        return "No specific topic";
    }

    return topics[topicIndex];
}

void Recommendation::showStudyAdvice(int topicIndex)
{
    cout << "\nStudy Advice:\n";

    switch (topicIndex)
    {
    case 0:
        cout << "- Revise indexing, traversal and array operations.\n";
        break;

    case 1:
        cout << "- Revise character traversal and string operations.\n";
        break;

    case 2:
        cout << "- Revise Linear Search and Binary Search.\n";
        break;

    case 3:
        cout << "- Compare Bubble, Selection and Insertion Sort.\n";
        break;

    case 4:
        cout << "- Revise node links, insertion and deletion.\n";
        break;

    case 5:
        cout << "- Revise LIFO, push, pop and stack overflow/underflow.\n";
        break;

    case 6:
        cout << "- Revise FIFO, enqueue, dequeue and queue conditions.\n";
        break;

    case 7:
        cout << "- Revise BST insertion, search and traversals.\n";
        break;

    case 8:
        cout << "- Identify base cases and recursive cases carefully.\n";
        break;

    default:
        cout << "- Review your DSA fundamentals.\n";
    }
}

void Recommendation::showPracticeAdvice(int topicIndex)
{
    cout << "Practice Advice:\n";

    switch (topicIndex)
    {
    case 0:
        cout << "- Solve array traversal and maximum/minimum problems.\n";
        break;

    case 1:
        cout << "- Practice string reversal and character counting.\n";
        break;

    case 2:
        cout << "- Practice both linear and binary search.\n";
        break;

    case 3:
        cout << "- Implement sorting algorithms manually.\n";
        break;

    case 4:
        cout << "- Practice linked-list insertion and deletion.\n";
        break;

    case 5:
        cout << "- Practice stack operations and bracket problems.\n";
        break;

    case 6:
        cout << "- Practice enqueue and dequeue operations.\n";
        break;

    case 7:
        cout << "- Practice BST insertion, search, deletion and traversal.\n";
        break;

    case 8:
        cout << "- Trace small recursive examples by hand.\n";
        break;

    default:
        cout << "- Practice basic DSA problems regularly.\n";
    }
}

void Recommendation::suggestTopic(
    int score,
    int totalQuestions,
    bool quizAttempted,
    int weakestTopic)
{
    cout << "\n====================================================\n";
    cout << "             LEARNING RECOMMENDATION\n";
    cout << "====================================================\n";

    if (!quizAttempted)
    {
        cout << "No quiz has been attempted yet.\n";
        cout << "Recommendation: Attempt the MCQ quiz first.\n";
        cout << "This will help identify your weaker areas.\n";
        cout << "====================================================\n";
        return;
    }

    if (totalQuestions <= 0 ||
        score < 0 ||
        score > totalQuestions)
    {
        cout << "Invalid performance information.\n";
        cout << "Please attempt the quiz again.\n";
        cout << "====================================================\n";
        return;
    }

    int percentage =
        (score * 100) / totalQuestions;

    cout << "Quiz Accuracy: "
         << percentage << "%\n";

    if (weakestTopic >= 0 && weakestTopic < 9)
    {
        cout << "Focus Topic  : "
             << getTopicName(weakestTopic) << "\n";

        showStudyAdvice(weakestTopic);
        showPracticeAdvice(weakestTopic);
    }
    else if (percentage < 40)
    {
        cout << "\nYour overall score needs improvement.\n";
        cout << "Start with fundamental DSA concepts.\n";
        cout << "Recommended focus: Arrays and Searching.\n";
    }
    else if (percentage < 70)
    {
        cout << "\nYour performance is developing.\n";
        cout << "Strengthen your fundamentals through practice.\n";
        cout << "Recommended focus: Sorting and Linked Lists.\n";
    }
    else
    {
        cout << "\nGood performance!\n";
        cout << "Continue challenging yourself with advanced practice.\n";
        cout << "Recommended focus: Stack, Queue, BST and Recursion.\n";
    }

    cout << "====================================================\n";
}