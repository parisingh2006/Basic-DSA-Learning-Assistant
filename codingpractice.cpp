#include <iostream>
#include "codingpractice.hpp"

using namespace std;

const char *getTopicName(int choice)
{
    switch (choice)
    {
    case 1:
        return "Arrays";

    case 2:
        return "Strings";

    case 3:
        return "Searching";

    case 4:
        return "Sorting";

    case 5:
        return "Linked Lists";

    case 6:
        return "Stack";

    case 7:
        return "Queue";

    case 8:
        return "Binary Search Tree";

    case 9:
        return "Recursion";

    default:
        return "Unknown";
    }
}

bool sameText(const char *first, const char *second)
{
    int i = 0;

    while (first[i] != '\0' && second[i] != '\0')
    {
        if (first[i] != second[i])
        {
            return false;
        }

        i++;
    }

    return first[i] == second[i];
}

CodingPractice::CodingPractice()
{
    initializeProblems();
}

void CodingPractice::initializeProblems()
{
    problems[0] =
        {
            "Find Maximum Element",
            "Arrays",
            "Easy",
            "Given an array of integers, find the largest element.",
            "First enter n, followed by n integers.",
            "Print the largest element.",
            "Input: 5 10 4 25 8 12\nOutput: 25",
            "Assume the first element is maximum and compare it with the remaining elements.",
            "Use one traversal of the array and maintain a maximum value.",
            "https://www.hackerrank.com/challenges/maximizing-xor/problem"};

    problems[1] =
        {
            "Reverse an Array",
            "Arrays",
            "Easy",
            "Reverse the elements of an array without using another array.",
            "First enter n, followed by n integers.",
            "Print the array in reverse order.",
            "Input: 5 1 2 3 4 5\nOutput: 5 4 3 2 1",
            "Use two positions, one from the beginning and one from the end.",
            "Swap the elements at both positions and move them towards the centre.",
            "https://www.geeksforgeeks.org/dsa/write-a-program-to-reverse-an-array-or-string/"};

    problems[2] =
        {
            "Count Vowels",
            "Strings",
            "Easy",
            "Count the number of vowels in a given string.",
            "Enter a line of text.",
            "Print the total number of vowels.",
            "Input: programming\nOutput: 3",
            "Check each character against a, e, i, o and u.",
            "Traverse the string and increase the counter whenever a vowel is found.",
            "https://www.hackerrank.com/challenges/counting-vowels/problem"};

    problems[3] =
        {
            "Check Palindrome",
            "Strings",
            "Easy",
            "Determine whether a given string reads the same forward and backward.",
            "Enter a string.",
            "Print whether the string is a palindrome.",
            "Input: madam\nOutput: Palindrome",
            "Compare characters from both ends.",
            "Move the left and right positions towards the centre.",
            "https://www.geeksforgeeks.org/dsa/c-program-check-given-string-palindrome/"};

    problems[4] =
        {
            "Linear Search",
            "Searching",
            "Easy",
            "Find the position of a target value using linear search.",
            "Enter n, n integers and the target value.",
            "Print the position if found; otherwise print not found.",
            "Input: 5 10 20 30 40 50 30\nOutput: Found at position 3",
            "Check each element one by one.",
            "Traverse from the first element until the target is found.",
            "https://www.geeksforgeeks.org/dsa/linear-search/"};

    problems[5] =
        {
            "Binary Search",
            "Searching",
            "Medium",
            "Find a target element in a sorted array using binary search.",
            "Enter a sorted array and the target value.",
            "Print the position of the target if it exists.",
            "Input: 5 10 20 30 40 50 40\nOutput: Found at position 4",
            "Compare the target with the middle element.",
            "Discard half of the search space after every comparison.",
            "https://www.geeksforgeeks.org/dsa/binary-search/"};

    problems[6] =
        {
            "Bubble Sort",
            "Sorting",
            "Easy",
            "Sort an array in ascending order using Bubble Sort.",
            "Enter n followed by n integers.",
            "Print the sorted array.",
            "Input: 5 5 2 4 1 3\nOutput: 1 2 3 4 5",
            "Compare adjacent elements.",
            "Swap adjacent elements whenever they are in the wrong order.",
            "https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/"};

    problems[7] =
        {
            "Selection Sort",
            "Sorting",
            "Easy",
            "Sort an array using Selection Sort.",
            "Enter n followed by n integers.",
            "Print the sorted array.",
            "Input: 5 64 25 12 22 11\nOutput: 11 12 22 25 64",
            "Find the smallest element in the unsorted part.",
            "Place the smallest element at the beginning of the unsorted section.",
            "https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/"};

    problems[8] =
        {
            "Insertion Sort",
            "Sorting",
            "Medium",
            "Sort an array using the Insertion Sort algorithm.",
            "Enter n followed by n integers.",
            "Print the sorted array.",
            "Input: 5 12 11 13 5 6\nOutput: 5 5 6 11 12 13",
            "Take one element at a time and place it in its correct position.",
            "Maintain a sorted portion and insert each new element into it.",
            "https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/"};

    problems[9] =
        {
            "Insert Node at Beginning",
            "Linked Lists",
            "Easy",
            "Insert a new node at the beginning of a singly linked list.",
            "Enter the existing list followed by the new value.",
            "Display the updated linked list.",
            "Input: 10 20 30, insert 5\nOutput: 5 10 20 30",
            "The new node becomes the new head.",
            "Create a node, point it to the current head and update head.",
            "https://www.geeksforgeeks.org/dsa/linked-list-set-2-inserting-a-node/"};

    problems[10] =
        {
            "Search in Linked List",
            "Linked Lists",
            "Easy",
            "Search for a value in a singly linked list.",
            "Enter the list and the target value.",
            "Print whether the target exists.",
            "Input: 10 20 30, target 20\nOutput: Found",
            "Start from the head and move through next pointers.",
            "Traverse until the target is found or the pointer becomes NULL.",
            "https://www.geeksforgeeks.org/dsa/search-an-element-in-a-linked-list-iterative-and-recursive/"};

    problems[11] =
        {
            "Stack Using Array",
            "Stack",
            "Easy",
            "Implement push and pop operations using an array-based stack.",
            "Perform a sequence of stack operations.",
            "Display the stack after operations.",
            "Push 10, Push 20, Pop\nOutput: 10",
            "Maintain a top variable.",
            "Increment top during push and decrement top during pop.",
            "https://www.geeksforgeeks.org/dsa/stack-data-structure/"};

    problems[12] =
        {
            "Balanced Parentheses",
            "Stack",
            "Medium",
            "Check whether brackets in an expression are properly balanced.",
            "Enter an expression containing brackets.",
            "Print Balanced or Not Balanced.",
            "Input: { [ ( ) ] }\nOutput: Balanced",
            "Use a stack to remember opening brackets.",
            "For every closing bracket, check the most recent opening bracket.",
            "https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/"};

    problems[13] =
        {
            "Queue Using Array",
            "Queue",
            "Easy",
            "Implement basic enqueue and dequeue operations using an array.",
            "Perform queue operations.",
            "Display the queue after operations.",
            "Enqueue 10, Enqueue 20, Dequeue\nOutput: 20",
            "Maintain front and rear positions.",
            "Insert at the rear and remove from the front.",
            "https://www.geeksforgeeks.org/dsa/queue-data-structure/"};

    problems[14] =
        {
            "Circular Queue",
            "Queue",
            "Medium",
            "Implement a circular queue using an array.",
            "Perform enqueue and dequeue operations.",
            "Display the current queue.",
            "Enqueue 10, 20, 30, Dequeue\nOutput: 20 30",
            "Use modulo arithmetic to wrap the rear and front positions.",
            "Reuse positions that become free after dequeue.",
            "https://www.geeksforgeeks.org/dsa/circular-queue/"};

    problems[15] =
        {
            "BST Insertion",
            "Binary Search Tree",
            "Medium",
            "Insert values into a Binary Search Tree while maintaining BST properties.",
            "Enter values to insert into the tree.",
            "Display an inorder traversal.",
            "Input: 50 30 70 20 40\nOutput: 20 30 40 50 70",
            "Smaller values go left and larger values go right.",
            "Recursively compare the new value with each node.",
            "https://www.geeksforgeeks.org/dsa/binary-search-tree-data-structure/"};

    problems[16] =
        {
            "BST Search",
            "Binary Search Tree",
            "Medium",
            "Search for a value in a Binary Search Tree.",
            "Enter the BST values followed by the target.",
            "Print whether the target exists.",
            "Input: 50 30 70 20 40, target 40\nOutput: Found",
            "Use the BST ordering property.",
            "Move left for smaller values and right for larger values.",
            "https://www.geeksforgeeks.org/dsa/binary-search-tree-data-structure/"};

    problems[17] =
        {
            "Factorial Using Recursion",
            "Recursion",
            "Easy",
            "Calculate the factorial of a non-negative integer using recursion.",
            "Enter a non-negative integer n.",
            "Print n factorial.",
            "Input: 5\nOutput: 120",
            "The factorial of 0 is 1.",
            "Use n * factorial(n - 1) until the base case is reached.",
            "https://www.geeksforgeeks.org/dsa/program-for-factorial-of-a-number/"};
}

void CodingPractice::displayProblem(int index)
{
    if (index < 0 || index >= TOTAL_PROBLEMS)
    {
        cout << "Invalid problem.\n";
        return;
    }

    CodingProblem problem = problems[index];

    cout << "\n====================================================\n";
    cout << "                CODING PROBLEM\n";
    cout << "====================================================\n";

    cout << "Problem " << index + 1 << " of "
         << TOTAL_PROBLEMS << "\n";

    cout << "Title      : " << problem.title << "\n";
    cout << "Topic      : " << problem.topic << "\n";
    cout << "Difficulty : " << problem.difficulty << "\n";

    cout << "\nDescription:\n";
    cout << problem.description << "\n";

    cout << "\nInput Format:\n";
    cout << problem.inputFormat << "\n";

    cout << "\nOutput Format:\n";
    cout << problem.outputFormat << "\n";

    cout << "\nExample:\n";
    cout << problem.example << "\n";

    cout << "\nHint:\n";
    cout << problem.hint << "\n";

    cout << "\nReference Approach:\n";
    cout << problem.referenceSolution << "\n";

    cout << "\nPractice Resource:\n";
    cout << problem.practiceUrl << "\n";

    cout << "\n====================================================\n";
}

void CodingPractice::showTopicProblems(int topicChoice)
{
    const char *selectedTopic = getTopicName(topicChoice);

    int matchingProblems[TOTAL_PROBLEMS];
    int count = 0;

    for (int i = 0; i < TOTAL_PROBLEMS; i++)
    {
        if (sameText(problems[i].topic, selectedTopic))
        {
            matchingProblems[count] = i;
            count++;
        }
    }

    if (count == 0)
    {
        cout << "\nNo problems found for this topic.\n";
        return;
    }

    int choice = 0;

    do
    {
        cout << "\n============================================\n";
        cout << selectedTopic << " PROBLEMS\n";
        cout << "============================================\n";

        for (int i = 0; i < count; i++)
        {
            int index = matchingProblems[i];

            cout << i + 1 << ". "
                 << problems[index].title
                 << " ["
                 << problems[index].difficulty
                 << "]\n";
        }

        cout << count + 1 << ". Back\n";
        cout << "============================================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a valid choice: ";
        }

        if (choice >= 1 && choice <= count)
        {
            displayProblem(matchingProblems[choice - 1]);
        }
        else if (choice == count + 1)
        {
            cout << "Returning to topic menu...\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != count + 1);
}

void CodingPractice::showPracticeMenu()
{
    int choice = 0;

    do
    {
        cout << "\n============================================\n";
        cout << "              CODING PRACTICE\n";
        cout << "============================================\n";
        cout << "1. All Problems\n";
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
        cout << "============================================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a number from 1 to 11: ";
        }

        if (choice == 1)
        {
            int problemChoice = 0;

            do
            {
                cout << "\n============================================\n";
                cout << "              ALL PROBLEMS\n";
                cout << "============================================\n";

                for (int i = 0; i < TOTAL_PROBLEMS; i++)
                {
                    cout << i + 1 << ". "
                         << problems[i].title
                         << " ["
                         << problems[i].topic
                         << "] ["
                         << problems[i].difficulty
                         << "]\n";
                }

                cout << TOTAL_PROBLEMS + 1 << ". Back\n";
                cout << "============================================\n";
                cout << "Enter your choice: ";

                while (!(cin >> problemChoice))
                {
                    cin.clear();
                    cin.ignore(1000, '\n');

                    cout << "Invalid input. Enter a valid choice: ";
                }

                if (problemChoice >= 1 &&
                    problemChoice <= TOTAL_PROBLEMS)
                {
                    displayProblem(problemChoice - 1);
                }
                else if (problemChoice ==
                         TOTAL_PROBLEMS + 1)
                {
                    cout << "Returning to practice menu...\n";
                }
                else
                {
                    cout << "Invalid choice.\n";
                }

            } while (problemChoice != TOTAL_PROBLEMS + 1);
        }
        else if (choice >= 2 && choice <= 10)
        {
            showTopicProblems(choice - 1);
        }
        else if (choice == 11)
        {
            cout << "Returning to main practice menu...\n";
        }
        else
        {
            cout << "Invalid choice. Please select 1 to 11.\n";
        }

    } while (choice != 11);
}

void CodingPractice::startPracticeSession()
{
    showPracticeMenu();
}