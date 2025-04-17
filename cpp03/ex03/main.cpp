#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n--- Testing DiamondTrap ---\n" << std::endl;
    
    DiamondTrap diamond("DI4MOND");
    
    // Test inherited abilities
    diamond.attack("Super Badass");
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.guardGate();
    diamond.highFivesGuys();
    
    // Test special ability
    diamond.whoAmI();
    
    std::cout << "\n--- Testing copy constructor ---\n" << std::endl;
    
    DiamondTrap diamond2 = diamond;
    diamond2.takeDamage(50);
    diamond2.whoAmI();
    
    std::cout << "\n--- Testing all destructors ---\n" << std::endl;
    return 0;
}
