#include "Character.hpp"

Character::Character() : name("Default") {
    // std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(std::string const & name) : name(name) {
    // std::cout << "Character named constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(Character const & src) {
    // std::cout << "Character copy constructor called" << std::endl;
    this->name = src.name;
    for (int i = 0; i < 4; i++) {
        if (src.inventory[i])
            this->inventory[i] = src.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character &Character::operator=(Character const & src) {
    // std::cout << "Character assignment operator called" << std::endl;
    if (this != &src) {
        this->name = src.name;
        
        // Clean up existing inventory
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i]) {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
        }
        
        // Copy new inventory
        for (int i = 0; i < 4; i++) {
            if (src.inventory[i])
                this->inventory[i] = src.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    // std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i]) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
}

std::string const & Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            // std::cout << name << " equipped " << m->getType() << " at slot " << i << std::endl;
            return;
        }
    }
    
    // If inventory is full, the materia is not equipped
    // std::cout << name << " cannot equip " << m->getType() << ". Inventory full!" << std::endl;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        // std::cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}