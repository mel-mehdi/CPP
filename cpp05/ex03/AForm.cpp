#include "AForm.hpp"

// Orthodox Canonical Form implementations
AForm::AForm() : 
    _name("default form"), 
    _signed(false), 
    _gradeToSign(150), 
    _gradeToExecute(150) {
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : 
    _name(name), 
    _signed(false), 
    _gradeToSign(gradeToSign), 
    _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : 
    _name(other._name), 
    _signed(other._signed), 
    _gradeToSign(other._gradeToSign), 
    _gradeToExecute(other._gradeToExecute) {
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        // Can't copy const attributes, only copy the signed status
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {
}

// Getters
std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

// Member functions
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

// Common execution check
void AForm::checkExecution(const Bureaucrat& executor) const {
    if (!_signed)
        throw NotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

// Exception classes implementation
const char* AForm::GradeTooHighException::what() const throw() {
    return "Error: Form grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Error: Form grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Error: Form is not signed";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() 
       << ", signed: " << (form.isSigned() ? "yes" : "no") 
       << ", grade to sign: " << form.getGradeToSign() 
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}