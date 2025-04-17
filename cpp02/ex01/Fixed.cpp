#include "Fixed.hpp"


const int Fixed::fractionalBits = 8;

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int intValue)
{    
    std::cout << "Int constructor called\n";
    this->value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called\n";
    this->value = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

float Fixed::toFloat(void) const {
    return (float)(this->value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return this->value >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}