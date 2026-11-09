#pragma once

class Recursion
{
private:
    int factorial(int n);
    int fibonacci(int n);
    int sumNaturalNumbers(int n);
    int power(int base, int exponent);
    int reverseNumber(int number, int reversed);

    void factorialDemo();
    void fibonacciDemo();
    void sumDemo();
    void powerDemo();
    void reverseDemo();

public:
    void interactiveMenu();
};