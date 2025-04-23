#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "--- Creating Bureaucrats ---" << std::endl;
        Bureaucrat boss("Executive", 1);
        Bureaucrat manager("Manager", 40);
        Bureaucrat employee("Employee", 100);
        Bureaucrat intern("Intern", 150);
        
        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << employee << std::endl;
        std::cout << intern << std::endl;
        
        std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;
        
        // Signing attempts
        intern.signForm(shrub);     // Should work - grade 145 required
        
        // Execution attempts
        intern.executeForm(shrub);  // Should fail - grade 137 required
        employee.executeForm(shrub); // Should work
        
        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        RobotomyRequestForm robot("Victor");
        std::cout << robot << std::endl;
        
        // Signing attempts
        employee.signForm(robot);   // Should fail - grade 72 required
        manager.signForm(robot);    // Should work
        
        // Execution attempts
        employee.executeForm(robot); // Should fail - grade 45 required
        manager.executeForm(robot);  // Should work
        
        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        PresidentialPardonForm pardon("Criminal");
        std::cout << pardon << std::endl;
        
        // Signing attempts
        manager.signForm(pardon);   // Should fail - grade 25 required
        boss.signForm(pardon);      // Should work
        
        // Execution attempts
        manager.executeForm(pardon); // Should fail - grade 5 required
        boss.executeForm(pardon);    // Should work
        
        std::cout << "\n--- Testing unsigned form execution ---" << std::endl;
        PresidentialPardonForm unsignedPardon("Fugitive");
        boss.executeForm(unsignedPardon); // Should fail - not signed
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}