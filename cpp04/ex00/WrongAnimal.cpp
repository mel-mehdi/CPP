#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &src) {
        this->type = src.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "* Wrong generic animal sound *" << std::endl;
}