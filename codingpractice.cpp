#include <iostream>
#include "CodingPractice.hpp"

using namespace std;

CodingPractice::CodingPractice()
{
    initializeProblems();
}

void CodingPractice::initializeProblems()
{
    // Arrays
    problems[0] = {
        "Reverse an Array In-Place",
        1,
        "Given an integer array of size N, reverse its elements without using auxiliary arrays.",
        "Input: arr = [1, 2, 3, 4, 5], N = 5",
        "Output: [5, 4, 3, 2, 1]",
        "Use two pointers (start = 0, end = N - 1) and swap while start < end.",
        "void reverseArray(int arr[], int n) {\n"
        "    int start = 0, end = n - 1;\n"
        "    while (start < end) {\n"
        "        int temp = arr[start];\n"
        "        arr[start] = arr[end];\n"
        "        arr[end] = temp;\n"
        "        start++; end--;\n"
        "    }\n"
        "}"};
    problems[1] = {
        "Find Maximum and Minimum in an Array",
        1,
        "Traverse an array of N integers and identify both the maximum and minimum elements.",
        "Input: arr = [12, 4, 56, 2, 9], N = 5",
        "Output: Min = 2, Max = 56",
        "Initialize min and max with arr[0], then iterate from index 1 to N-1 updating them.",
        "void findMinMax(int arr[], int n, int &minVal, int &maxVal) {\n"
        "    minVal = arr[0]; maxVal = arr[0];\n"
        "    for (int i = 1; i < n; i++) {\n"
        "        if (arr[i] < minVal) minVal = arr[i];\n"
        "        if (arr[i] > maxVal) maxVal = arr[i];\n"
        "    }\n"
        "}"};

    // Searching
    problems[2] = {
        "Iterative Binary Search",
        2,
        "Implement binary search on a sorted array of size N to locate a target key.",
        "Input: arr = [2, 5, 8, 12, 16], target = 8",
        "Output: Found at Index: 2",
        "Calculate mid = low + (high - low)/2. Adjust low or high boundaries accordingly.",
        "int binarySearch(int arr[], int n, int key) {\n"
        "    int low = 0, high = n - 1;\n"
        "    while (low <= high) {\n"
        "        int mid = low + (high - low) / 2;\n"
        "        if (arr[mid] == key) return mid;\n"
        "        else if (arr[mid] < key) low = mid + 1;\n"
        "        else high = mid - 1;\n"
        "    }\n"
        "    return -1;\n"
        "}"};
    problems[3] = {
        "Find First Occurrence of an Element",
        2,
        "In a sorted array with duplicates, return the lowest index where target appears.",
        "Input: arr = [1, 2, 2, 2, 3], target = 2",
        "Output: Index: 1",
        "When arr[mid] == target, save the index and continue searching the left half (high = mid - 1).",
        "int firstOccurrence(int arr[], int n, int key) {\n"
        "    int low = 0, high = n - 1, res = -1;\n"
        "    while (low <= high) {\n"
        "        int mid = low + (high - low) / 2;\n"
        "        if (arr[mid] == key) { res = mid; high = mid - 1; }\n"
        "        else if (arr[mid] < key) low = mid + 1;\n"
        "        else high = mid - 1;\n"
        "    }\n"
        "    return res;\n"
        "}"};

    // Sorting
    problems[4] = {
        "Bubble Sort with Early Exit",
        3,
        "Sort an array in ascending order using Bubble Sort optimized with a boolean swapped flag.",
        "Input: arr = [64, 34, 25, 12, 22, 11, 90]",
        "Output: [11, 12, 22, 25, 34, 64, 90]",
        "If no swaps occur in an inner pass, break early as the array is already sorted.",
        "void bubbleSort(int arr[], int n) {\n"
        "    for (int i = 0; i < n - 1; i++) {\n"
        "        bool swapped = false;\n"
        "        for (int j = 0; j < n - i - 1; j++) {\n"
        "            if (arr[j] > arr[j + 1]) {\n"
        "                int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;\n"
        "                swapped = true;\n"
        "            }\n"
        "        }\n"
        "        if (!swapped) break;\n"
        "    }\n"
        "}"};
    problems[5] = {
        "Insertion Sort Implementation",
        3,
        "Sort an array in ascending order by shifting larger elements to make room for insertion.",
        "Input: arr = [12, 11, 13, 5, 6]",
        "Output: [5, 6, 11, 12, 13]",
        "Pick element key = arr[i]. Shift elements of arr[0..i-1] that are greater than key to the right.",
        "void insertionSort(int arr[], int n) {\n"
        "    for (int i = 1; i < n; i++) {\n"
        "        int key = arr[i];\n"
        "        int j = i - 1;\n"
        "        while (j >= 0 && arr[j] > key) {\n"
        "            arr[j + 1] = arr[j];\n"
        "            j--;\n"
        "        }\n"
        "        arr[j + 1] = key;\n"
        "    }\n"
        "}"};

    // Linked Lists
    problems[6] = {
        "Reverse a Singly Linked List",
        4,
        "Reverse a singly linked list in-place using three pointers.",
        "Input: 1 -> 2 -> 3 -> 4 -> NULL",
        "Output: 4 -> 3 -> 2 -> 1 -> NULL",
        "Maintain prev (null), curr (head), and next (null). Rewire curr->next to prev.",
        "Node* reverseList(Node* head) {\n"
        "    Node* prev = nullptr;\n"
        "    Node* curr = head;\n"
        "    while (curr != nullptr) {\n"
        "        Node* nextNode = curr->next;\n"
        "        curr->next = prev;\n"
        "        prev = curr;\n"
        "        curr = nextNode;\n"
        "    }\n"
        "    return prev;\n"
        "}"};
    problems[7] = {
        "Find the Middle Node of a Linked List",
        4,
        "Find the middle element of a singly linked list in a single traversal.",
        "Input: 10 -> 20 -> 30 -> 40 -> 50 -> NULL",
        "Output: Middle Node Data: 30",
        "Use Floyd's Cycle / Tortoise and Hare approach: slow moves 1 step, fast moves 2 steps.",
        "Node* findMiddle(Node* head) {\n"
        "    Node* slow = head;\n"
        "    Node* fast = head;\n"
        "    while (fast != nullptr && fast->next != nullptr) {\n"
        "        slow = slow->next;\n"
        "        fast = fast->next->next;\n"
        "    }\n"
        "    return slow;\n"
        "}"};

    // Stacks
    problems[8] = {
        "Check Balanced Parentheses",
        5,
        "Determine if an expression with '(', ')', '{', '}', '[', ']' has balanced brackets.",
        "Input: {[()]}",
        "Output: Balanced (Valid)",
        "Push opening brackets to a stack; on a closing bracket, verify that the top matches.",
        "bool isBalanced(const char expr[]) {\n"
        "    char st[100]; int top = -1;\n"
        "    for (int i = 0; expr[i] != '\\0'; i++) {\n"
        "        char ch = expr[i];\n"
        "        if (ch == '(' || ch == '{' || ch == '[') st[++top] = ch;\n"
        "        else if (ch == ')' || ch == '}' || ch == ']') {\n"
        "            if (top == -1) return false;\n"
        "            char o = st[top--];\n"
        "            if ((ch == ')' && o != '(') || (ch == '}' && o != '{') || (ch == ']' && o != '[')) return false;\n"
        "        }\n"
        "    }\n"
        "    return (top == -1);\n"
        "}"};
    problems[9] = {
        "Reverse a String using a Custom Stack",
        5,
        "Reverse an input character string using a manual LIFO stack.",
        "Input: \"STRUCTURE\"",
        "Output: \"ERUTCURTS\"",
        "Push each character onto the stack until null-terminator, then pop back sequentially.",
        "void reverseString(char str[]) {\n"
        "    char st[100]; int top = -1;\n"
        "    for (int i = 0; str[i] != '\\0'; i++) st[++top] = str[i];\n"
        "    int idx = 0;\n"
        "    while (top >= 0) str[idx++] = st[top--];\n"
        "}"};

    // Queues
    problems[10] = {
        "Implement a Circular Queue using an Array",
        6,
        "Implement enqueue and dequeue operations for a fixed-size circular queue using modulo arithmetic.",
        "Input: Enqueue(10), Enqueue(20), Dequeue(), Enqueue(30)",
        "Output: Dequeued: 10, Front Element: 20",
        "Use (rear + 1) % SIZE for enqueue and (front + 1) % SIZE for dequeue.",
        "class CircularQueue {\n"
        "    int arr[5], front = -1, rear = -1;\n"
        "public:\n"
        "    bool enqueue(int x) {\n"
        "        if ((rear + 1) % 5 == front) return false; // Full\n"
        "        if (front == -1) front = 0;\n"
        "        rear = (rear + 1) % 5; arr[rear] = x; return true;\n"
        "    }\n"
        "    int dequeue() {\n"
        "        if (front == -1) return -1; // Empty\n"
        "        int val = arr[front];\n"
        "        if (front == rear) front = rear = -1;\n"
        "        else front = (front + 1) % 5;\n"
        "        return val;\n"
        "    }\n"
        "};"};
    problems[11] = {
        "Generate Binary Numbers from 1 to N using a Queue",
        6,
        "Generate and display binary representations for numbers 1 through N using a FIFO queue.",
        "Input: N = 4",
        "Output: 1, 10, 11, 100",
        "Enqueue \"1\". In each iteration, dequeue string s, print it, then enqueue s + \"0\" and s + \"1\".",
        "void generateBinary(int n) {\n"
        "    string q[100]; int front = 0, rear = 0;\n"
        "    q[rear++] = \"1\";\n"
        "    for (int i = 1; i <= n; i++) {\n"
        "        string s = q[front++];\n"
        "        cout << s << \" \";\n"
        "        if (rear < 98) {\n"
        "            q[rear++] = s + \"0\";\n"
        "            q[rear++] = s + \"1\";\n"
        "        }\n"
        "    }\n"
        "}"};
}

void CodingPractice::startPracticeSession()
{
    int choice = 0;
    do
    {
        cout << "\n================ CODING PRACTICE MODULE (12 QUESTIONS) ================\n";
        for (int i = 0; i < TOTAL_PRACTICE_PROBLEMS; i++)
        {
            cout << (i + 1) << ". " << problems[i].title << "\n";
        }
        cout << "13. Return to Main Menu\n";
        cout << "------------------------------------------------------------------------\n";
        cout << "Select a problem to solve and inspect (1-13): ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number between 1 and 13.\n";
            continue;
        }

        if (choice >= 1 && choice <= 12)
        {
            displayProblem(choice - 1);
        }
        else if (choice == 13)
        {
            cout << "Returning to Main Menu...\n";
        }
        else
        {
            cout << "Invalid choice! Enter a value between 1 and 13.\n";
        }
    } while (choice != 13);
}

void CodingPractice::displayProblem(int index)
{
    cout << "\n========================================================================\n";
    cout << "Problem " << (index + 1) << ": " << problems[index].title << "\n";
    cout << "------------------------------------------------------------------------\n";
    cout << "[Problem Statement]:\n  " << problems[index].description << "\n\n";
    cout << "[Sample Input]:\n  " << problems[index].sampleInput << "\n\n";
    cout << "[Sample Output]:\n  " << problems[index].sampleOutput << "\n\n";
    cout << "[Conceptual Hint]:\n  " << problems[index].hint << "\n\n";
    cout << "[Custom Reference Solution (No STL)]:\n"
         << problems[index].referenceSolution << "\n";
    cout << "========================================================================\n";
}