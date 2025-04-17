#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    ClapTrap();							// Default constructor
    ClapTrap(const std::string& name);	// Parameterized constructor
    ClapTrap(const ClapTrap& other);	// Copy constructor
    ~ClapTrap();						// Destructor
    
    ClapTrap& operator=(const ClapTrap& other); 	// Copy assignment operator
    
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
