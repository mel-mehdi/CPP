#include "Point.hpp"

// Default constructor
Point::Point() : x(0), y(0) {
}

// Parameterized constructor
Point::Point(const float x_val, const float y_val) : x(x_val), y(y_val) {
}

// Copy constructor
Point::Point(const Point& other) : x(other.x), y(other.y) {
}

// Copy assignment operator
Point& Point::operator=(const Point& other) {
    (void)other;
    return *this;
}

// Destructor
Point::~Point() {
}

// Getters
Fixed Point::getX() const {
    return this->x;
}

Fixed Point::getY() const {
    return this->y;
}
