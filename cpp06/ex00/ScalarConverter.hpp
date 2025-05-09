#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <string>
#include <cerrno>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);

    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);

    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
};

#endif