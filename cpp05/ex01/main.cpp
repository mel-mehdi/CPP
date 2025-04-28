#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Create a bureaucrat
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;
        
        // Create a form
        Form contract("Contract", 50, 75);
        std::cout << contract << std::endl;
        
        // Sign the form
        bob.signForm(contract);
        std::cout << contract << std::endl;
        
        // Try to sign with low-grade bureaucrat
        Bureaucrat jim("Jim", 100);
        Form topSecret("Top Secret", 20, 30);
        jim.signForm(topSecret); // Should fail
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}