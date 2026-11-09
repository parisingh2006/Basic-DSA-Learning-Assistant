#include <iostream>
#include "BST.hpp"

using namespace std;

BST::BST()
{
    root = NULL;
}

BST::Node *BST::insert(Node *current, int value)
{
    if (current == NULL)
    {
        Node *newNode = new Node;

        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (value < current->data)
    {
        current->left = insert(current->left, value);
    }
    else if (value > current->data)
    {
        current->right = insert(current->right, value);
    }
    else
    {
        cout << "Duplicate value ignored. "
             << "BST already contains " << value << ".\n";
    }

    return current;
}

BST::Node *BST::search(Node *current, int value)
{
    if (current == NULL)
    {
        return NULL;
    }

    if (current->data == value)
    {
        return current;
    }

    if (value < current->data)
    {
        return search(current->left, value);
    }

    return search(current->right, value);
}

BST::Node *BST::findMinimum(Node *current)
{
    if (current == NULL)
    {
        return NULL;
    }

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

BST::Node *BST::findMaximum(Node *current)
{
    if (current == NULL)
    {
        return NULL;
    }

    while (current->right != NULL)
    {
        current = current->right;
    }

    return current;
}

BST::Node *BST::deleteNode(Node *current, int value)
{
    if (current == NULL)
    {
        return NULL;
    }

    if (value < current->data)
    {
        current->left =
            deleteNode(current->left, value);
    }
    else if (value > current->data)
    {
        current->right =
            deleteNode(current->right, value);
    }
    else
    {
        // Case 1: No child
        if (current->left == NULL &&
            current->right == NULL)
        {
            delete current;
            return NULL;
        }

        // Case 2: Only right child
        if (current->left == NULL)
        {
            Node *temporary = current->right;

            delete current;

            return temporary;
        }

        // Case 3: Only left child
        if (current->right == NULL)
        {
            Node *temporary = current->left;

            delete current;

            return temporary;
        }

        // Case 4: Two children
        Node *successor =
            findMinimum(current->right);

        current->data = successor->data;

        current->right =
            deleteNode(current->right,
                       successor->data);
    }

    return current;
}

void BST::inorder(Node *current)
{
    if (current == NULL)
    {
        return;
    }

    inorder(current->left);

    cout << current->data << " ";

    inorder(current->right);
}

void BST::preorder(Node *current)
{
    if (current == NULL)
    {
        return;
    }

    cout << current->data << " ";

    preorder(current->left);

    preorder(current->right);
}

void BST::postorder(Node *current)
{
    if (current == NULL)
    {
        return;
    }

    postorder(current->left);

    postorder(current->right);

    cout << current->data << " ";
}

void BST::insertValue()
{
    int value;

    cout << "Enter value to insert: ";

    while (!(cin >> value))
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Enter an integer: ";
    }

    if (search(root, value) != NULL)
    {
        cout << "Value already exists in the BST.\n";
        return;
    }

    root = insert(root, value);

    cout << "Value inserted successfully.\n";
}

void BST::searchValue()
{
    if (root == NULL)
    {
        cout << "BST is empty.\n";
        return;
    }

    int value;

    cout << "Enter value to search: ";

    while (!(cin >> value))
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Enter an integer: ";
    }

    Node *result = search(root, value);

    if (result != NULL)
    {
        cout << "Value " << value
             << " was found in the BST.\n";
    }
    else
    {
        cout << "Value " << value
             << " was not found in the BST.\n";
    }
}

void BST::deleteValue()
{
    if (root == NULL)
    {
        cout << "BST is empty.\n";
        return;
    }

    int value;

    cout << "Enter value to delete: ";

    while (!(cin >> value))
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Enter an integer: ";
    }

    if (search(root, value) == NULL)
    {
        cout << "Value not found in the BST.\n";
        return;
    }

    root = deleteNode(root, value);

    cout << "Value deleted successfully.\n";
}

void BST::displayTraversals()
{
    if (root == NULL)
    {
        cout << "BST is empty.\n";
        return;
    }

    cout << "\n========== BST TRAVERSALS ==========\n";

    cout << "Inorder   : ";
    inorder(root);
    cout << "\n";

    cout << "Preorder  : ";
    preorder(root);
    cout << "\n";

    cout << "Postorder : ";
    postorder(root);
    cout << "\n";
}

void BST::displayMinimum()
{
    if (root == NULL)
    {
        cout << "BST is empty.\n";
        return;
    }

    Node *minimum = findMinimum(root);

    cout << "Minimum value: "
         << minimum->data
         << "\n";
}

void BST::displayMaximum()
{
    if (root == NULL)
    {
        cout << "BST is empty.\n";
        return;
    }

    Node *maximum = findMaximum(root);

    cout << "Maximum value: "
         << maximum->data
         << "\n";
}

void BST::clearTree(Node *current)
{
    if (current == NULL)
    {
        return;
    }

    clearTree(current->left);
    clearTree(current->right);

    delete current;
}

void BST::interactiveMenu()
{
    int choice = 0;

    do
    {
        cout << "\n========================================\n";
        cout << "          BINARY SEARCH TREE\n";
        cout << "========================================\n";
        cout << "1. Insert Value\n";
        cout << "2. Search Value\n";
        cout << "3. Delete Value\n";
        cout << "4. Display Traversals\n";
        cout << "5. Find Minimum\n";
        cout << "6. Find Maximum\n";
        cout << "7. Back to Main Menu\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a number from 1 to 7: ";
        }

        switch (choice)
        {
        case 1:
            insertValue();
            break;

        case 2:
            searchValue();
            break;

        case 3:
            deleteValue();
            break;

        case 4:
            displayTraversals();
            break;

        case 5:
            displayMinimum();
            break;

        case 6:
            displayMaximum();
            break;

        case 7:
            cout << "Returning to main menu...\n";
            break;

        default:
            cout << "Invalid choice. Please select 1 to 7.\n";
        }

    } while (choice != 7);
}

BST::~BST()
{
    clearTree(root);
    root = NULL;
}