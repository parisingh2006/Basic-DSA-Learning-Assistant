#include <iostream>
#include "problembank.hpp"

using namespace std;

ProblemBank::ProblemBank()
{
    score = 0;
    totalQuestions = 0;
    quizAttempted = false;
    questionCount = 0;

    resetPerformance();
    createQuestionBank();
}

void ProblemBank::resetPerformance()
{
    score = 0;
    totalQuestions = 0;
    quizAttempted = false;

    for (int i = 0; i < TOPIC_COUNT; i++)
    {
        topicScore[i] = 0;
        topicQuestions[i] = 0;
    }
}

void ProblemBank::createQuestionBank()
{
    questionCount = 0;

    // ================= ARRAYS =================

    questionBank[questionCount++] = {
        0,
        "Arrays",
        "What is the time complexity of accessing an element of an array using its index?",
        "O(1)",
        "O(n)",
        "O(log n)",
        "O(n^2)",
        1,
        "Array elements are stored in contiguous memory, so an element can be accessed directly using its index.",
        1};

    questionBank[questionCount++] = {
        0,
        "Arrays",
        "What is the main disadvantage of inserting an element at the beginning of an array?",
        "No memory is required",
        "Existing elements may need to be shifted",
        "Searching becomes impossible",
        "The array becomes sorted",
        2,
        "Elements after the insertion position usually have to be shifted to create space.",
        1};

    questionBank[questionCount++] = {
        0,
        "Arrays",
        "Which property is generally associated with a normal array?",
        "Non-contiguous storage",
        "Dynamic node-based storage",
        "Contiguous memory storage",
        "Only linked storage",
        3,
        "A normal array stores its elements in contiguous memory locations.",
        1};

    // ================= STRINGS =================

    questionBank[questionCount++] = {
        1,
        "Strings",
        "Which character marks the end of a C-style string?",
        "'\\n'",
        "'\\0'",
        "'\\t'",
        "' '",
        2,
        "C-style strings are character arrays terminated by the null character '\\0'.",
        1};

    questionBank[questionCount++] = {
        1,
        "Strings",
        "What is required to check whether a string is a palindrome?",
        "Compare characters from both ends",
        "Sort the string only",
        "Delete all characters",
        "Convert it into an integer",
        1,
        "A palindrome reads the same forward and backward, so characters from both ends can be compared.",
        1};

    questionBank[questionCount++] = {
        1,
        "Strings",
        "Which data structure is commonly used to store a C-style string?",
        "Integer variable",
        "Character array",
        "Boolean array only",
        "Floating-point variable",
        2,
        "A C-style string is stored as an array of characters ending with '\\0'.",
        1};

    // ================= SEARCHING =================

    questionBank[questionCount++] = {
        2,
        "Searching",
        "What is the worst-case time complexity of linear search?",
        "O(1)",
        "O(log n)",
        "O(n)",
        "O(n^2)",
        3,
        "Linear search may need to examine every element, giving O(n) worst-case complexity.",
        1};

    questionBank[questionCount++] = {
        2,
        "Searching",
        "What condition is normally required before applying binary search?",
        "The array must be sorted",
        "The array must contain only zeros",
        "The array must be linked",
        "The array must have duplicate values",
        1,
        "Binary search repeatedly divides the search range, which requires the data to be sorted.",
        1};

    questionBank[questionCount++] = {
        2,
        "Searching",
        "What is the time complexity of binary search in the average standard case?",
        "O(n)",
        "O(log n)",
        "O(n^2)",
        "O(2^n)",
        2,
        "Binary search eliminates approximately half of the remaining search space after each comparison.",
        2};

    // ================= SORTING =================

    questionBank[questionCount++] = {
        3,
        "Sorting",
        "Which sorting algorithm repeatedly compares adjacent elements?",
        "Bubble Sort",
        "Binary Search",
        "Linear Search",
        "Stack Sort",
        1,
        "Bubble Sort repeatedly compares adjacent elements and swaps them when they are in the wrong order.",
        1};

    questionBank[questionCount++] = {
        3,
        "Sorting",
        "Which sorting algorithm selects the minimum element and places it at the correct position?",
        "Bubble Sort",
        "Selection Sort",
        "Linear Search",
        "Binary Search",
        2,
        "Selection Sort repeatedly selects the minimum element from the unsorted portion.",
        1};

    questionBank[questionCount++] = {
        3,
        "Sorting",
        "Which sorting algorithm builds the sorted portion one element at a time?",
        "Insertion Sort",
        "Binary Search",
        "Linear Search",
        "Queue Sort",
        1,
        "Insertion Sort takes elements from the unsorted portion and inserts them into the correct position in the sorted portion.",
        2};

    // ================= LINKED LISTS =================

    questionBank[questionCount++] = {
        4,
        "Linked Lists",
        "What does the first node of a singly linked list usually point to?",
        "The previous node",
        "The next node",
        "The root only",
        "Nothing in all cases",
        2,
        "Each singly linked list node contains data and a pointer to the next node.",
        1};

    questionBank[questionCount++] = {
        4,
        "Linked Lists",
        "What is the time complexity of inserting a node at the beginning of a linked list when the head is available?",
        "O(1)",
        "O(n)",
        "O(n^2)",
        "O(log n)",
        1,
        "The new node can directly become the head without traversing the list.",
        2};

    questionBank[questionCount++] = {
        4,
        "Linked Lists",
        "Which additional pointer is present in a doubly linked list?",
        "Previous pointer",
        "Root pointer",
        "Index pointer",
        "Binary pointer",
        1,
        "A doubly linked list node normally contains both next and previous pointers.",
        1};

    // ================= STACK =================

    questionBank[questionCount++] = {
        5,
        "Stack",
        "Which principle does a stack follow?",
        "FIFO",
        "LIFO",
        "Random order",
        "Sorted order",
        2,
        "Stack follows LIFO: Last In, First Out.",
        1};

    questionBank[questionCount++] = {
        5,
        "Stack",
        "Which operation adds an element to a stack?",
        "Pop",
        "Push",
        "Dequeue",
        "Search",
        2,
        "Push inserts an element onto the top of a stack.",
        1};

    questionBank[questionCount++] = {
        5,
        "Stack",
        "What condition occurs when an element is removed from an empty stack?",
        "Overflow",
        "Underflow",
        "Collision",
        "Traversal",
        2,
        "Trying to remove an element from an empty stack causes underflow.",
        1};

    // ================= QUEUE =================

    questionBank[questionCount++] = {
        6,
        "Queue",
        "Which principle does a queue follow?",
        "LIFO",
        "FIFO",
        "Random order",
        "Reverse order",
        2,
        "Queue follows FIFO: First In, First Out.",
        1};

    questionBank[questionCount++] = {
        6,
        "Queue",
        "Which operation is generally used to insert an element into a queue?",
        "Push",
        "Pop",
        "Enqueue",
        "Peek only",
        3,
        "Enqueue adds an element to the rear of a queue.",
        1};

    questionBank[questionCount++] = {
        6,
        "Queue",
        "What is a major advantage of a circular queue over a simple array queue?",
        "It always sorts elements",
        "It reuses available positions",
        "It removes the need for a front",
        "It cannot become full",
        2,
        "A circular queue reuses positions that become available after dequeue operations.",
        2};

    // ================= BST =================

    questionBank[questionCount++] = {
        7,
        "Binary Search Tree",
        "In a Binary Search Tree, where are values smaller than the root normally placed?",
        "Right subtree",
        "Left subtree",
        "At the root only",
        "Outside the tree",
        2,
        "In a standard BST, smaller values are placed in the left subtree.",
        1};

    questionBank[questionCount++] = {
        7,
        "Binary Search Tree",
        "Which traversal of a Binary Search Tree produces values in sorted order?",
        "Preorder",
        "Postorder",
        "Inorder",
        "Level order only",
        3,
        "Inorder traversal visits left subtree, root, and right subtree, producing sorted order in a BST.",
        1};

    questionBank[questionCount++] = {
        7,
        "Binary Search Tree",
        "What is the worst-case search complexity of a Binary Search Tree?",
        "O(1)",
        "O(log n)",
        "O(n)",
        "O(n^2)",
        3,
        "If a BST becomes highly skewed, searching may require visiting every node, resulting in O(n).",
        2};

    // ================= RECURSION =================

    questionBank[questionCount++] = {
        8,
        "Recursion",
        "What is essential to stop a recursive function from calling itself forever?",
        "Loop only",
        "Base case",
        "Global variable",
        "Array",
        2,
        "A base case provides the condition at which recursive calls stop.",
        1};

    questionBank[questionCount++] = {
        8,
        "Recursion",
        "What is the factorial of 5?",
        "10",
        "25",
        "120",
        "60",
        3,
        "5! = 5 × 4 × 3 × 2 × 1 = 120.",
        1};

    questionBank[questionCount++] = {
        8,
        "Recursion",
        "Which memory structure keeps track of active recursive function calls?",
        "Queue",
        "Call stack",
        "Heap only",
        "Array only",
        2,
        "Each recursive call creates a stack frame, which is maintained on the call stack.",
        2};
}

const char *ProblemBank::getTopicName(int topicIndex)
{
    switch (topicIndex)
    {
    case 0:
        return "Arrays";
    case 1:
        return "Strings";
    case 2:
        return "Searching";
    case 3:
        return "Sorting";
    case 4:
        return "Linked Lists";
    case 5:
        return "Stack";
    case 6:
        return "Queue";
    case 7:
        return "Binary Search Tree";
    case 8:
        return "Recursion";
    default:
        return "Unknown";
    }
}

int ProblemBank::getTopicIndex(int choice)
{
    if (choice >= 2 && choice <= 10)
    {
        return choice - 2;
    }

    return -1;
}

int ProblemBank::askQuestion(
    const Question &question,
    int questionNumber,
    int total)
{
    int answer;

    cout << "\n====================================================\n";
    cout << "Question " << questionNumber << " of " << total << "\n";
    cout << "Topic      : " << question.topic << "\n";
    cout << "Difficulty : ";

    if (question.difficulty == 1)
        cout << "Easy\n";
    else
        cout << "Medium\n";

    cout << "----------------------------------------------------\n";
    cout << question.question << "\n\n";

    cout << "1. " << question.option1 << "\n";
    cout << "2. " << question.option2 << "\n";
    cout << "3. " << question.option3 << "\n";
    cout << "4. " << question.option4 << "\n";
    cout << "5. Exit Quiz\n";

    cout << "\nEnter your answer: ";

    while (!(cin >> answer) || answer < 1 || answer > 5)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid choice. Enter 1 to 5: ";
    }

    if (answer == 5)
    {
        return -1;
    }

    if (answer == question.correctAnswer)
    {
        cout << "\nCorrect answer!\n";
        cout << "Explanation: " << question.explanation << "\n";
        return 1;
    }

    cout << "\nIncorrect answer.\n";
    cout << "Correct answer: ";

    switch (question.correctAnswer)
    {
    case 1:
        cout << question.option1;
        break;

    case 2:
        cout << question.option2;
        break;

    case 3:
        cout << question.option3;
        break;

    case 4:
        cout << question.option4;
        break;
    }

    cout << "\nExplanation: " << question.explanation << "\n";

    return 0;
}

void ProblemBank::runTopicQuiz(int topicIndex)
{
    int answered = 0;

    for (int i = 0; i < questionCount; i++)
    {
        if (questionBank[i].topicIndex != topicIndex)
            continue;

        int result = askQuestion(
            questionBank[i],
            answered + 1,
            3);

        if (result == -1)
        {
            cout << "\nQuiz exited.\n";
            break;
        }

        answered++;
        totalQuestions++;
        topicQuestions[topicIndex]++;

        if (result == 1)
        {
            score++;
            topicScore[topicIndex]++;
        }
    }

    if (totalQuestions > 0)
    {
        quizAttempted = true;
    }
}

void ProblemBank::runMixedQuiz()
{
    for (int i = 0; i < questionCount; i++)
    {
        int result = askQuestion(
            questionBank[i],
            i + 1,
            questionCount);

        if (result == -1)
        {
            cout << "\nQuiz exited.\n";
            break;
        }

        totalQuestions++;

        int topicIndex = questionBank[i].topicIndex;

        topicQuestions[topicIndex]++;

        if (result == 1)
        {
            score++;
            topicScore[topicIndex]++;
        }
    }

    if (totalQuestions > 0)
    {
        quizAttempted = true;
    }
}

void ProblemBank::showQuizMenu()
{
    int choice = 0;

    do
    {
        cout << "\n====================================================\n";
        cout << "                    MCQ QUIZ\n";
        cout << "====================================================\n";
        cout << "1. All Topics\n";
        cout << "2. Arrays\n";
        cout << "3. Strings\n";
        cout << "4. Searching\n";
        cout << "5. Sorting\n";
        cout << "6. Linked Lists\n";
        cout << "7. Stack\n";
        cout << "8. Queue\n";
        cout << "9. Binary Search Tree\n";
        cout << "10. Recursion\n";
        cout << "11. Back to Practice Menu\n";
        cout << "----------------------------------------------------\n";
        cout << "Select an option: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a number from 1 to 11: ";
        }

        if (choice == 1)
        {
            resetPerformance();

            cout << "\nStarting mixed quiz with "
                 << TOTAL_QUESTIONS << " questions.\n";

            runMixedQuiz();

            if (quizAttempted)
            {
                displayScore();
            }
        }
        else if (choice >= 2 && choice <= 10)
        {
            int topicIndex = getTopicIndex(choice);

            resetPerformance();

            cout << "\nStarting quiz: "
                 << getTopicName(topicIndex) << "\n";

            runTopicQuiz(topicIndex);

            if (quizAttempted)
            {
                displayScore();
            }
        }
        else if (choice == 11)
        {
            cout << "\nReturning to Practice menu...\n";
        }
        else
        {
            cout << "\nInvalid choice. Select 1 to 11.\n";
        }

    } while (choice != 11);
}

void ProblemBank::startQuiz()
{
    showQuizMenu();
}

void ProblemBank::displayScore()
{
    if (!quizAttempted || totalQuestions == 0)
    {
        cout << "\nNo quiz has been attempted yet.\n";
        return;
    }

    int percentage = (score * 100) / totalQuestions;

    cout << "\n====================================================\n";
    cout << "                 QUIZ PERFORMANCE\n";
    cout << "====================================================\n";
    cout << "Score     : " << score << " / " << totalQuestions << "\n";
    cout << "Accuracy  : " << percentage << "%\n";

    if (percentage >= 80)
        cout << "Level     : Excellent\n";
    else if (percentage >= 60)
        cout << "Level     : Good\n";
    else if (percentage >= 40)
        cout << "Level     : Needs Improvement\n";
    else
        cout << "Level     : Needs More Practice\n";

    cout << "\n--------------- Topic-wise Performance -------------\n";

    for (int i = 0; i < TOPIC_COUNT; i++)
    {
        cout << getTopicName(i) << " : ";

        if (topicQuestions[i] == 0)
        {
            cout << "Not Attempted\n";
        }
        else
        {
            int topicPercentage =
                (topicScore[i] * 100) / topicQuestions[i];

            cout << topicScore[i]
                 << " / "
                 << topicQuestions[i]
                 << " ("
                 << topicPercentage
                 << "%)\n";
        }
    }

    cout << "====================================================\n";
}

int ProblemBank::getScore()
{
    return score;
}

int ProblemBank::getTotalQuestions()
{
    return totalQuestions;
}

bool ProblemBank::hasAttemptedQuiz()
{
    return quizAttempted;
}

int ProblemBank::getTopicScore(int topicIndex)
{
    if (topicIndex < 0 || topicIndex >= TOPIC_COUNT)
        return 0;

    return topicScore[topicIndex];
}

int ProblemBank::getTopicQuestions(int topicIndex)
{
    if (topicIndex < 0 || topicIndex >= TOPIC_COUNT)
        return 0;

    return topicQuestions[topicIndex];
}