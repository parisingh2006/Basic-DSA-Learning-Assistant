#include <iostream>
#include "Learning.hpp"

using namespace std;

void Learning::displayTopics()
{
    int choice = 0;
    do
    {
        cout << "\n=================== DSA LEARNING MODULE ===================\n";
        cout << "1. Topic 1: Arrays\n";
        cout << "2. Topic 2: Searching Algorithms\n";
        cout << "3. Topic 3: Sorting Algorithms\n";
        cout << "4. Topic 4: Linked Lists\n";
        cout << "5. Topic 5: Stacks\n";
        cout << "6. Topic 6: Queues\n";
        cout << "7. Return to Main Menu\n";
        cout << "-----------------------------------------------------------\n";
        cout << "Enter your topic choice (1-7): ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number between 1 and 7.\n";
            continue;
        }

        if (choice >= 1 && choice <= 6)
        {
            showTopicDetails(choice);
        }
        else if (choice == 7)
        {
            cout << "Returning to Main Menu...\n";
        }
        else
        {
            cout << "Invalid choice! Enter a value between 1 and 7.\n";
        }
    } while (choice != 7);
}

void Learning::showTopicDetails(int choice)
{
    switch (choice)
    {
    case 1:
        explainArrays();
        break;
    case 2:
        explainSearching();
        break;
    case 3:
        explainSorting();
        break;
    case 4:
        explainLinkedLists();
        break;
    case 5:
        explainStacks();
        break;
    case 6:
        explainQueues();
        break;
    default:
        break;
    }
}

void Learning::explainArrays()
{
    cout << "\n-------------------- TOPIC 1: ARRAYS --------------------\n";
    cout << "[Definition]:\n";
    cout << "  A contiguous collection of elements of identical data type accessible via numerical indices.\n\n";
    cout << "[Academic Explanation]:\n";
    cout << "  Arrays are static or dynamic linear structures mapped directly into contiguous physical memory.\n";
    cout << "  Base address indexing enables immediate address arithmetic: Address(A[i]) = Base + i * sizeof(Type).\n\n";
    cout << "[Code Example (C++)]:\n";
    cout << "  int arr[5] = {10, 20, 30, 40, 50};\n";
    cout << "  for(int i = 0; i < 5; i++) cout << arr[i] << \" \";\n\n";
    cout << "[Advantages]:\n";
    cout << "  - Instant O(1) random access by index.\n";
    cout << "  - Optimal spatial locality for CPU caching.\n\n";
    cout << "[Limitations]:\n";
    cout << "  - Fixed capacity once allocated.\n";
    cout << "  - Expensive O(n) insertions and deletions due to element shifting.\n\n";
    cout << "[Time Complexity]:\n";
    cout << "  - Access: Best O(1), Average O(1), Worst O(1)\n";
    cout << "  - Search: Best O(1), Average O(n), Worst O(n)\n";
    cout << "  - Insertion/Deletion: Best O(1), Average O(n), Worst O(n)\n\n";
    cout << "[Space Complexity]: O(n) total space, O(1) auxiliary space.\n";
    cout << "---------------------------------------------------------\n";
}

void Learning::explainSearching()
{
    cout << "\n------------------ TOPIC 2: SEARCHING -------------------\n";
    cout << "[Definition]:\n";
    cout << "  Algorithms designed to locate a target key within a given data collection.\n\n";
    cout << "[Academic Explanation]:\n";
    cout << "  - Linear Search: Evaluates every element sequentially from index 0 to n-1. Applicable to unsorted data.\n";
    cout << "  - Binary Search: Divide-and-conquer strategy on pre-sorted data comparing middle element.\n\n";
    cout << "[Code Example (Binary Search)]:\n";
    cout << "  int low = 0, high = n - 1;\n";
    cout << "  while (low <= high) {\n";
    cout << "      int mid = low + (high - low) / 2;\n";
    cout << "      if (arr[mid] == target) return mid;\n";
    cout << "      else if (arr[mid] < target) low = mid + 1;\n";
    cout << "      else high = mid - 1;\n";
    cout << "  }\n\n";
    cout << "[Advantages]:\n";
    cout << "  - Binary Search reduces large search intervals exponentially.\n\n";
    cout << "[Limitations]:\n";
    cout << "  - Binary Search requires strictly sorted contiguous or indexable data.\n\n";
    cout << "[Time Complexity]:\n";
    cout << "  - Linear Search: Best O(1), Average O(n), Worst O(n)\n";
    cout << "  - Binary Search: Best O(1), Average O(log n), Worst O(log n)\n\n";
    cout << "[Space Complexity]: O(1) iterative, O(log n) recursive call stack.\n";
    cout << "---------------------------------------------------------\n";
}

void Learning::explainSorting()
{
    cout << "\n------------------- TOPIC 3: SORTING --------------------\n";
    cout << "[Definition]:\n";
    cout << "  Systematically reordering elements according to a strict weak ordering criterion (ascending or descending).\n\n";
    cout << "[Academic Explanation]:\n";
    cout << "  - Bubble Sort: Successively compares and swaps adjacent out-of-order pairs.\n";
    cout << "  - Selection Sort: Iteratively extracts the minimum element and places it into the sorted partition.\n";
    cout << "  - Insertion Sort: Inserts each element into its proper position within a sorted sub-array.\n\n";
    cout << "[Code Example (Bubble Sort)]:\n";
    cout << "  for (int i = 0; i < n - 1; i++) {\n";
    cout << "      for (int j = 0; j < n - i - 1; j++) {\n";
    cout << "          if (arr[j] > arr[j + 1]) {\n";
    cout << "              int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;\n";
    cout << "          }\n";
    cout << "      }\n";
    cout << "  }\n\n";
    cout << "[Advantages]:\n";
    cout << "  - Simple to implement and intuitive for small arrays.\n\n";
    cout << "[Limitations]:\n";
    cout << "  - Poor quadratic scalability on larger inputs.\n\n";
    cout << "[Time Complexity]:\n";
    cout << "  - Bubble Sort: Best O(n), Average O(n^2), Worst O(n^2)\n";
    cout << "  - Insertion Sort: Best O(n), Average O(n^2), Worst O(n^2)\n";
    cout << "  - Selection Sort: Best O(n^2), Average O(n^2), Worst O(n^2)\n\n";
    cout << "[Space Complexity]: O(1) auxiliary space (in-place).\n";
    cout << "---------------------------------------------------------\n";
}

void Learning::explainLinkedLists()
{
    cout << "\n----------------- TOPIC 4: LINKED LISTS -----------------\n";
    cout << "[Definition]:\n";
    cout << "  A sequence of distinct dynamic nodes where each node encapsulates data and pointer references to adjacent nodes.\n\n";
    cout << "[Academic Explanation]:\n";
    cout << "  Unlike arrays, linked lists are stored non-contiguously on the heap. Nodes are dynamically allocated\n";
    cout << "  and connected via pointers (single or double links).\n\n";
    cout << "[Code Example (Singly Linked List Node)]:\n";
    cout << "  struct Node {\n";
    cout << "      int data;\n";
    cout << "      Node* next;\n";
    cout << "  };\n";
    cout << "  Node* head = new Node{10, nullptr};\n\n";
    cout << "[Advantages]:\n";
    cout << "  - Dynamic size without reallocations.\n";
    cout << "  - O(1) insertions/deletions at known pointer positions without memory shifts.\n\n";
    cout << "[Limitations]:\n";
    cout << "  - No random indexing; sequential traversal requires O(n).\n";
    cout << "  - Extra memory overhead for pointer variables per node.\n\n";
    cout << "[Time Complexity]:\n";
    cout << "  - Access: Best O(1), Average O(n), Worst O(n)\n";
    cout << "  - Insertion at Head: Best O(1), Average O(1), Worst O(1)\n";
    cout << "  - Deletion at Head: Best O(1), Average O(1), Worst O(1)\n\n";
    cout << "[Space Complexity]: O(n) heap memory for n nodes.\n";
    cout << "---------------------------------------------------------\n";
}

void Learning::explainStacks()
{
    cout << "\n-------------------- TOPIC 5: STACKS --------------------\n";
    cout << "[Definition]:\n";
    cout << "  A linear data container adhering strictly to the Last-In, First-Out (LIFO) protocol.\n\n";
    cout << "[Academic Explanation]:\n";
    cout << "  Additions and removals occur exclusively at a single endpoint designated as the 'top'.\n";
    cout << "  Commonly applied in syntax parsing, recursion runtime call stacks, and expression evaluations.\n\n";
    cout << "[Code Example (Array Implementation)]:\n";
    cout << "  int top = -1, stack[100];\n";
    cout << "  void push(int x) { if (top < 99) stack[++top] = x; }\n";
    cout << "  int pop() { return (top >= 0) ? stack[top--] : -1; }\n\n";
    cout << "[Advantages]:\n";
    cout << "  - Deterministic O(1) top operations without data movement.\n\n";
    cout << "[Limitations]:\n";
    cout << "  - Direct access to intermediate or bottom elements is prohibited.\n";
    cout << "  - Susceptible to stack overflow if bounded by fixed size.\n\n";
    cout << "[Time Complexity]:\n";
    cout << "  - Push: O(1)\n";
    cout << "  - Pop: O(1)\n";
    cout << "  - Peek: O(1)\n\n";
    cout << "[Space Complexity]: O(n) total elements stored, O(1) auxiliary per operation.\n";
    cout << "---------------------------------------------------------\n";
}

void Learning::explainQueues()
{
    cout << "\n-------------------- TOPIC 6: QUEUES --------------------\n";
    cout << "[Definition]:\n";
    cout << "  A linear data container adhering strictly to the First-In, First-Out (FIFO) principle.\n\n";
    cout << "[Academic Explanation]:\n";
    cout << "  Items enter via the rear terminal (enqueue) and vacate through the front terminal (dequeue).\n";
    cout << "  Circular arrays or linked lists prevent memory wastage when wrapping indices.\n\n";
    cout << "[Code Example (Linear Queue)]:\n";
    cout << "  int queue[100], front = 0, rear = 0;\n";
    cout << "  void enqueue(int x) { queue[rear++] = x; }\n";
    cout << "  int dequeue() { return queue[front++]; }\n\n";
    cout << "[Advantages]:\n";
    cout << "  - Natural FIFO fairness for task scheduling and breadth-first search traversals.\n\n";
    cout << "[Limitations]:\n";
    cout << "  - Simple linear arrays suffer from false overflow without circular index wrapping.\n\n";
    cout << "[Time Complexity]:\n";
    cout << "  - Enqueue: O(1)\n";
    cout << "  - Dequeue: O(1)\n";
    cout << "  - Front: O(1)\n\n";
    cout << "[Space Complexity]: O(n) total elements, O(1) auxiliary per operation.\n";
    cout << "---------------------------------------------------------\n";
}