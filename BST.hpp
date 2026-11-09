#pragma once

class BST
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
    };

    Node *root;

    Node *insert(Node *current, int value);
    Node *search(Node *current, int value);
    Node *deleteNode(Node *current, int value);

    void inorder(Node *current);
    void preorder(Node *current);
    void postorder(Node *current);

    Node *findMinimum(Node *current);
    Node *findMaximum(Node *current);

    void clearTree(Node *current);

    void insertValue();
    void searchValue();
    void deleteValue();
    void displayTraversals();
    void displayMinimum();
    void displayMaximum();

public:
    BST();

    void interactiveMenu();

    ~BST();
};