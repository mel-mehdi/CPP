#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
    int value; // Integer to store the fixed-point number value
    static const int fractionalBits; // Number of fractional bits

public:
    Fixed(); // Default constructor
    Fixed(const Fixed &other); // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment operator
    ~Fixed(); // Destructor

    int getRawBits(void) const; // Returns the raw value of the fixed-point value
    void setRawBits(int const raw); // Sets the raw value of the fixed-point number
};

#endif // FIXED_H