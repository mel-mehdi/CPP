#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration to avoid circular dependency

class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat& bureaucrat);
    
    // Pure virtual function to make the class abstract
    virtual void execute(const Bureaucrat& executor) const = 0;
    
    // Common execution check
    void checkExecution(const Bureaucrat& executor) const;

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class NotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif