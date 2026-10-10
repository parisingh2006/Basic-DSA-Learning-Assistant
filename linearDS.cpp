#include <iostream>
#include "LinearDS.hpp"

using namespace std;

LinearDS::LinearDS()
{
    sllHead = nullptr;
    dllHead = nullptr;
    top = -1;
    front = -1;
    rear = -1;
}

LinearDS::~LinearDS()
{
    clearSLL();
    clearDLL();
}

void LinearDS::clearSLL()
{
    SLLNode *curr = sllHead;
    while (curr != nullptr)
    {
        SLLNode *nxt = curr->next;
        delete curr;
        curr = nxt;
    }
    sllHead = nullptr;
}

void LinearDS::clearDLL()
{
    DLLNode *curr = dllHead;
    while (curr != nullptr)
    {
        DLLNode *nxt = curr->next;
        delete curr;
        curr = nxt;
    }
    dllHead = nullptr;
}

void LinearDS::insertNodeSLL(int val)
{
    SLLNode *newNode = new SLLNode{val, nullptr};
    if (!sllHead)
    {
        sllHead = newNode;
    }
    else
    {
        SLLNode *temp = sllHead;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Inserted " << val << " into Singly Linked List.\n";
}

void LinearDS::deleteNodeSLL(int val)
{
    if (!sllHead)
    {
        cout << "Singly Linked List is empty!\n";
        return;
    }

    if (sllHead->data == val)
    {
        SLLNode *toDelete = sllHead;
        sllHead = sllHead->next;
        delete toDelete;
        cout << "Deleted " << val << " from Singly Linked List.\n";
        return;
    }

    SLLNode *curr = sllHead;
    while (curr->next != nullptr && curr->next->data != val)
    {
        curr = curr->next;
    }

    if (curr->next == nullptr)
    {
        cout << "Value " << val << " not found in Singly Linked List.\n";
    }
    else
    {
        SLLNode *toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
        cout << "Deleted " << val << " from Singly Linked List.\n";
    }
}

void LinearDS::displayListSLL() const
{
    if (!sllHead)
    {
        cout << "Singly Linked List is empty.\n";
        return;
    }
    cout << "Singly Linked List: ";
    SLLNode *temp = sllHead;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void LinearDS::insertNodeDLL(int val)
{
    DLLNode *newNode = new DLLNode{val, nullptr, nullptr};
    if (!dllHead)
    {
        dllHead = newNode;
    }
    else
    {
        DLLNode *temp = dllHead;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Inserted " << val << " into Doubly Linked List.\n";
}

void LinearDS::deleteNodeDLL(int val)
{
    if (!dllHead)
    {
        cout << "Doubly Linked List is empty!\n";
        return;
    }

    DLLNode *curr = dllHead;
    while (curr != nullptr && curr->data != val)
    {
        curr = curr->next;
    }

    if (!curr)
    {
        cout << "Value " << val << " not found in Doubly Linked List.\n";
        return;
    }

    if (curr == dllHead)
    {
        dllHead = curr->next;
        if (dllHead)
            dllHead->prev = nullptr;
    }
    else
    {
        if (curr->prev)
            curr->prev->next = curr->next;
        if (curr->next)
            curr->next->prev = curr->prev;
    }

    delete curr;
    cout << "Deleted " << val << " from Doubly Linked List.\n";
}

void LinearDS::displayListDLL() const
{
    if (!dllHead)
    {
        cout << "Doubly Linked List is empty.\n";
        return;
    }
    cout << "Doubly Linked List: NULL <-> ";
    DLLNode *temp = dllHead;
    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void LinearDS::push(int val)
{
    if (top >= STACK_CAPACITY - 1)
    {
        cout << "Stack Overflow! Cannot push onto full stack.\n";
        return;
    }
    stack[++top] = val;
    cout << "Pushed " << val << " onto Stack.\n";
}

void LinearDS::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }
    cout << "Popped value: " << stack[top--] << "\n";
}

void LinearDS::displayStack() const
{
    if (top < 0)
    {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack (Top to Bottom): ";
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << "\n";
}

void LinearDS::enqueue(int val)
{
    if ((rear + 1) % QUEUE_CAPACITY == front)
    {
        cout << "Queue Overflow! Circular Queue is full.\n";
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % QUEUE_CAPACITY;
    queue[rear] = val;
    cout << "Enqueued " << val << " into Circular Queue.\n";
}

void LinearDS::dequeue()
{
    if (front == -1)
    {
        cout << "Queue Underflow! Circular Queue is empty.\n";
        return;
    }
    int val = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % QUEUE_CAPACITY;
    }
    cout << "Dequeued value: " << val << "\n";
}

void LinearDS::displayQueue() const
{
    if (front == -1)
    {
        cout << "Circular Queue is empty.\n";
        return;
    }
    cout << "Circular Queue elements: ";
    int i = front;
    while (true)
    {
        cout << queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % QUEUE_CAPACITY;
    }
    cout << "\n";
}

void LinearDS::interactiveMenu()
{
    int choice = 0;
    do
    {
        cout << "\n---------------- LINEAR DATA STRUCTURES WORKBENCH ----------------\n";
        cout << " 1. Singly Linked List: Insert Node\n";
        cout << " 2. Singly Linked List: Delete Node\n";
        cout << " 3. Singly Linked List: Display\n";
        cout << " 4. Doubly Linked List: Insert Node\n";
        cout << " 5. Doubly Linked List: Delete Node\n";
        cout << " 6. Doubly Linked List: Display\n";
        cout << " 7. Stack: Push\n";
        cout << " 8. Stack: Pop\n";
        cout << " 9. Stack: Display\n";
        cout << "10. Circular Queue: Enqueue\n";
        cout << "11. Circular Queue: Dequeue\n";
        cout << "12. Circular Queue: Display\n";
        cout << "13. Back to Main Menu\n";
        cout << "-------------------------------------------------------------------\n";
        cout << "Enter your choice (1-13): ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a valid integer.\n";
            continue;
        }

        int val = 0;
        switch (choice)
        {
        case 1:
            cout << "Enter integer to insert in SLL: ";
            if (cin >> val)
                insertNodeSLL(val);
            break;
        case 2:
            cout << "Enter integer to delete from SLL: ";
            if (cin >> val)
                deleteNodeSLL(val);
            break;
        case 3:
            displayListSLL();
            break;
        case 4:
            cout << "Enter integer to insert in DLL: ";
            if (cin >> val)
                insertNodeDLL(val);
            break;
        case 5:
            cout << "Enter integer to delete from DLL: ";
            if (cin >> val)
                deleteNodeDLL(val);
            break;
        case 6:
            displayListDLL();
            break;
        case 7:
            cout << "Enter integer to push to Stack: ";
            if (cin >> val)
                push(val);
            break;
        case 8:
            pop();
            break;
        case 9:
            displayStack();
            break;
        case 10:
            cout << "Enter integer to enqueue: ";
            if (cin >> val)
                enqueue(val);
            break;
        case 11:
            dequeue();
            break;
        case 12:
            displayQueue();
            break;
        case 13:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid option! Choose between 1 and 13.\n";
        }
    } while (choice != 13);
}