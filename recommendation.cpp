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

    if (topicIndex >= 0 && topicIndex < 9)
    {
        return topics[topicIndex];
    }

    return "Unknown Topic";
}

void Recommendation::showStudyAdvice(int topicIndex)
{
    cout << "\nStudy Recommendation\n";
    cout << "----------------------------------------\n";

    switch (topicIndex)
    {
    case 0:
        cout << "Revise array traversal, insertion, deletion and indexing.\n";
        cout << "Focus on the time complexity of array operations.\n";
        break;

    case 1:
        cout << "Revise string traversal, comparison and basic manipulation.\n";
        cout << "Practise character-by-character problem solving.\n";
        break;

    case 2:
        cout << "Revise linear search and binary search.\n";
        cout << "Remember that binary search requires sorted data.\n";
        break;

    case 3:
        cout << "Revise bubble, selection and insertion sort.\n";
        cout << "Compare their time complexities.\n";
        break;

    case 4:
        cout << "Revise linked-list nodes, traversal, insertion and deletion.\n";
        cout << "Pay special attention to pointer movement.\n";
        break;

    case 5:
        cout << "Revise LIFO behaviour and stack operations.\n";
        cout << "Practise push, pop, peek and overflow/underflow.\n";
        break;

    case 6:
        cout << "Revise FIFO behaviour and queue operations.\n";
        cout << "Practise enqueue, dequeue and empty/full conditions.\n";
        break;

    case 7:
        cout << "Revise BST insertion, searching and tree traversals.\n";
        cout << "Practise inorder, preorder and postorder traversal.\n";
        break;

    case 8:
        cout << "Revise recursion, base cases and recursive calls.\n";
        cout << "Trace simple recursive functions step by step.\n";
        break;

    default:
        cout << "Revise the fundamental DSA concepts.\n";
    }
}

void Recommendation::showPracticeAdvice(int topicIndex)
{
    cout << "\nPractice Recommendation\n";
    cout << "----------------------------------------\n";

    switch (topicIndex)
    {
    case 0:
        cout << "Practise array traversal, maximum/minimum and insertion problems.\n";
        break;

    case 1:
        cout << "Practise string reversal, character counting and palindrome problems.\n";
        break;

    case 2:
        cout << "Practise linear search and binary search problems.\n";
        break;

    case 3:
        cout << "Practise sorting small arrays using the three basic algorithms.\n";
        break;

    case 4:
        cout << "Practise linked-list insertion, deletion and traversal.\n";
        break;

    case 5:
        cout << "Practise stack push, pop and peek operations.\n";
        break;

    case 6:
        cout << "Practise queue insertion, deletion and circular queue concepts.\n";
        break;

    case 7:
        cout << "Practise BST insertion, search and tree traversals.\n";
        break;

    case 8:
        cout << "Practise factorial, Fibonacci and sum-of-N recursion problems.\n";
        break;

    default:
        cout << "Practise basic DSA problems regularly.\n";
    }
}

void Recommendation::suggestTopic(
    int score,
    int totalQuestions,
    bool quizAttempted,
    int weakestTopic)
{
    cout << "\n========================================\n";
    cout << "        LEARNING RECOMMENDATION\n";
    cout << "========================================\n";

    if (!quizAttempted || totalQuestions == 0)
    {
        cout << "No quiz performance is available yet.\n";
        cout << "Please attempt the MCQ quiz first.\n";
        cout << "========================================\n";
        return;
    }

    int percentage = (score * 100) / totalQuestions;

    cout << "Overall Quiz Accuracy: "
         << percentage << "%\n";

    cout << "\nOverall Feedback\n";
    cout << "----------------------------------------\n";

    if (percentage >= 80)
    {
        cout << "Excellent performance!\n";
        cout << "Continue practising and attempt more challenging problems.\n";
    }
    else if (percentage >= 60)
    {
        cout << "Good performance.\n";
        cout << "Revise weak concepts and continue regular practice.\n";
    }
    else if (percentage >= 40)
    {
        cout << "Your fundamentals need more practice.\n";
        cout << "Focus on the recommended weak topic below.\n";
    }
    else
    {
        cout << "Strong revision is recommended.\n";
        cout << "Start with the fundamental concepts of the weak topic.\n";
    }

    if (weakestTopic != -1)
    {
        cout << "\nWeakest Topic: "
             << getTopicName(weakestTopic) << "\n";

        showStudyAdvice(weakestTopic);
        showPracticeAdvice(weakestTopic);
    }
    else
    {
        cout << "\nNo topic-specific performance is available yet.\n";
    }

    cout << "========================================\n";
}