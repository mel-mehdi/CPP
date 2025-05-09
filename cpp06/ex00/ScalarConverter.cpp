#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isInt(const std::string& literal) {
    char* end;
    std::strtol(literal.c_str(), &end, 10);
    return *end == '\0';
}

bool ScalarConverter::isFloat(const std::string& literal) {
    char* end;
    std::strtof(literal.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string& literal) {
    char* end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0';
}

void ScalarConverter::printChar(char c) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";
}

void ScalarConverter::printInt(int i) {
    std::cout << "int: " << i << "\n";
}

void ScalarConverter::printFloat(float f) {
    if (std::isnan(f) || std::isinf(f))
        std::cout << "float: " << f << "f\n";
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
}

void ScalarConverter::printDouble(double d) {
    if (std::isnan(d) || std::isinf(d))
        std::cout << "double: " << d << "\n";
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::convert(const std::string& literal) {
    if (isChar(literal)) {
        char c = literal[1];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    } else if (isInt(literal)) {
        int i = std::atoi(literal.c_str());
        printChar(static_cast<char>(i));
        printInt(i);
        printFloat(static_cast<float>(i));
        printDouble(static_cast<double>(i));
    } else if (isFloat(literal)) {
        float f = std::strtof(literal.c_str(), NULL);
        printChar(static_cast<char>(f));
        printInt(static_cast<int>(f));
        printFloat(f);
        printDouble(static_cast<double>(f));
    } else if (isDouble(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        printChar(static_cast<char>(d));
        printInt(static_cast<int>(d));
        printFloat(static_cast<float>(d));
        printDouble(d);
    } else {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
    }
}
