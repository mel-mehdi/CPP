#include "Animal.hpp"

Animal::Animal() : type("") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &src) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &src) {
        this->type = src.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "* Generic animal sound *" << std::endl;
}