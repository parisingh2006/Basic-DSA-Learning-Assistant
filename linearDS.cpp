#include <iostream>
#include "linearDS.hpp"

using namespace std;

LinearDS::LinearDS()
{
    singlyHead = NULL;
    doublyHead = NULL;

    stackTop = -1;

    queueFront = 0;
    queueRear = -1;
    queueCount = 0;
}

/* =========================================================
   SINGLY LINKED LIST
   ========================================================= */

void LinearDS::insertSinglyAtBeginning(int value)
{
    SinglyNode *newNode = new SinglyNode;

    newNode->data = value;
    newNode->next = singlyHead;

    singlyHead = newNode;

    cout << "Node inserted at beginning successfully.\n";
}

void LinearDS::insertSinglyAtEnd(int value)
{
    SinglyNode *newNode = new SinglyNode;

    newNode->data = value;
    newNode->next = NULL;

    if (singlyHead == NULL)
    {
        singlyHead = newNode;
        cout << "Node inserted successfully.\n";
        return;
    }

    SinglyNode *current = singlyHead;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;

    cout << "Node inserted at end successfully.\n";
}

void LinearDS::deleteSinglyFromBeginning()
{
    if (singlyHead == NULL)
    {
        cout << "Singly linked list is empty.\n";
        return;
    }

    SinglyNode *temporary = singlyHead;

    singlyHead = singlyHead->next;

    cout << "Deleted value: " << temporary->data << "\n";

    delete temporary;
}

void LinearDS::deleteSinglyByValue(int value)
{
    if (singlyHead == NULL)
    {
        cout << "Singly linked list is empty.\n";
        return;
    }

    if (singlyHead->data == value)
    {
        SinglyNode *temporary = singlyHead;

        singlyHead = singlyHead->next;

        delete temporary;

        cout << "Node deleted successfully.\n";
        return;
    }

    SinglyNode *current = singlyHead;

    while (current->next != NULL &&
           current->next->data != value)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        cout << "Value not found in the list.\n";
        return;
    }

    SinglyNode *temporary = current->next;

    current->next = temporary->next;

    delete temporary;

    cout << "Node deleted successfully.\n";
}

void LinearDS::displaySingly()
{
    if (singlyHead == NULL)
    {
        cout << "Singly linked list is empty.\n";
        return;
    }

    SinglyNode *current = singlyHead;

    cout << "Singly Linked List:\n";

    while (current != NULL)
    {
        cout << current->data;

        if (current->next != NULL)
        {
            cout << " -> ";
        }

        current = current->next;
    }

    cout << " -> NULL\n";
}

void LinearDS::singlyLinkedListMenu()
{
    int choice = 0;

    do
    {
        cout << "\n========================================\n";
        cout << "        SINGLY LINKED LIST\n";
        cout << "========================================\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete by Value\n";
        cout << "5. Display List\n";
        cout << "6. Back\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a number from 1 to 6: ";
        }

        int value;

        switch (choice)
        {
        case 1:

            cout << "Enter value: ";

            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Invalid value. Enter an integer: ";
            }

            insertSinglyAtBeginning(value);
            break;

        case 2:

            cout << "Enter value: ";

            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Invalid value. Enter an integer: ";
            }

            insertSinglyAtEnd(value);
            break;

        case 3:

            deleteSinglyFromBeginning();
            break;

        case 4:

            cout << "Enter value to delete: ";

            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Invalid value. Enter an integer: ";
            }

            deleteSinglyByValue(value);
            break;

        case 5:

            displaySingly();
            break;

        case 6:

            cout << "Returning to Data Structure Workbench...\n";
            break;

        default:

            cout << "Invalid choice. Please select 1 to 6.\n";
        }

    } while (choice != 6);
}

/* =========================================================
   DOUBLY LINKED LIST
   ========================================================= */

void LinearDS::insertDoublyAtBeginning(int value)
{
    DoublyNode *newNode = new DoublyNode;

    newNode->data = value;
    newNode->previous = NULL;
    newNode->next = doublyHead;

    if (doublyHead != NULL)
    {
        doublyHead->previous = newNode;
    }

    doublyHead = newNode;

    cout << "Node inserted at beginning successfully.\n";
}

void LinearDS::insertDoublyAtEnd(int value)
{
    DoublyNode *newNode = new DoublyNode;

    newNode->data = value;
    newNode->next = NULL;

    if (doublyHead == NULL)
    {
        newNode->previous = NULL;
        doublyHead = newNode;

        cout << "Node inserted successfully.\n";
        return;
    }

    DoublyNode *current = doublyHead;

    while (current->next != NULL)
    {
        current = current->next;
    }

    newNode->previous = current;

    current->next = newNode;

    cout << "Node inserted at end successfully.\n";
}

void LinearDS::deleteDoublyFromBeginning()
{
    if (doublyHead == NULL)
    {
        cout << "Doubly linked list is empty.\n";
        return;
    }

    DoublyNode *temporary = doublyHead;

    doublyHead = doublyHead->next;

    if (doublyHead != NULL)
    {
        doublyHead->previous = NULL;
    }

    cout << "Deleted value: " << temporary->data << "\n";

    delete temporary;
}

void LinearDS::deleteDoublyByValue(int value)
{
    if (doublyHead == NULL)
    {
        cout << "Doubly linked list is empty.\n";
        return;
    }

    DoublyNode *current = doublyHead;

    while (current != NULL &&
           current->data != value)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "Value not found in the list.\n";
        return;
    }

    if (current->previous != NULL)
    {
        current->previous->next = current->next;
    }
    else
    {
        doublyHead = current->next;
    }

    if (current->next != NULL)
    {
        current->next->previous = current->previous;
    }

    delete current;

    cout << "Node deleted successfully.\n";
}

void LinearDS::displayDoublyForward()
{
    if (doublyHead == NULL)
    {
        cout << "Doubly linked list is empty.\n";
        return;
    }

    DoublyNode *current = doublyHead;

    cout << "Forward Direction:\n";

    while (current != NULL)
    {
        cout << current->data;

        if (current->next != NULL)
        {
            cout << " <-> ";
        }

        current = current->next;
    }

    cout << " -> NULL\n";
}

void LinearDS::displayDoublyBackward()
{
    if (doublyHead == NULL)
    {
        cout << "Doubly linked list is empty.\n";
        return;
    }

    DoublyNode *current = doublyHead;

    while (current->next != NULL)
    {
        current = current->next;
    }

    cout << "Backward Direction:\n";

    while (current != NULL)
    {
        cout << current->data;

        if (current->previous != NULL)
        {
            cout << " <-> ";
        }

        current = current->previous;
    }

    cout << " -> NULL\n";
}

void LinearDS::doublyLinkedListMenu()
{
    int choice = 0;

    do
    {
        cout << "\n========================================\n";
        cout << "         DOUBLY LINKED LIST\n";
        cout << "========================================\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete by Value\n";
        cout << "5. Display Forward\n";
        cout << "6. Display Backward\n";
        cout << "7. Back\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a number from 1 to 7: ";
        }

        int value;

        switch (choice)
        {
        case 1:

            cout << "Enter value: ";

            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Invalid value. Enter an integer: ";
            }

            insertDoublyAtBeginning(value);
            break;

        case 2:

            cout << "Enter value: ";

            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Invalid value. Enter an integer: ";
            }

            insertDoublyAtEnd(value);
            break;

        case 3:

            deleteDoublyFromBeginning();
            break;

        case 4:

            cout << "Enter value to delete: ";

            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Invalid value. Enter an integer: ";
            }

            deleteDoublyByValue(value);
            break;

        case 5:

            displayDoublyForward();
            break;

        case 6:

            displayDoublyBackward();
            break;

        case 7:

            cout << "Returning to Data Structure Workbench...\n";
            break;

        default:

            cout << "Invalid choice. Please select 1 to 7.\n";
        }

    } while (choice != 7);
}

/* =========================================================
   STACK
   ========================================================= */

void LinearDS::push(int value)
{
    if (stackTop == STACK_SIZE - 1)
    {
        cout << "Stack Overflow. Cannot push more elements.\n";
        return;
    }

    stackTop++;

    stackArray[stackTop] = value;

    cout << "Value pushed successfully.\n";
}

void LinearDS::pop()
{
    if (stackTop == -1)
    {
        cout << "Stack Underflow. Stack is empty.\n";
        return;
    }

    cout << "Popped value: "
         << stackArray[stackTop]
         << "\n";

    stackTop--;
}

void LinearDS::displayStack()
{
    if (stackTop == -1)
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack from TOP to BOTTOM:\n";

    for (int i = stackTop; i >= 0; i--)
    {
        cout << stackArray[i] << "\n";
    }
}

void LinearDS::stackMenu()
{
    int choice = 0;

    do
    {
        cout << "\n========================================\n";
        cout << "                STACK\n";
        cout << "========================================\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Back\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a number from 1 to 4: ";
        }

        int value;

        switch (choice)
        {
        case 1:

            cout << "Enter value: ";

            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Invalid value. Enter an integer: ";
            }

            push(value);
            break;

        case 2:

            pop();
            break;

        case 3:

            displayStack();
            break;

        case 4:

            cout << "Returning to Data Structure Workbench...\n";
            break;

        default:

            cout << "Invalid choice. Please select 1 to 4.\n";
        }

    } while (choice != 4);
}

/* =========================================================
   CIRCULAR QUEUE
   ========================================================= */

void LinearDS::enqueue(int value)
{
    if (queueCount == QUEUE_SIZE)
    {
        cout << "Queue Overflow. Circular queue is full.\n";
        return;
    }

    queueRear = (queueRear + 1) % QUEUE_SIZE;

    circularQueue[queueRear] = value;

    queueCount++;

    cout << "Value inserted into circular queue.\n";
}

void LinearDS::dequeue()
{
    if (queueCount == 0)
    {
        cout << "Queue Underflow. Circular queue is empty.\n";
        return;
    }

    cout << "Deleted value: "
         << circularQueue[queueFront]
         << "\n";

    queueFront = (queueFront + 1) % QUEUE_SIZE;

    queueCount--;

    if (queueCount == 0)
    {
        queueFront = 0;
        queueRear = -1;
    }
}

void LinearDS::displayCircularQueue()
{
    if (queueCount == 0)
    {
        cout << "Circular queue is empty.\n";
        return;
    }

    cout << "Circular Queue:\n";

    int index = queueFront;

    for (int i = 0; i < queueCount; i++)
    {
        cout << circularQueue[index];

        if (i < queueCount - 1)
        {
            cout << " <- ";
        }

        index = (index + 1) % QUEUE_SIZE;
    }

    cout << "\n";
}

void LinearDS::circularQueueMenu()
{
    int choice = 0;

    do
    {
        cout << "\n========================================\n";
        cout << "            CIRCULAR QUEUE\n";
        cout << "========================================\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Back\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a number from 1 to 4: ";
        }

        int value;

        switch (choice)
        {
        case 1:

            cout << "Enter value: ";

            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Invalid value. Enter an integer: ";
            }

            enqueue(value);
            break;

        case 2:

            dequeue();
            break;

        case 3:

            displayCircularQueue();
            break;

        case 4:

            cout << "Returning to Data Structure Workbench...\n";
            break;

        default:

            cout << "Invalid choice. Please select 1 to 4.\n";
        }

    } while (choice != 4);
}

/* =========================================================
   MEMORY CLEANUP
   ========================================================= */

void LinearDS::clearSinglyList()
{
    while (singlyHead != NULL)
    {
        SinglyNode *temporary = singlyHead;

        singlyHead = singlyHead->next;

        delete temporary;
    }
}

void LinearDS::clearDoublyList()
{
    while (doublyHead != NULL)
    {
        DoublyNode *temporary = doublyHead;

        doublyHead = doublyHead->next;

        delete temporary;
    }
}

/* =========================================================
   MAIN DATA STRUCTURE WORKBENCH
   ========================================================= */

void LinearDS::interactiveMenu()
{
    int choice = 0;

    do
    {
        cout << "\n============================================\n";
        cout << "       DATA STRUCTURE WORKBENCH\n";
        cout << "============================================\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Stack\n";
        cout << "4. Circular Queue\n";
        cout << "5. Back to Main Menu\n";
        cout << "============================================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a number from 1 to 5: ";
        }

        switch (choice)
        {
        case 1:

            singlyLinkedListMenu();
            break;

        case 2:

            doublyLinkedListMenu();
            break;

        case 3:

            stackMenu();
            break;

        case 4:

            circularQueueMenu();
            break;

        case 5:

            cout << "Returning to main menu...\n";
            break;

        default:

            cout << "Invalid choice. Please select 1 to 5.\n";
        }

    } while (choice != 5);
}

/* =========================================================
   DESTRUCTOR
   ========================================================= */

LinearDS::~LinearDS()
{
    clearSinglyList();
    clearDoublyList();
}