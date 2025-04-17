#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Basic ClapTrap test
    ClapTrap clap("Clappy");
    clap.attack("Target");
    clap.takeDamage(3);
    clap.beRepaired(2);
    
    // Basic ScavTrap test
    ScavTrap scav("Scavvy");
    scav.attack("Enemy");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();
    
    // Test polymorphism
    ClapTrap* ptr = &scav;
    ptr->attack("Foe");
    
    return 0;
}