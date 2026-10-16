#pragma once

struct SLLNode
{
    int data;
    SLLNode *next;
};

struct DLLNode
{
    int data;
    DLLNode *prev;
    DLLNode *next;
};

class LinearDS
{
private:
    // Singly Linked List
    SLLNode *sllHead;

    // Doubly Linked List
    DLLNode *dllHead;

    // Fixed Bounded Array Stack
    static const int STACK_CAPACITY = 100;
    // const keeps the value fixed capacity i.e. 100
    int stack[STACK_CAPACITY];
    int top;

    // Circular Array Queue
    static const int QUEUE_CAPACITY = 100;
    int queue[QUEUE_CAPACITY];
    int front;
    int rear;

    void clearSLL();  // for deletion 
    void clearDLL();

public:
    LinearDS();  // for initializing
    ~LinearDS(); // destructor for deletion/destroying object

    // Singly Linked List
    void insertNodeSLL(int val);
    void deleteNodeSLL(int val);
    void displayListSLL() const;

    // Doubly Linked List
    void insertNodeDLL(int val);
    void deleteNodeDLL(int val);
    void displayListDLL() const;

    // Stack Operations
    void push(int val);
    void pop();
    void displayStack() const;

    // Queue Operations
    void enqueue(int val);
    void dequeue();
    void displayQueue() const;

    // Interactive Sub-Menu
    void interactiveMenu();
};
