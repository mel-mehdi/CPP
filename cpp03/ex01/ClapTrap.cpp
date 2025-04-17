#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap named constructor called for " << _name <<"\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called\n";
    *this = other;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << _name <<"\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignment operator called\n";
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left to attack!\n";
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no hit points left to attack!\n";
        return;
    }
    
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " 
              << _attackDamage << " points of damage!\n";
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already down!\n";
        return;
    }
    
    if (amount >= _hitPoints) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage and is down!\n";
    } else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage, reducing hit points to " 
                  << _hitPoints << "!\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left to repair itself!\n";
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no hit points left to repair itself!\n";
        return;
    }
    
    _hitPoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
              << " hit points, now has " << _hitPoints << " hit points!\n";
}
