#include "Fixed.hpp"

// Orthodox Canonical Form implementations
Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
}

// Additional constructors
Fixed::Fixed(const int value) {
    this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
    this->_value = roundf(value * (1 << this->_fractionalBits));
}

// Member functions
int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_value >> this->_fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_value != other._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value + other._value);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value - other._value);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long temp = (long)this->_value * (long)other._value;
    result.setRawBits(temp >> this->_fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other._value == 0) {
        // Handle division by zero
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    Fixed result;
    long temp = ((long)this->_value << this->_fractionalBits) / (long)other._value;
    result.setRawBits(temp);
    return result;
}

// Increment/decrement operators
Fixed& Fixed::operator++() {
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old(*this);
    this->_value++;
    return old;
}

Fixed& Fixed::operator--() {
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old(*this);
    this->_value--;
    return old;
}

// Static methods
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
