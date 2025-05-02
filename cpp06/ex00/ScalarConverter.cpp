#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty())
        return false;
        
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i++;
        
    for (; i < literal.length(); i++) {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
        
    if (literal.empty() || literal[literal.length() - 1] != 'f')
        return false;
        
    std::string temp = literal.substr(0, literal.length() - 1);
    bool hasDecimalPoint = false;
    size_t i = 0;
    
    if (temp[0] == '-' || temp[0] == '+')
        i++;
        
    for (; i < temp.length(); i++) {
        if (temp[i] == '.') {
            if (hasDecimalPoint)
                return false;
            hasDecimalPoint = true;
        } else if (!std::isdigit(temp[i])) {
            return false;
        }
    }
    return hasDecimalPoint;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
        
    if (literal.empty())
        return false;
        
    bool hasDecimalPoint = false;
    size_t i = 0;
    
    if (literal[0] == '-' || literal[0] == '+')
        i++;
        
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDecimalPoint)
                return false;
            hasDecimalPoint = true;
        } else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    return hasDecimalPoint;
}

void ScalarConverter::convertFromChar(char c) {
    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::convertFromInt(int i) {
    printChar(i);
    printInt(i);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void ScalarConverter::convertFromFloat(float f) {
    printChar(f);
    printInt(f);
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void ScalarConverter::convertFromDouble(double d) {
    printChar(d);
    printInt(d);
    printFloat(static_cast<float>(d));
    printDouble(d);
}

void ScalarConverter::printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < CHAR_MIN || value > CHAR_MAX) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(double value) {
    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
    } else if (value == std::numeric_limits<float>::infinity()) {
        std::cout << "+inff" << std::endl;
    } else if (value == -std::numeric_limits<float>::infinity()) {
        std::cout << "-inff" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan" << std::endl;
    } else if (value == std::numeric_limits<double>::infinity()) {
        std::cout << "+inf" << std::endl;
    } else if (value == -std::numeric_limits<double>::infinity()) {
        std::cout << "-inf" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (isChar(literal)) {
        convertFromChar(literal[1]);
    } else if (isInt(literal)) {
        try {
            int value = atoi(literal.c_str());
            if ((literal[0] == '-' && literal.length() > 11) || 
                (literal[0] != '-' && literal.length() > 10)) {
                std::cout << "Error: Integer overflow" << std::endl;
                return;
            }
            convertFromInt(value);
        } catch (const std::exception& e) {
            std::cout << "Error: Integer conversion failed - " << e.what() << std::endl;
        }
    } else if (isFloat(literal)) {
        try {
            if (literal == "nanf") {
                convertFromFloat(std::numeric_limits<float>::quiet_NaN());
            } else if (literal == "+inff") {
                convertFromFloat(std::numeric_limits<float>::infinity());
            } else if (literal == "-inff") {
                convertFromFloat(-std::numeric_limits<float>::infinity());
            } else {
                std::string temp = literal.substr(0, literal.length() - 1);
                float value = static_cast<float>(atof(temp.c_str()));
                convertFromFloat(value);
            }
        } catch (const std::exception& e) {
            std::cout << "Error: Float conversion failed - " << e.what() << std::endl;
        }
    } else if (isDouble(literal)) {
        try {
            if (literal == "nan") {
                convertFromDouble(std::numeric_limits<double>::quiet_NaN());
            } else if (literal == "+inf") {
                convertFromDouble(std::numeric_limits<double>::infinity());
            } else if (literal == "-inf") {
                convertFromDouble(-std::numeric_limits<double>::infinity());
            } else {
                double value = atof(literal.c_str());
                convertFromDouble(value);
            }
        } catch (const std::exception& e) {
            std::cout << "Error: Double conversion failed - " << e.what() << std::endl;
        }
    } else {
        std::cout << "Error: Unable to detect the type of the literal." << std::endl;
    }
}