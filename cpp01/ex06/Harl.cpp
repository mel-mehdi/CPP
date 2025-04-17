#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info(void) {
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) {
    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int index = 0;

    for (int i = 0;i < 4 && index == 0; ++i) {
        index = (levels[i] == level) * i;
    }

    switch (index) {
        case 0:
            (this->*functions[0])();
            /* fall through */
        case 1:
            (this->*functions[1])();
            /* fall through */
        case 2:
            (this->*functions[2])();
            /* fall through */
        case 3:
            (this->*functions[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
    }
}