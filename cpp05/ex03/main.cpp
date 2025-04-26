#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "--- Creating Bureaucrats ---" << std::endl;
        Bureaucrat boss("Executive", 1);
        Bureaucrat manager("Manager", 40);
        
        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        
        std::cout << "\n--- Testing Intern Form Creation ---" << std::endl;
        Intern someRandomIntern;
        AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "garden");
        if (form1) {
            boss.signForm(*form1);
            manager.executeForm(*form1);
            delete form1;
        }
        AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form2) {
            boss.signForm(*form2);
            boss.executeForm(*form2);
            delete form2;
        }
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Douglas Adams");
        if (form3) {
            boss.signForm(*form3);
            boss.executeForm(*form3);
            delete form3;
        }
        
        std::cout << "\n--- Testing with invalid form name ---" << std::endl;
        AForm* form4 = someRandomIntern.makeForm("coffee making", "office");
        if (form4) {
            delete form4; // This shouldn't execute
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}