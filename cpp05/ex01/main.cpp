#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "--- Testing Form class ---" << std::endl;
    
    try {

        Bureaucrat highRanked("Director", 5);
        Bureaucrat midRanked("Manager", 50);
        Bureaucrat lowRanked("Intern", 140);
        
        std::cout << highRanked << std::endl;
        std::cout << midRanked << std::endl;
        std::cout << lowRanked << std::endl;
        

        Form easyForm("Basic Form", 100, 120);
        Form mediumForm("Standard Form", 50, 70);
        Form hardForm("Classified Form", 5, 10);
        
        std::cout << "\n" << easyForm << std::endl;
        std::cout << mediumForm << std::endl;
        std::cout << hardForm << std::endl;
        

        std::cout << "\n--- Signing attempts ---" << std::endl;
        

        lowRanked.signForm(easyForm);

        lowRanked.signForm(mediumForm);  // Should fail
        midRanked.signForm(mediumForm);
        midRanked.signForm(hardForm);    // Should fail
        highRanked.signForm(hardForm);
        
        std::cout << "\n--- Invalid form creation ---" << std::endl;
        Form invalidHighForm("Too High Grade Form", 0, 10);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        Form invalidLowForm("Too Low Grade Form", 160, 10);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}