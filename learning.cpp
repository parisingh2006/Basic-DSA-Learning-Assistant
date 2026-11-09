#include <iostream>
#include "learning.hpp"

using namespace std;

void Learning::displayTopics()
{
    int choice = 0;

    do
    {
        cout << "\n============================================================\n";
        cout << "                 DSA LEARNING MODULE\n";
        cout << "============================================================\n";
        cout << " 1. Arrays\n";
        cout << " 2. Strings\n";
        cout << " 3. Searching Algorithms\n";
        cout << " 4. Sorting Algorithms\n";
        cout << " 5. Linked Lists\n";
        cout << " 6. Stacks\n";
        cout << " 7. Queues\n";
        cout << " 8. Circular Queue\n";
        cout << " 9. Priority Queue\n";
        cout << "10. Binary Search Tree\n";
        cout << "11. Recursion\n";
        cout << "12. Return to Main Menu\n";
        cout << "------------------------------------------------------------\n";
        cout << "Enter your choice (1-12): ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "\nInvalid input. Please enter a number from 1 to 12.\n";
            continue;
        }

        if (choice >= 1 && choice <= 11)
        {
            showTopicDetails(choice);
        }
        else if (choice == 12)
        {
            cout << "\nReturning to Main Menu...\n";
        }
        else
        {
            cout << "\nInvalid choice. Please enter a number from 1 to 12.\n";
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
        cout << "Invalid topic choice.\n";
    }
}

void Learning::explainArrays()
{
    cout << "\n============================================================\n";
    cout << "                         ARRAYS\n";
    cout << "============================================================\n";

    cout << "\n[Definition]\n";
    cout << "An array is a linear data structure used to store multiple\n";
    cout << "values of the same data type under one variable name.\n";

    cout << "\n[Purpose]\n";
    cout << "Arrays are useful when a fixed number of related values\n";
    cout << "need to be stored and accessed using an index.\n";

    cout << "\n[Key Concepts]\n";
    cout << "- Elements are accessed using indexes.\n";
    cout << "- The first index is normally 0.\n";
    cout << "- Elements are stored in consecutive memory locations.\n";

    cout << "\n[Basic Operations]\n";
    cout << "- Traversal\n";
    cout << "- Searching\n";
    cout << "- Insertion\n";
    cout << "- Deletion\n";
    cout << "- Updating an element\n";

    cout << "\n[Example]\n";
    cout << "int marks[5] = {70, 82, 65, 90, 76};\n";
    cout << "marks[2] gives the value 65.\n";

    cout << "\n[Advantages]\n";
    cout << "- Easy to understand and implement.\n";
    cout << "- Fast access using an index.\n";
    cout << "- Useful for storing a fixed number of values.\n";

    cout << "\n[Limitations]\n";
    cout << "- Basic arrays have a fixed size.\n";
    cout << "- Insertion and deletion may require shifting elements.\n";

    cout << "\n[Time Complexity]\n";
    cout << "- Access: O(1)\n";
    cout << "- Search: O(n)\n";
    cout << "- Insertion: O(n) in the general case\n";
    cout << "- Deletion: O(n) in the general case\n";

    cout << "\n[Space Complexity]\n";
    cout << "O(n)\n";

    cout << "\n[Real-World Application]\n";
    cout << "Arrays can be used to store marks, prices, temperatures,\n";
    cout << "student records represented by simple values, and other\n";
    cout << "fixed-size collections.\n";

    cout << "\n[Viva Point]\n";
    cout << "Array indexing provides direct access to an element.\n";

    cout << "\n------------------------------------------------------------\n";
}

void Learning::explainStrings()
{
    cout << "\n============================================================\n";
    cout << "                        STRINGS\n";
    cout << "============================================================\n";

    cout << "\n[Definition]\n";
    cout << "A string is a sequence of characters used to represent text.\n";

    cout << "\n[Purpose]\n";
    cout << "Strings are used to store names, messages, words and other\n";
    cout << "text-based information.\n";

    cout << "\n[Key Concepts]\n";
    cout << "- Characters are stored in sequence.\n";
    cout << "- Each character has an index.\n";
    cout << "- C-style strings end with the null character '\\0'.\n";
    cout << "- C++ also provides the string data type.\n";

    cout << "\n[Basic Operations]\n";
    cout << "- Traversal\n";
    cout << "- Searching for a character or substring\n";
    cout << "- Comparing strings\n";
    cout << "- Inserting characters\n";
    cout << "- Deleting characters\n";

    cout << "\n[Example]\n";
    cout << "string name = \"Pari\";\n";
    cout << "The characters can be accessed using indexes.\n";

    cout << "\n[Advantages]\n";
    cout << "- Useful for handling textual data.\n";
    cout << "- Supports many common text-processing operations.\n";

    cout << "\n[Limitations]\n";
    cout << "- Some string operations require traversing many characters.\n";
    cout << "- Care is required when handling character arrays manually.\n";

    cout << "\n[Time Complexity]\n";
    cout << "For a string of length n, a complete traversal takes O(n).\n";

    cout << "\n[Space Complexity]\n";
    cout << "O(n) for storing n characters.\n";

    cout << "\n[Real-World Application]\n";
    cout << "Names, passwords, search queries, messages and file data.\n";

    cout << "\n[Viva Point]\n";
    cout << "A C-style string is terminated by the null character '\\0'.\n";

    cout << "\n------------------------------------------------------------\n";
}

void Learning::explainSearching()
{
    cout << "\n============================================================\n";
    cout << "                  SEARCHING ALGORITHMS\n";
    cout << "============================================================\n";

    cout << "\n[Definition]\n";
    cout << "Searching is the process of finding a required element\n";
    cout << "inside a collection of data.\n";

    cout << "\n[1. Linear Search]\n";
    cout << "Linear search checks elements one by one from the beginning\n";
    cout << "until the required value is found or the collection ends.\n";

    cout << "\nExample:\n";
    cout << "For {10, 25, 30, 45}, searching for 30 checks 10, then 25,\n";
    cout << "and then 30.\n";

    cout << "\n[2. Binary Search]\n";
    cout << "Binary search repeatedly divides a sorted array into two\n";
    cout << "parts and checks the middle element.\n";

    cout << "\n[Important Condition]\n";
    cout << "Binary search requires the data to be sorted.\n";

    cout << "\n[Advantages]\n";
    cout << "- Linear search can work on unsorted data.\n";
    cout << "- Binary search is much faster for large sorted arrays.\n";

    cout << "\n[Limitations]\n";
    cout << "- Linear search can become slow for large data.\n";
    cout << "- Binary search cannot be directly applied to unsorted data.\n";

    cout << "\n[Time Complexity]\n";
    cout << "Linear Search:\n";
    cout << "- Best: O(1)\n";
    cout << "- Average: O(n)\n";
    cout << "- Worst: O(n)\n";

    cout << "\nBinary Search:\n";
    cout << "- Best: O(1)\n";
    cout << "- Average: O(log n)\n";
    cout << "- Worst: O(log n)\n";

    cout << "\n[Space Complexity]\n";
    cout << "Iterative versions generally use O(1) extra space.\n";

    cout << "\n[Real-World Application]\n";
    cout << "Searching records, finding products and locating values\n";
    cout << "in sorted data.\n";

    cout << "\n[Viva Point]\n";
    cout << "Binary search works by repeatedly reducing the search range.\n";

    cout << "\n------------------------------------------------------------\n";
}

void Learning::explainSorting()
{
    cout << "\n============================================================\n";
    cout << "                    SORTING ALGORITHMS\n";
    cout << "============================================================\n";

    cout << "\n[Definition]\n";
    cout << "Sorting is the process of arranging data in a particular\n";
    cout << "order, such as ascending or descending order.\n";

    cout << "\n[Bubble Sort]\n";
    cout << "Repeatedly compares adjacent elements and swaps them when\n";
    cout << "they are in the wrong order.\n";

    cout << "\n[Selection Sort]\n";
    cout << "Finds the smallest element from the unsorted part and places\n";
    cout << "it at the correct position.\n";

    cout << "\n[Insertion Sort]\n";
    cout << "Takes one element at a time and inserts it into its correct\n";
    cout << "position in the already sorted part.\n";

    cout << "\n[Advantages]\n";
    cout << "- Simple algorithms for learning basic sorting concepts.\n";
    cout << "- Easy to implement without advanced libraries.\n";

    cout << "\n[Limitations]\n";
    cout << "- These algorithms are not efficient for very large data.\n";
    cout << "- Bubble, selection and insertion sort generally require\n";
    cout << "  O(n^2) time in their average/worst cases.\n";

    cout << "\n[Time Complexity]\n";
    cout << "Bubble Sort: Best O(n), Average O(n^2), Worst O(n^2)\n";
    cout << "Selection Sort: Best O(n^2), Average O(n^2), Worst O(n^2)\n";
    cout << "Insertion Sort: Best O(n), Average O(n^2), Worst O(n^2)\n";

    cout << "\n[Space Complexity]\n";
    cout << "These basic implementations use O(1) extra space.\n";

    cout << "\n[Real-World Application]\n";
    cout << "Sorting marks, prices, names, scores and other records.\n";

    cout << "\n[Viva Point]\n";
    cout << "Sorting makes data easier to search, compare and analyze.\n";

    cout << "\n------------------------------------------------------------\n";
}

void Learning::explainLinkedLists()
{
    cout << "\n============================================================\n";
    cout << "                       LINKED LISTS\n";
    cout << "============================================================\n";

    cout << "\n[Definition]\n";
    cout << "A linked list is a linear data structure made up of nodes.\n";
    cout << "Each node stores data and one or more links to other nodes.\n";

    cout << "\n[Types]\n";
    cout << "- Singly Linked List\n";
    cout << "- Doubly Linked List\n";

    cout << "\n[Singly Linked List]\n";
    cout << "Each node contains data and a pointer to the next node.\n";

    cout << "\n[Doubly Linked List]\n";
    cout << "Each node contains data, a pointer to the next node and\n";
    cout << "a pointer to the previous node.\n";

    cout << "\n[Basic Operations]\n";
    cout << "- Insertion\n";
    cout << "- Deletion\n";
    cout << "- Traversal\n";
    cout << "- Searching\n";

    cout << "\n[Example Node]\n";
    cout << "struct Node\n";
    cout << "{\n";
    cout << "    int data;\n";
    cout << "    Node* next;\n";
    cout << "};\n";

    cout << "\n[Advantages]\n";
    cout << "- Size can grow or shrink during program execution.\n";
    cout << "- Insertion and deletion can be efficient when the correct\n";
    cout << "  node position is already known.\n";

    cout << "\n[Limitations]\n";
    cout << "- No direct random access like an array.\n";
    cout << "- Extra memory is required for pointers.\n";

    cout << "\n[Time Complexity]\n";
    cout << "Access/Search: O(n) in the general case\n";
    cout << "Insertion at beginning: O(1)\n";
    cout << "Deletion at beginning: O(1)\n";

    cout << "\n[Space Complexity]\n";
    cout << "O(n) for n nodes.\n";

    cout << "\n[Real-World Application]\n";
    cout << "Dynamic lists, memory management concepts and situations\n";
    cout << "where frequent insertion and deletion are required.\n";

    cout << "\n[Viva Point]\n";
    cout << "Linked-list nodes do not need to be stored next to each other\n";
    cout << "in memory.\n";

    cout << "\n------------------------------------------------------------\n";
}

void Learning::explainStacks()
{
    cout << "\n============================================================\n";
    cout << "                          STACKS\n";
    cout << "============================================================\n";

    cout << "\n[Definition]\n";
    cout << "A stack is a linear data structure that follows the\n";
    cout << "LIFO principle: Last In, First Out.\n";

    cout << "\n[Basic Operations]\n";
    cout << "- Push: Adds an element to the top.\n";
    cout << "- Pop: Removes the top element.\n";
    cout << "- Peek: Reads the top element without removing it.\n";

    cout << "\n[Example]\n";
    cout << "If 10, 20 and 30 are pushed in this order, 30 will be\n";
    cout << "removed first.\n";

    cout << "\n[Advantages]\n";
    cout << "- Push and pop operations are normally fast.\n";
    cout << "- Simple structure for problems involving reverse order.\n";

    cout << "\n[Limitations]\n";
    cout << "- Only the top element can be directly accessed.\n";
    cout << "- An array-based stack has a fixed capacity.\n";

    cout << "\n[Time Complexity]\n";
    cout << "Push: O(1)\n";
    cout << "Pop: O(1)\n";
    cout << "Peek: O(1)\n";

    cout << "\n[Space Complexity]\n";
    cout << "O(n) for n stored elements.\n";

    cout << "\n[Real-World Application]\n";
    cout << "Undo operations, function calls, expression evaluation and\n";
    cout << "parentheses checking.\n";

    cout << "\n[Viva Point]\n";
    cout << "Stack follows LIFO.\n";

    cout << "\n------------------------------------------------------------\n";
}

void Learning::explainQueues()
{
    cout << "\n============================================================\n";
    cout << "                          QUEUES\n";
    cout << "============================================================\n";

    cout << "\n[Definition]\n";
    cout << "A queue is a linear data structure that follows the\n";
    cout << "FIFO principle: First In, First Out.\n";

    cout << "\n[Basic Operations]\n";
    cout << "- Enqueue: Adds an element at the rear.\n";
    cout << "- Dequeue: Removes an element from the front.\n";
    cout << "- Front: Reads the first element.\n";

    cout << "\n[Example]\n";
    cout << "If 10, 20 and 30 enter the queue in this order, 10 will\n";
    cout << "leave first.\n";

    cout << "\n[Advantages]\n";
    cout << "- Provides fair first-come-first-served processing.\n";
    cout << "- Enqueue and dequeue can be O(1) with a suitable design.\n";

    cout << "\n[Limitations]\n";
    cout << "- Direct access to middle elements is not provided.\n";
    cout << "- A simple linear array implementation may waste space\n";
    cout << "  after repeated deletions.\n";

    cout << "\n[Time Complexity]\n";
    cout << "Enqueue: O(1)\n";
    cout << "Dequeue: O(1)\n";
    cout << "Front: O(1)\n";

    cout << "\n[Space Complexity]\n";
    cout << "O(n) for n stored elements.\n";

    cout << "\n[Real-World Application]\n";
    cout << "Printer queues, task scheduling, customer service systems\n";
    cout << "and request processing.\n";

    cout << "\n[Viva Point]\n";
    cout << "Queue follows FIFO.\n";

    cout << "\n------------------------------------------------------------\n";
}

void Learning::explainCircularQueue()
{
    cout << "\n============================================================\n";
    cout << "                      CIRCULAR QUEUE\n";
    cout << "============================================================\n";

    cout << "\n[Definition]\n";
    cout << "A circular queue is a queue in which the last position is\n";
    cout << "connected logically back to the first position.\n";

    cout << "\n[Purpose]\n";
    cout << "It allows unused positions at the beginning of an array\n";
    cout << "to be reused after deletion.\n";

    cout << "\n[Basic Operations]\n";
    cout << "- Enqueue\n";
    cout << "- Dequeue\n";
    cout << "- Front\n";
    cout << "- Rear\n";

    cout << "\n[Working]\n";
    cout << "The front and rear positions move using circular indexing.\n";
    cout << "When the rear reaches the last position, it can move back\n";
    cout << "to the first position if space is available.\n";

    cout << "\n[Advantages]\n";
    cout << "- Better use of fixed array space.\n";
    cout << "- Enqueue and dequeue can be performed in O(1).\n";

    cout << "\n[Limitations]\n";
    cout << "- The implementation is slightly more complex than a basic\n";
    cout << "  linear queue.\n";

    cout << "\n[Time Complexity]\n";
    cout << "Enqueue: O(1)\n";
    cout << "Dequeue: O(1)\n";

    cout << "\n[Space Complexity]\n";
    cout << "O(n) for a queue of capacity n.\n";

    cout << "\n[Real-World Application]\n";
    cout << "CPU scheduling, buffering and repeated task processing.\n";

    cout << "\n[Viva Point]\n";
    cout << "Circular queues reuse positions by wrapping around the array.\n";

    cout << "\n------------------------------------------------------------\n";
}

void Learning::explainPriorityQueue()
{
    cout << "\n============================================================\n";
    cout << "                       PRIORITY QUEUE\n";
    cout << "============================================================\n";

    cout << "\n[Definition]\n";
    cout << "A priority queue is a data structure in which elements are\n";
    cout << "processed according to their priority rather than only\n";
    cout << "their arrival order.\n";

    cout << "\n[Working]\n";
    cout << "Each element is associated with a priority. The element with\n";
    cout << "the required highest or lowest priority is processed first,\n";
    cout << "depending on the implementation.\n";

    cout << "\n[Basic Operations]\n";
    cout << "- Insert an element with a priority.\n";
    cout << "- Remove the element with the required priority.\n";
    cout << "- View the highest or lowest priority element.\n";

    cout << "\n[Simple Implementation]\n";
    cout << "For a basic array implementation, elements can be searched\n";
    cout << "to find the required priority before deletion.\n";

    cout << "\n[Advantages]\n";
    cout << "- Important tasks can be processed before less important tasks.\n";
    cout << "- Useful when normal FIFO order is not sufficient.\n";

    cout << "\n[Limitations]\n";
    cout << "- A simple implementation may require extra searching.\n";
    cout << "- Correct priority handling is required.\n";

    cout << "\n[Time Complexity]\n";
    cout << "It depends on the implementation.\n";
    cout << "A simple array-based implementation may take O(n) to find\n";
    cout << "the required priority.\n";

    cout << "\n[Space Complexity]\n";
    cout << "O(n) for n elements.\n";

    cout << "\n[Real-World Application]\n";
    cout << "CPU scheduling, emergency services and task management.\n";

    cout << "\n[Viva Point]\n";
    cout << "A priority queue processes elements based on priority.\n";

    cout << "\n------------------------------------------------------------\n";
}

void Learning::explainBST()
{
    cout << "\n============================================================\n";
    cout << "                    BINARY SEARCH TREE\n";
    cout << "============================================================\n";

    cout << "\n[Definition]\n";
    cout << "A Binary Search Tree (BST) is a binary tree in which values\n";
    cout << "smaller than a node are generally placed in the left subtree\n";
    cout << "and larger values are placed in the right subtree.\n";

    cout << "\n[Basic Operations]\n";
    cout << "- Insertion\n";
    cout << "- Searching\n";
    cout << "- Inorder Traversal\n";
    cout << "- Preorder Traversal\n";
    cout << "- Postorder Traversal\n";

    cout << "\n[Important Property]\n";
    cout << "Inorder traversal of a valid BST produces values in sorted\n";
    cout << "order when duplicate handling is defined consistently.\n";

    cout << "\n[Example]\n";
    cout << "If 50 is the root, values smaller than 50 can be placed on\n";
    cout << "the left and values greater than 50 on the right.\n";

    cout << "\n[Advantages]\n";
    cout << "- Provides an organized way to store searchable data.\n";
    cout << "- Searching can be efficient when the tree is reasonably balanced.\n";

    cout << "\n[Limitations]\n";
    cout << "- A badly unbalanced BST can behave similar to a linked list.\n";
    cout << "- Performance depends on the shape of the tree.\n";

    cout << "\n[Time Complexity]\n";
    cout << "Average search/insertion: O(log n)\n";
    cout << "Worst-case search/insertion: O(n)\n";

    cout << "\n[Space Complexity]\n";
    cout << "O(n) for n nodes.\n";

    cout << "\n[Real-World Application]\n";
    cout << "Searching and maintaining ordered data in applications where\n";
    cout << "tree-based organization is useful.\n";

    cout << "\n[Viva Point]\n";
    cout << "Inorder traversal of a BST gives sorted output.\n";

    cout << "\n------------------------------------------------------------\n";
}

void Learning::explainRecursion()
{
    cout << "\n============================================================\n";
    cout << "                         RECURSION\n";
    cout << "============================================================\n";

    cout << "\n[Definition]\n";
    cout << "Recursion is a programming technique in which a function\n";
    cout << "calls itself to solve a smaller version of the same problem.\n";

    cout << "\n[Two Important Parts]\n";
    cout << "1. Base Case: Stops further recursive calls.\n";
    cout << "2. Recursive Case: Calls the function with a smaller problem.\n";

    cout << "\n[Example: Factorial]\n";
    cout << "factorial(n) = n * factorial(n - 1)\n";
    cout << "The base case can be factorial(0) = 1.\n";

    cout << "\n[Working]\n";
    cout << "Each recursive call is stored in the function call stack.\n";
    cout << "The calls return after reaching the base case.\n";

    cout << "\n[Advantages]\n";
    cout << "- Can make some problems easier to express.\n";
    cout << "- Useful for tree traversal and divide-and-conquer problems.\n";

    cout << "\n[Limitations]\n";
    cout << "- Too many recursive calls can use a large amount of stack memory.\n";
    cout << "- Missing or incorrect base cases can cause infinite recursion.\n";

    cout << "\n[Time Complexity]\n";
    cout << "Depends on the recursive algorithm and the number of calls.\n";

    cout << "\n[Space Complexity]\n";
    cout << "Depends on recursion depth because function calls use stack memory.\n";

    cout << "\n[Real-World Application]\n";
    cout << "Tree traversal, directory traversal, mathematical problems\n";
    cout << "and divide-and-conquer algorithms.\n";

    cout << "\n[Viva Point]\n";
    cout << "Every recursive function must have a suitable base case.\n";

    cout << "\n------------------------------------------------------------\n";
}