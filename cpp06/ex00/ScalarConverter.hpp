#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <limits>
#include <cmath>
#include <cctype>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>


class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    
    static void convertFromChar(char c);
    static void convertFromInt(int i);
    static void convertFromFloat(float f);
    static void convertFromDouble(double d);

    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);

public:
    static void convert(const std::string& literal);
};

#endif