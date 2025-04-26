#include "Form.hpp"

Form::Form() : 
    _name("default form"), 
    _signed(false), 
    _gradeToSign(150), 
    _gradeToExecute(150) {
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : 
    _name(name), 
    _signed(false), 
    _gradeToSign(gradeToSign), 
    _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : 
    _name(other._name), 
    _signed(other._signed), 
    _gradeToSign(other._gradeToSign), 
    _gradeToExecute(other._gradeToExecute) {
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form() {
}

std::string Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Error: Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Error: Form grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() 
       << ", signed: " << (form.isSigned() ? "yes" : "no") 
       << ", grade to sign: " << form.getGradeToSign() 
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}