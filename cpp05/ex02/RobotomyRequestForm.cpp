#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
    AForm("Robotomy Request Form", 72, 55),
    _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : 
    AForm("Robotomy Request Form", 72, 55),
    _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : 
    AForm(other),
    _target(other._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkExecution(executor);
    
    std::cout << "* DRILLING NOISES * Brr... Bzzt... Whirrr..." << std::endl;
    
    // 50% chance of success
    std::srand(static_cast<unsigned int>(std::time(0)));
    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << _target << " failed miserably!" << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}