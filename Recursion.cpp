#include <iostream>
#include "Recursion.hpp"

using namespace std;

int Recursion::factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int Recursion::fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int Recursion::sumNaturalNumbers(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + sumNaturalNumbers(n - 1);
}

int Recursion::power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }

    return base * power(base, exponent - 1);
}

int Recursion::reverseNumber(int number, int reversed)
{
    if (number == 0)
    {
        return reversed;
    }

    int digit = number % 10;

    return reverseNumber(
        number / 10,
        reversed * 10 + digit);
}

void Recursion::factorialDemo()
{
    int n;

    cout << "\n========== FACTORIAL USING RECURSION ==========\n";
    cout << "Enter a non-negative integer: ";

    while (!(cin >> n) || n < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Enter a non-negative integer: ";
    }

    if (n > 12)
    {
        cout << "Please enter a value from 0 to 12 "
             << "to avoid integer overflow.\n";
        return;
    }

    cout << "Factorial of " << n
         << " = " << factorial(n) << "\n";

    cout << "\nBase Case: n = 0 or n = 1\n";
    cout << "Recursive Case: n * factorial(n - 1)\n";
}

void Recursion::fibonacciDemo()
{
    int n;

    cout << "\n========== FIBONACCI USING RECURSION ==========\n";
    cout << "Enter term position (0 to 30): ";

    while (!(cin >> n) || n < 0 || n > 30)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Enter a value from 0 to 30: ";
    }

    cout << "Fibonacci term " << n
         << " = " << fibonacci(n) << "\n";

    cout << "\nBase Cases: F(0) = 0 and F(1) = 1\n";
    cout << "Recursive Case: F(n) = F(n-1) + F(n-2)\n";
}

void Recursion::sumDemo()
{
    int n;

    cout << "\n========== SUM OF NATURAL NUMBERS ==========\n";
    cout << "Enter a non-negative integer: ";

    while (!(cin >> n) || n < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Enter a non-negative integer: ";
    }

    if (n > 10000)
    {
        cout << "Please enter a value up to 10000.\n";
        return;
    }

    cout << "Sum from 1 to " << n
         << " = "
         << sumNaturalNumbers(n)
         << "\n";

    cout << "\nBase Case: sum(0) = 0\n";
    cout << "Recursive Case: n + sum(n - 1)\n";
}

void Recursion::powerDemo()
{
    int base;
    int exponent;

    cout << "\n========== POWER USING RECURSION ==========\n";

    cout << "Enter base: ";

    while (!(cin >> base))
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Enter an integer: ";
    }

    cout << "Enter non-negative exponent: ";

    while (!(cin >> exponent) || exponent < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Enter a non-negative integer: ";
    }

    if (exponent > 12)
    {
        cout << "Please enter an exponent from 0 to 12 "
             << "to keep the result within integer range.\n";
        return;
    }

    cout << base << "^" << exponent
         << " = "
         << power(base, exponent)
         << "\n";

    cout << "\nBase Case: exponent = 0\n";
    cout << "Recursive Case: base * power(base, exponent - 1)\n";
}

void Recursion::reverseDemo()
{
    int number;

    cout << "\n========== REVERSE NUMBER USING RECURSION ==========\n";
    cout << "Enter a non-negative integer: ";

    while (!(cin >> number) || number < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Enter a non-negative integer: ";
    }

    cout << "Reversed number = "
         << reverseNumber(number, 0)
         << "\n";

    cout << "\nRecursive idea:\n";
    cout << "Take the last digit, add it to the reversed result,\n";
    cout << "then recursively process the remaining number.\n";
}

void Recursion::interactiveMenu()
{
    int choice = 0;

    do
    {
        cout << "\n============================================\n";
        cout << "             RECURSION PRACTICE\n";
        cout << "============================================\n";
        cout << "1. Factorial\n";
        cout << "2. Fibonacci\n";
        cout << "3. Sum of Natural Numbers\n";
        cout << "4. Power of a Number\n";
        cout << "5. Reverse a Number\n";
        cout << "6. Back to Main Menu\n";
        cout << "============================================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a number from 1 to 6: ";
        }

        switch (choice)
        {
        case 1:
            factorialDemo();
            break;

        case 2:
            fibonacciDemo();
            break;

        case 3:
            sumDemo();
            break;

        case 4:
            powerDemo();
            break;

        case 5:
            reverseDemo();
            break;

        case 6:
            cout << "Returning to main menu...\n";
            break;

        default:
            cout << "Invalid choice. Please select 1 to 6.\n";
        }

    } while (choice != 6);
}