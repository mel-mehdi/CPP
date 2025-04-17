#include "ClapTrap.hpp"

int main() {
    // Create a ClapTrap instance
    ClapTrap clap("mehdi");
    
    // Test basic actions
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    // Test copy constructor
    ClapTrap clap2 = clap;
    clap2.attack("Another Enemy");
    
    // Test taking fatal damage
    clap.takeDamage(10);
    clap.attack("Enemy"); // Should not work when out of hit points
    
    return 0;
}