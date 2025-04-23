#include "ShrubberyCreationForm.hpp"

// Orthodox Canonical Form implementations
ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm("Shrubbery Creation Form", 145, 137),
    _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
    AForm("Shrubbery Creation Form", 145, 137),
    _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : 
    AForm(other),
    _target(other._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

// Implementation of pure virtual function
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    // Check if form can be executed
    checkExecution(executor);
    
    // Create file with ASCII trees
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    // Write ASCII trees to file
    outfile << "         *         " << std::endl;
    outfile << "        /|\\        " << std::endl;
    outfile << "       / | \\       " << std::endl;
    outfile << "      /  |  \\      " << std::endl;
    outfile << "     /   |   \\     " << std::endl;
    outfile << "    /    |    \\    " << std::endl;
    outfile << "   /_____|_____\\   " << std::endl;
    outfile << "        |||        " << std::endl;
    outfile << "        |||        " << std::endl;
    outfile << std::endl;
    outfile << "     *******      " << std::endl;
    outfile << "    *********     " << std::endl;
    outfile << "   ***********    " << std::endl;
    outfile << "  *************   " << std::endl;
    outfile << " *************** " << std::endl;
    outfile << "******************" << std::endl;
    outfile << "       ||||       " << std::endl;
    outfile << "       ||||       " << std::endl;
    
    outfile.close();
    std::cout << "Created shrubbery in file " << filename << std::endl;
}

// Getter
std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}