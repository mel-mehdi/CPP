#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "---- DEBUG ----\n";
    harl.complain("DEBUG");

    std::cout << "---- INFO ----\n";
    harl.complain("INFO");

    std::cout << "---- WARNING ----\n";
    harl.complain("WARNING");

    std::cout << "---- ERROR ----\n";
    harl.complain("ERROR");

    std::cout << "---- UNKNOWN LEVEL ----\n";
    harl.complain("UNKNOWN");

    return 0;
}
