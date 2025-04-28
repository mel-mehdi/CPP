#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Create bureaucrats with different grades
        Bureaucrat highLevel("Director", 5);
        Bureaucrat midLevel("Manager", 40);
        Bureaucrat lowLevel("Intern", 140);
        
        std::cout << "--- Bureaucrats ---\n";
        std::cout << highLevel << std::endl;
        std::cout << midLevel << std::endl;
        std::cout << lowLevel << std::endl;
        
        // Test each form type
        std::cout << "\n--- Shrubbery Creation Form ---\n";
        ShrubberyCreationForm shrubForm("home");
        lowLevel.signForm(shrubForm);
        midLevel.executeForm(shrubForm);
        
        std::cout << "\n--- Robotomy Request Form ---\n";
        RobotomyRequestForm robotForm("Employee");
        midLevel.signForm(robotForm);
        midLevel.executeForm(robotForm);
        
        std::cout << "\n--- Presidential Pardon Form ---\n";
        PresidentialPardonForm pardonForm("Citizen");
        highLevel.signForm(pardonForm);
        highLevel.executeForm(pardonForm);
        
        // Test failed execution (insufficient grade)
        std::cout << "\n--- Testing Failed Execution ---\n";
        lowLevel.executeForm(pardonForm);
        
        // Test unsigned form
        std::cout << "\n--- Testing Unsigned Form ---\n";
        PresidentialPardonForm unsignedForm("Someone");
        highLevel.executeForm(unsignedForm);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}