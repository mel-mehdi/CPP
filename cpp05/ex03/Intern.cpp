#include "Intern.hpp"

// Orthodox Canonical Form implementations
Intern::Intern() {
    // No specific initialization needed
}

Intern::Intern(const Intern& other) {
    // No attributes to copy
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    // No attributes to copy
    (void)other;
    return *this;
}

Intern::~Intern() {
    // No specific cleanup needed
}

// Member function to create forms
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    int formIndex = -1;
    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            formIndex = i;
            break;
        }
    }
    
    AForm* form = NULL;
    switch (formIndex) {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
            throw FormNotFoundException();
    }
    
    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}

// Exception class implementation
const char* Intern::FormNotFoundException::what() const throw() {
    return "Error: Requested form type not found";
}