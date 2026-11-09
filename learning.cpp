#include <iostream>
#include "learning.hpp"

using namespace std;

void Learning::showResources(
    const char *video,
    const char *reading,
    const char *practice)
{
    cout << "\n--------------------------------------------\n";
    cout << "LEARNING RESOURCES\n";
    cout << "--------------------------------------------\n";

    cout << "Video Resource:\n";
    cout << video << "\n\n";

    cout << "Reading Resource:\n";
    cout << reading << "\n\n";

    cout << "Practice Resource:\n";
    cout << practice << "\n";

    cout << "--------------------------------------------\n";
}

void Learning::displayTopics()
{
    int choice = 0;

    do
    {
        cout << "\n============================================\n";
        cout << "              DSA LEARNING\n";
        cout << "============================================\n";
        cout << "1. Arrays\n";
        cout << "2. Strings\n";
        cout << "3. Searching Algorithms\n";
        cout << "4. Sorting Algorithms\n";
        cout << "5. Linked Lists\n";
        cout << "6. Stacks\n";
        cout << "7. Queues\n";
        cout << "8. Circular Queue\n";
        cout << "9. Priority Queue\n";
        cout << "10. Binary Search Tree\n";
        cout << "11. Recursion\n";
        cout << "12. Back to Main Menu\n";
        cout << "============================================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a number from 1 to 12: ";
        }

        if (choice >= 1 && choice <= 11)
        {
            showTopicDetails(choice);
        }
        else if (choice == 12)
        {
            cout << "Returning to main menu...\n";
        }
        else
        {
            cout << "Invalid choice. Please select 1 to 12.\n";
        }

    } while (choice != 12);
}

void Learning::showTopicDetails(int choice)
{
    switch (choice)
    {
    case 1:
        explainArrays();
        break;

    case 2:
        explainStrings();
        break;

    case 3:
        explainSearching();
        break;

    case 4:
        explainSorting();
        break;

    case 5:
        explainLinkedLists();
        break;

    case 6:
        explainStacks();
        break;

    case 7:
        explainQueues();
        break;

    case 8:
        explainCircularQueue();
        break;

    case 9:
        explainPriorityQueue();
        break;

    case 10:
        explainBST();
        break;

    case 11:
        explainRecursion();
        break;

    default:
        cout << "Invalid topic.\n";
    }
}

void Learning::explainArrays()
{
    cout << "\n============================================\n";
    cout << "                    ARRAYS\n";
    cout << "============================================\n";

    cout << "\nDefinition:\n";
    cout << "An array is a collection of elements of the same data type\n";
    cout << "stored in contiguous memory locations.\n";

    cout << "\nKey Concepts:\n";
    cout << "- Fixed size\n";
    cout << "- Index-based access\n";
    cout << "- Contiguous memory\n";

    cout << "\nBasic Operations:\n";
    cout << "- Traversal\n";
    cout << "- Insertion\n";
    cout << "- Deletion\n";
    cout << "- Searching\n";
    cout << "- Updating\n";

    cout << "\nExample:\n";
    cout << "int marks[5] = {80, 75, 90, 85, 70};\n";

    cout << "\nTime Complexity:\n";
    cout << "Access: O(1)\n";
    cout << "Search: O(n)\n";
    cout << "Insertion/Deletion: O(n) in general\n";

    cout << "\nSpace Complexity: O(n)\n";

    cout << "\nReal-World Application:\n";
    cout << "Storing marks, sensor readings, temperatures and fixed-size records.\n";

    cout << "\nViva Point:\n";
    cout << "Array elements are accessed using an index.\n";

    showResources(
        "https://www.youtube.com/results?search_query=arrays+data+structures+beginner",
        "https://www.geeksforgeeks.org/dsa/array-data-structure/",
        "https://www.hackerrank.com/domains/data-structures/arrays");
}

void Learning::explainStrings()
{
    cout << "\n============================================\n";
    cout << "                   STRINGS\n";
    cout << "============================================\n";

    cout << "\nDefinition:\n";
    cout << "A string is a sequence of characters used to represent text.\n";

    cout << "\nKey Concepts:\n";
    cout << "- Character sequence\n";
    cout << "- Character indexing\n";
    cout << "- Null terminator in C-style strings\n";

    cout << "\nBasic Operations:\n";
    cout << "- Traversal\n";
    cout << "- Comparison\n";
    cout << "- Searching\n";
    cout << "- Reversal\n";
    cout << "- Concatenation\n";

    cout << "\nExample:\n";
    cout << "char name[] = \"Pari\";\n";

    cout << "\nTime Complexity:\n";
    cout << "Traversal: O(n)\n";
    cout << "Searching: O(n) for basic linear search\n";

    cout << "\nSpace Complexity: O(n)\n";

    cout << "\nReal-World Application:\n";
    cout << "Names, passwords, messages, file names and text processing.\n";

    cout << "\nViva Point:\n";
    cout << "A C-style string ends with the null character '\\0'.\n";

    showResources(
        "https://www.youtube.com/results?search_query=c%2B%2B+strings+beginner",
        "https://www.geeksforgeeks.org/cpp/strings-in-cpp/",
        "https://www.hackerrank.com/domains/cpp/strings");
}

void Learning::explainSearching()
{
    cout << "\n============================================\n";
    cout << "             SEARCHING ALGORITHMS\n";
    cout << "============================================\n";

    cout << "\nDefinition:\n";
    cout << "Searching is the process of finding a required element\n";
    cout << "in a data structure.\n";

    cout << "\nMain Algorithms:\n";
    cout << "- Linear Search\n";
    cout << "- Binary Search\n";

    cout << "\nLinear Search:\n";
    cout << "Checks elements one by one.\n";
    cout << "Time Complexity: O(n)\n";

    cout << "\nBinary Search:\n";
    cout << "Repeatedly divides a sorted search space into two parts.\n";
    cout << "Time Complexity: O(log n)\n";

    cout << "\nSpace Complexity:\n";
    cout << "Iterative versions generally use O(1) extra space.\n";

    cout << "\nReal-World Application:\n";
    cout << "Finding records, products, IDs and database entries.\n";

    cout << "\nViva Point:\n";
    cout << "Binary search requires the data to be sorted.\n";

    showResources(
        "https://www.youtube.com/results?search_query=linear+search+binary+search+data+structures",
        "https://www.geeksforgeeks.org/dsa/searching-algorithms/",
        "https://www.hackerrank.com/domains/algorithms/search");
}

void Learning::explainSorting()
{
    cout << "\n============================================\n";
    cout << "              SORTING ALGORITHMS\n";
    cout << "============================================\n";

    cout << "\nDefinition:\n";
    cout << "Sorting arranges data in a particular order, such as\n";
    cout << "ascending or descending order.\n";

    cout << "\nAlgorithms Covered:\n";
    cout << "- Bubble Sort\n";
    cout << "- Selection Sort\n";
    cout << "- Insertion Sort\n";

    cout << "\nComplexities:\n";
    cout << "Bubble Sort: O(n^2) average/worst case\n";
    cout << "Selection Sort: O(n^2)\n";
    cout << "Insertion Sort: O(n^2) average/worst case\n";

    cout << "\nSpace Complexity:\n";
    cout << "These basic implementations generally use O(1) extra space.\n";

    cout << "\nReal-World Application:\n";
    cout << "Ranking, arranging records and organizing data for faster processing.\n";

    cout << "\nViva Point:\n";
    cout << "Sorting can make searching and data processing easier.\n";

    showResources(
        "https://www.youtube.com/results?search_query=bubble+selection+insertion+sort+beginner",
        "https://www.geeksforgeeks.org/dsa/sorting-algorithms/",
        "https://www.hackerrank.com/domains/algorithms/implementation");
}

void Learning::explainLinkedLists()
{
    cout << "\n============================================\n";
    cout << "                LINKED LISTS\n";
    cout << "============================================\n";

    cout << "\nDefinition:\n";
    cout << "A linked list is a dynamic data structure made of nodes\n";
    cout << "connected using links or pointers.\n";

    cout << "\nTypes:\n";
    cout << "- Singly Linked List\n";
    cout << "- Doubly Linked List\n";

    cout << "\nBasic Operations:\n";
    cout << "- Insertion\n";
    cout << "- Deletion\n";
    cout << "- Traversal\n";
    cout << "- Searching\n";

    cout << "\nTime Complexity:\n";
    cout << "Insertion at beginning: O(1)\n";
    cout << "Search: O(n)\n";
    cout << "Traversal: O(n)\n";

    cout << "\nSpace Complexity: O(n)\n";

    cout << "\nReal-World Application:\n";
    cout << "Dynamic collections, playlists and memory-based structures.\n";

    cout << "\nViva Point:\n";
    cout << "Linked lists do not require contiguous memory locations.\n";

    showResources(
        "https://www.youtube.com/results?search_query=linked+list+c%2B%2B+beginner",
        "https://www.geeksforgeeks.org/dsa/linked-list-data-structure/",
        "https://www.hackerrank.com/domains/data-structures/linked-lists");
}

void Learning::explainStacks()
{
    cout << "\n============================================\n";
    cout << "                    STACKS\n";
    cout << "============================================\n";

    cout << "\nDefinition:\n";
    cout << "A stack is a linear data structure that follows LIFO:\n";
    cout << "Last In, First Out.\n";

    cout << "\nOperations:\n";
    cout << "- Push\n";
    cout << "- Pop\n";
    cout << "- Peek/Top\n";

    cout << "\nTime Complexity:\n";
    cout << "Push: O(1)\n";
    cout << "Pop: O(1)\n";
    cout << "Top: O(1)\n";

    cout << "\nSpace Complexity: O(n)\n";

    cout << "\nReal-World Application:\n";
    cout << "Function calls, undo operations and browser history.\n";

    cout << "\nViva Point:\n";
    cout << "The element inserted last is removed first.\n";

    showResources(
        "https://www.youtube.com/results?search_query=stack+data+structure+c%2B%2B",
        "https://www.geeksforgeeks.org/dsa/stack-data-structure/",
        "https://www.hackerrank.com/domains/data-structures/stacks");
}

void Learning::explainQueues()
{
    cout << "\n============================================\n";
    cout << "                    QUEUES\n";
    cout << "============================================\n";

    cout << "\nDefinition:\n";
    cout << "A queue is a linear data structure that follows FIFO:\n";
    cout << "First In, First Out.\n";

    cout << "\nOperations:\n";
    cout << "- Enqueue\n";
    cout << "- Dequeue\n";
    cout << "- Front\n";

    cout << "\nTime Complexity:\n";
    cout << "Enqueue: O(1)\n";
    cout << "Dequeue: O(1) in a suitable implementation\n";

    cout << "\nSpace Complexity: O(n)\n";

    cout << "\nReal-World Application:\n";
    cout << "Printer queues, task scheduling and customer service systems.\n";

    cout << "\nViva Point:\n";
    cout << "The element inserted first is removed first.\n";

    showResources(
        "https://www.youtube.com/results?search_query=queue+data+structure+c%2B%2B",
        "https://www.geeksforgeeks.org/dsa/queue-data-structure/",
        "https://www.hackerrank.com/domains/data-structures/queues");
}

void Learning::explainCircularQueue()
{
    cout << "\n============================================\n";
    cout << "                 CIRCULAR QUEUE\n";
    cout << "============================================\n";

    cout << "\nDefinition:\n";
    cout << "A circular queue connects the last position of the queue\n";
    cout << "back to the first position.\n";

    cout << "\nKey Idea:\n";
    cout << "The rear can wrap around to the beginning when space is available.\n";

    cout << "\nOperations:\n";
    cout << "- Enqueue\n";
    cout << "- Dequeue\n";
    cout << "- Display\n";

    cout << "\nTime Complexity:\n";
    cout << "Enqueue: O(1)\n";
    cout << "Dequeue: O(1)\n";

    cout << "\nSpace Complexity: O(n)\n";

    cout << "\nReal-World Application:\n";
    cout << "Buffer management, scheduling and streaming systems.\n";

    cout << "\nViva Point:\n";
    cout << "Circular queues reuse previously occupied positions.\n";

    showResources(
        "https://www.youtube.com/results?search_query=circular+queue+data+structure",
        "https://www.geeksforgeeks.org/dsa/circular-queue/",
        "https://www.geeksforgeeks.org/problems/circular-queue/1");
}

void Learning::explainPriorityQueue()
{
    cout << "\n============================================\n";
    cout << "                  PRIORITY QUEUE\n";
    cout << "============================================\n";

    cout << "\nDefinition:\n";
    cout << "A priority queue is a structure where elements are processed\n";
    cout << "according to their priority rather than only their arrival order.\n";

    cout << "\nKey Concepts:\n";
    cout << "- Higher or lower priority can be processed first.\n";
    cout << "- Heap is commonly used for efficient implementation.\n";

    cout << "\nCommon Operations:\n";
    cout << "- Insert\n";
    cout << "- Get highest/lowest priority element\n";
    cout << "- Delete highest/lowest priority element\n";

    cout << "\nTypical Heap Complexity:\n";
    cout << "Insertion: O(log n)\n";
    cout << "Deletion: O(log n)\n";
    cout << "Access priority element: O(1)\n";

    cout << "\nSpace Complexity: O(n)\n";

    cout << "\nReal-World Application:\n";
    cout << "CPU scheduling, emergency systems and task prioritization.\n";

    cout << "\nViva Point:\n";
    cout << "Priority determines which element is processed first.\n";

    showResources(
        "https://www.youtube.com/results?search_query=priority+queue+data+structure+heap",
        "https://www.geeksforgeeks.org/dsa/priority-queue-set-1-introduction/",
        "https://www.geeksforgeeks.org/problems/priority-queue-using-binary-heap/1");
}

void Learning::explainBST()
{
    cout << "\n============================================\n";
    cout << "             BINARY SEARCH TREE\n";
    cout << "============================================\n";

    cout << "\nDefinition:\n";
    cout << "A Binary Search Tree is a binary tree where values smaller\n";
    cout << "than a node are placed on the left and larger values on the right.\n";

    cout << "\nOperations:\n";
    cout << "- Insertion\n";
    cout << "- Searching\n";
    cout << "- Deletion\n";
    cout << "- Tree Traversals\n";

    cout << "\nAverage Time Complexity:\n";
    cout << "Search: O(log n)\n";
    cout << "Insertion: O(log n)\n";
    cout << "Deletion: O(log n)\n";

    cout << "\nWorst Case:\n";
    cout << "Search, insertion and deletion can become O(n)\n";
    cout << "when the tree becomes skewed.\n";

    cout << "\nSpace Complexity: O(n)\n";

    cout << "\nReal-World Application:\n";
    cout << "Searching and maintaining ordered data.\n";

    cout << "\nViva Point:\n";
    cout << "Inorder traversal of a BST produces sorted order.\n";

    showResources(
        "https://www.youtube.com/results?search_query=binary+search+tree+c%2B%2B+beginner",
        "https://www.geeksforgeeks.org/dsa/binary-search-tree-data-structure/",
        "https://www.geeksforgeeks.org/problems/binary-search-tree/1");
}

void Learning::explainRecursion()
{
    cout << "\n============================================\n";
    cout << "                  RECURSION\n";
    cout << "============================================\n";

    cout << "\nDefinition:\n";
    cout << "Recursion is a technique where a function calls itself\n";
    cout << "to solve a smaller version of the same problem.\n";

    cout << "\nTwo Important Parts:\n";
    cout << "- Base Case\n";
    cout << "- Recursive Case\n";

    cout << "\nExamples:\n";
    cout << "- Factorial\n";
    cout << "- Fibonacci\n";
    cout << "- Sum of numbers\n";
    cout << "- Tree traversal\n";

    cout << "\nTime Complexity:\n";
    cout << "Depends on the recursive algorithm.\n";
    cout << "For example, simple recursive factorial is O(n).\n";

    cout << "\nSpace Complexity:\n";
    cout << "Recursive calls use the call stack.\n";

    cout << "\nReal-World Application:\n";
    cout << "Tree traversal, divide-and-conquer algorithms and backtracking.\n";

    cout << "\nViva Point:\n";
    cout << "A recursive function must have a terminating base case.\n";

    showResources(
        "https://www.youtube.com/results?search_query=recursion+c%2B%2B+beginner",
        "https://www.geeksforgeeks.org/dsa/recursion/",
        "https://www.hackerrank.com/domains/algorithms/recursion");
}