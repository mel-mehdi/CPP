#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    // Basic functionality test
    try {
        // Create a bureaucrat with valid grade
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        
        // Test increment and decrement
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Edge case tests
    try {
        Bureaucrat tooHigh("TooHigh", 0);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat tooLow("TooLow", 151);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}