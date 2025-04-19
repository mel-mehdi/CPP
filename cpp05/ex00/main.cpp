#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing Bureaucrat class ---" << std::endl;
    
    try {
        std::cout << "Creating bureaucrat with valid grade (42):" << std::endl;
        Bureaucrat b1("John", 42);
        std::cout << b1 << std::endl;
        
        std::cout << "\nIncrementing grade:" << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        
        std::cout << "\nDecrementing grade:" << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
        
        std::cout << "\nTrying to create bureaucrat with too high grade (0):" << std::endl;
        Bureaucrat b2("High", 0);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTrying to create bureaucrat with too low grade (151):" << std::endl;
        Bureaucrat b3("Low", 151);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTrying to increment beyond highest grade:" << std::endl;
        Bureaucrat b4("Max", 1);
        std::cout << b4 << std::endl;
        b4.incrementGrade();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTrying to decrement beyond lowest grade:" << std::endl;
        Bureaucrat b5("Min", 150);
        std::cout << b5 << std::endl;
        b5.decrementGrade();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}