#include <iostream>

int main() {
    // Arithmetic operators
    int a = 10, b = 5;
    std::cout << "Arithmetic Operators:\n";
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;
    std::cout << "a % b = " << a % b << std::endl;

    // Increment and decrement operators
    std::cout << "\nIncrement and Decrement Operators:\n";
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a-- = " << a-- << std::endl;
    std::cout << "a = " << a << std::endl;

    // Comparison operators
    std::cout << "\nComparison Operators:\n";
    std::cout << "a == b is " << (a == b) << std::endl;
    std::cout << "a != b is " << (a != b) << std::endl;
    std::cout << "a > b is " << (a > b) << std::endl;
    std::cout << "a < b is " << (a < b) << std::endl;

    // Logical operators
    bool x = true, y = false;
    std::cout << "\nLogical Operators:\n";
    std::cout << "x && y is " << (x && y) << std::endl;         // OUTPUT = 0
    std::cout << "x || y is " << (x || y) << std::endl;         // OUTPUT = 1
    std::cout << "!x is " << !x << std::endl;                   // OUTPUT = 0

    // Bitwise operators
    std::cout << "\nBitwise Operators:\n";
    std::cout << "a & b = " << (a & b) << std::endl;
    std::cout << "a | b = " << (a | b) << std::endl;
    std::cout << "a ^ b = " << (a ^ b) << std::endl;
    std::cout << "~a = " << ~a << std::endl;
    std::cout << "a << 1 = " << (a << 1) << std::endl;
    std::cout << "a >> 1 = " << (a >> 1) << std::endl;

    return 0;
}