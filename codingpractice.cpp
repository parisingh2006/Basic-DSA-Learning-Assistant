#include "CodingPractice.hpp"
#include <iostream>

using namespace std;

CodingPractice::CodingPractice() // Constructor
{
    initializeProblems();
}

void CodingPractice::initializeProblems()
{
    int idx = 0;

    // --- Topic 1: Arrays ---
    problems[idx++] = {
        "Reverse an Array",
        1,
        "Given an array of integers, reverse the array in place.",
        "5\n1 2 3 4 5",
        "5 4 3 2 1",
        "Use two pointers, one at the start and one at the end, swapping elements until they meet.",
        "void reverseArray(int arr[], int n) {\n    int start = 0, end = n - 1;\n    while (start < end) {\n        swap(arr[start], arr[end]);\n        start++;\n        end--;\n    }\n}",
        "https://www.hackerrank.com/challenges/arrays-ds/problem"};

    problems[idx++] = {
        "Find Maximum Element",
        1,
        "Find and return the maximum element in a given integer array.",
        "5\n12 45 2 99 23",
        "99",
        "Assume the first element is maximum, then iterate and compare.",
        "int findMax(int arr[], int n) {\n    int maxVal = arr[0];\n    for(int i = 1; i < n; i++) {\n        if(arr[i] > maxVal) maxVal = arr[i];\n    }\n    return maxVal;\n}",
        "https://www.hackerrank.com/challenges/simple-array-sum/problem"};

    // --- Topic 2: Searching ---
    problems[idx++] = {
        "Linear Search",
        2,
        "Search for a target value in an array and return its 0-based index. Return -1 if not found.",
        "5 20\n10 20 30 40 50",
        "1",
        "Check each element from left to right one by one.",
        "int linearSearch(int arr[], int n, int target) {\n    for(int i = 0; i < n; i++) {\n        if(arr[i] == target) return i;\n    }\n    return -1;\n}"};

    problems[idx++] = {
        "Binary Search",
        2,
        "Search for a target value in a sorted array in O(log n) time.",
        "5 40\n10 20 30 40 50",
        "3",
        "Find the middle index. If key is smaller, search left half; otherwise search right half.",
        "int binarySearch(int arr[], int n, int target) {\n    int low = 0, high = n - 1;\n    while(low <= high) {\n        int mid = low + (high - low) / 2;\n        if(arr[mid] == target) return mid;\n        else if(arr[mid] < target) low = mid + 1;\n        else high = mid - 1;\n    }\n    return -1;\n}",
        "https://www.hackerrank.com/challenges/icecream-parlor/problem"};

    // --- Topic 3: Sorting ---
    problems[idx++] = {
        "Bubble Sort",
        3,
        "Sort an array of n integers in ascending order using Bubble Sort.",
        "5\n64 34 25 12 22",
        "12 22 25 34 64",
        "Repeatedly swap adjacent elements if they are in the wrong order.",
        "void bubbleSort(int arr[], int n) {\n    for(int i = 0; i < n - 1; i++) {\n        for(int j = 0; j < n - i - 1; j++) {\n            if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);\n        }\n    }\n}",
        "https://www.hackerrank.com/challenges/ctci-bubble-sort/problem"};

    problems[idx++] = {
        "Selection Sort",
        3,
        "Sort an array by repeatedly finding the minimum element from the unsorted part.",
        "5\n29 10 14 37 13",
        "10 13 14 29 37",
        "Find minimum element in unsorted array and swap with element at beginning.",
        "void selectionSort(int arr[], int n) {\n    for(int i = 0; i < n - 1; i++) {\n        int minIdx = i;\n        for(int j = i + 1; j < n; j++) {\n            if(arr[j] < arr[minIdx]) minIdx = j;\n        }\n        swap(arr[i], arr[minIdx]);\n    }\n}",
        "https://www.hackerrank.com/challenges/correctness-invariant/problem"};

    // --- Topic 4: Linked Lists ---
    problems[idx++] = {
        "Insert at Head",
        4,
        "Insert a new node with data x at the beginning of a singly linked list.",
        "3\n10 20 30",
        "30 -> 20 -> 10 -> NULL",
        "Create new node, set newNode->next = head, then update head = newNode.",
        "void insertAtHead(Node*& head, int val) {\n    Node* newNode = new Node(val);\n    newNode->next = head;\n    head = newNode;\n}",
        "https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem"};

    problems[idx++] = {
        "Reverse a Linked List",
        4,
        "Reverse a singly linked list iteratively.",
        "1 -> 2 -> 3 -> NULL",
        "3 -> 2 -> 1 -> NULL",
        "Maintain three pointers: prev, current, and nextNode.",
        "Node* reverseList(Node* head) {\n    Node* prev = nullptr;\n    Node* curr = head;\n    while(curr != nullptr) {\n        Node* nextNode = curr->next;\n        curr->next = prev;\n        prev = curr;\n        curr = nextNode;\n    }\n    return prev;\n}",
        "https://www.hackerrank.com/challenges/reverse-a-linked-list/problem"};

    // --- Topic 5: Stacks ---
    problems[idx++] = {
        "Implement Stack using Array",
        5,
        "Implement push and pop operations using a fixed-size array.",
        "push(10), push(20), pop()",
        "Popped: 20",
        "Keep track of a 'top' index starting at -1.",
        "class Stack {\n    int top = -1, arr[100];\npublic:\n    void push(int x) { if(top < 99) arr[++top] = x; }\n    int pop() { return (top >= 0) ? arr[top--] : -1; }\n};",
        "https://www.hackerrank.com/challenges/maximum-element/problem"};

    problems[idx++] = {
        "Balanced Parentheses",
        5,
        "Check whether a string of brackets '()', '{}', '[]' is balanced.",
        "{[()]}",
        "Balanced",
        "Push opening brackets onto a stack; pop and match on closing brackets.",
        "bool isBalanced(string s) {\n    stack<char> st;\n    for(char c : s) {\n        if(c == '(' || c == '{' || c == '[') st.push(c);\n        else {\n            if(st.empty()) return false;\n            char top = st.top(); st.pop();\n            if((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) return false;\n        }\n    }\n    return st.empty();\n}",
        "https://www.hackerrank.com/challenges/balanced-brackets/problem"};

    // --- Topic 6: Queues ---
    problems[idx++] = {
        "Implement Queue using Array",
        6,
        "Implement enqueue and dequeue operations using an array.",
        "enqueue(5), enqueue(10), dequeue()",
        "Dequeued: 5",
        "Maintain 'front' and 'rear' indices.",
        "class Queue {\n    int front = 0, rear = 0, arr[100];\npublic:\n    void enqueue(int x) { arr[rear++] = x; }\n    int dequeue() { return (front < rear) ? arr[front++] : -1; }\n};",
        "https://www.hackerrank.com/challenges/queue-using-two-stacks/problem"};

    problems[idx++] = {
        "Circular Queue",
        6,
        "Implement a circular queue to avoid space wastage in standard linear queue.",
        "Capacity: 3, enqueue 1, 2, 3, dequeue, enqueue 4",
        "Rear wraps around to index 0",
        "Use modulo arithmetic: (rear + 1) % capacity.",
        "void enqueue(int x) {\n    if((rear + 1) % cap == front) return; // Full\n    arr[rear] = x;\n    rear = (rear + 1) % cap;\n}",
        "https://leetcode.com/problems/design-circular-queue/"};
}

void CodingPractice::startPracticeSession()
{
    int choice;

    do
    {
        cout << "\n========== CODING PRACTICE ==========\n";
        cout << "1. Arrays\n";
        cout << "2. Searching\n";
        cout << "3. Sorting\n";
        cout << "4. Linked Lists\n";
        cout << "5. Stacks\n";
        cout << "6. Queues\n";
        cout << "7. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 6)
        {
            showTopicProblems(choice);
        }
        else if (choice != 7)
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);
}

void CodingPractice::showTopicProblems(int topicID)
{
    int count = 0;
    int choice;

    cout << "\n========== PROBLEMS ==========\n";

    for (int i = 0; i < TOTAL_PRACTICE_PROBLEMS; i++)
    {
        if (problems[i].topicID == topicID)
        {
            count++;
            cout << count << ". " << problems[i].title << "\n";
        }
    }

    cout << "3. Back\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 3)
    {
        return;
    }

    if (choice < 1 || choice > 2)
    {
        cout << "Invalid choice!\n";
        return;
    }

    count = 0;

    for (int i = 0; i < TOTAL_PRACTICE_PROBLEMS; i++)
    {
        if (problems[i].topicID == topicID)
        {
            count++;

            if (count == choice)
            {
                displayProblem(i);
                return;
            }
        }
    }
}

void CodingPractice::displayProblem(int index)
{
    int choice;

    do
    {
        cout << "\n========== CODING PROBLEM ==========\n";
        cout << "Title: " << problems[index].title << "\n\n";

        cout << "Problem:\n";
        cout << problems[index].description << "\n\n";

        cout << "Sample Input:\n";
        cout << problems[index].sampleInput << "\n\n";

        cout << "Sample Output:\n";
        cout << problems[index].sampleOutput << "\n\n";

        cout << "Hint:\n";
        cout << problems[index].hint << "\n\n";

        cout << "1. View Solution\n";
        cout << "2. Practice Online\n";
        cout << "3. Back\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1)
        {
            cout << "\n========== REFERENCE SOLUTION ==========\n";
            cout << problems[index].referenceSolution << "\n";
        }
        else if (choice == 2)
        {
            showPracticeLink(index);
        }
        else if (choice != 3)
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);
}

void CodingPractice::showPracticeLink(int index)
{
    cout << "\n========== PRACTICE ONLINE ==========\n";
    cout << "Hold Ctrl and Click this link to open the challenge:\n";
    cout << problems[index].practiceUrl << "\n\n";
}
