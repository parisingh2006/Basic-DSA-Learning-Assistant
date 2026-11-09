#pragma once

class LinearDS
{
private:
    struct SinglyNode
    {
        int data;
        SinglyNode *next;
    };

    struct DoublyNode
    {
        int data;
        DoublyNode *previous;
        DoublyNode *next;
    };

    static const int STACK_SIZE = 50;
    static const int QUEUE_SIZE = 50;

    SinglyNode *singlyHead;
    DoublyNode *doublyHead;

    int stackArray[STACK_SIZE];
    int stackTop;

    int circularQueue[QUEUE_SIZE];
    int queueFront;
    int queueRear;
    int queueCount;

    void singlyLinkedListMenu();
    void doublyLinkedListMenu();
    void stackMenu();
    void circularQueueMenu();

    void insertSinglyAtBeginning(int value);
    void insertSinglyAtEnd(int value);
    void deleteSinglyFromBeginning();
    void deleteSinglyByValue(int value);
    void displaySingly();

    void insertDoublyAtBeginning(int value);
    void insertDoublyAtEnd(int value);
    void deleteDoublyFromBeginning();
    void deleteDoublyByValue(int value);
    void displayDoublyForward();
    void displayDoublyBackward();

    void push(int value);
    void pop();
    void displayStack();

    void enqueue(int value);
    void dequeue();
    void displayCircularQueue();

    void clearSinglyList();
    void clearDoublyList();

public:
    LinearDS();

    void interactiveMenu();

    ~LinearDS();
};