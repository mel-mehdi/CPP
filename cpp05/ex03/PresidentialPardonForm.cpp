#include "PresidentialPardonForm.hpp"

// Orthodox Canonical Form implementations
PresidentialPardonForm::PresidentialPardonForm() : 
    AForm("Presidential Pardon Form", 25, 5),
    _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : 
    AForm("Presidential Pardon Form", 25, 5),
    _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : 
    AForm(other),
    _target(other._target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

// Implementation of pure virtual function
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    // Check if form can be executed
    checkExecution(executor);
    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// Getter
std::string PresidentialPardonForm::getTarget() const {
    return _target;
}