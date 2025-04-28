#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    try {
        // Create one high-level bureaucrat
        Bureaucrat boss("CEO", 1);
        std::cout << boss << std::endl;
        Intern intern;
        std::string formTypes[] = {
            "shrubbery creation", 
            "robotomy request", 
            "presidential pardon",
            "invalid form type"  // Test invalid form
        };
        
        for (int i = 0; i < 4; i++) {
            std::cout << "\n--- Creating " << formTypes[i] << " form ---" << std::endl;
            AForm* form = intern.makeForm(formTypes[i], "Target");
            
            if (form) {
                boss.signForm(*form);
                boss.executeForm(*form);
                delete form;
            }
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}