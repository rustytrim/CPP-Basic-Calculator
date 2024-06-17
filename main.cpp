#include <cmath>
#include <iostream>
#include <limits>
#include <string>

// Display a welcome message when the program is executed
void DisplayWelcomeMessage()
{
    std::cout << "Welcome to a basic calculator written in C++" << std::endl;
}

// Get the input and store it within the references
void GetInput(double &x, double &y, char &op)
{
    std::cout << "Enter first number (X): ";

    // Validate the input for x
    while (!(std::cin >> x))
    {
        std::cin.clear();                                                   // Clear errors
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the input
        std::cout << "Error: Please enter a valid number for x!";
    }

    std::cout << "Use +, -, /, *, or % for operations: ";

    // Validate that op will indeed be a char
    while (!(std::cin >> op) || (op != '+' && op != '-' && op != '/' && op != '*' && op != '%'))
    {
        std::cin.clear();                                                   // Clear errors
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the input
        std::cout << "Error: Please enter a valid char (+, -, /, *, %): ";
    }

    std::cout << "Enter second number (Y): ";

    // Validate input for y
    while (!(std::cin >> y))
    {
        std::cin.clear();                                                   // Clear errors
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the input
        std::cout << "Error: Please enter a valid number for y!";
    }
}

// Perform the calculation
void Calculate(double &x, double &y, char &op)
{
    switch (op)
    {
    case '+':
        std::cout << "Result: " << x + y;
        break;
    case '-':
        std::cout << "Result: " << x - y;
        break;
    case '/':
        if (y == 0)
            std::cout << "Error: Division by zero is undefined." << std::endl;
        else
            std::cout << "Result: " << x / y;
        break;
    case '*':
        std::cout << "Result: " << x * y;
        break;
    case '%':
        if (y == 0)
            std::cout << "Error: Modulus by zero is undefined." << std::endl;
        else
            std::cout << "Result: " << std::fmod(x, y);
        break;
    }
}

int main()
{
    double x, y;
    char op;

    DisplayWelcomeMessage();
    GetInput(x, y, op);
    Calculate(x, y, op);
}