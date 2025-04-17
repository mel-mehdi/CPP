#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unknown_clap_name"), ScavTrap(), FragTrap() {
    _name = "Unknown";
    _hitPoints = FragTrap::_hitPoints; // 100 HP from FragTrap
    _energyPoints = ScavTrap::_energyPoints; // 50 EP from ScavTrap
    _attackDamage = FragTrap::_attackDamage; // 30 AD from FragTrap
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    _name = name;
    _hitPoints = FragTrap::_hitPoints; // 100 HP from FragTrap
    _energyPoints = ScavTrap::_energyPoints; // 50 EP from ScavTrap
    _attackDamage = FragTrap::_attackDamage; // 30 AD from FragTrap
    std::cout << "DiamondTrap named constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << _name << " and my ClapTrap name is " 
              << ClapTrap::_name << std::endl;
}
