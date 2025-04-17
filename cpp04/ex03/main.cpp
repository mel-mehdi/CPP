#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
    // Test from subject
    std::cout << "===== Subject Test =====" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    // Additional tests
    std::cout << "\n===== Additional Tests =====" << std::endl;
    
    // Create a character and equip materia
    Character* john = new Character("John");
    
    // Create materia source and learn materias
    MateriaSource ms;
    ms.learnMateria(new Ice());
    ms.learnMateria(new Cure());
    ms.learnMateria(new Ice());
    ms.learnMateria(new Cure());
    
    // Try to learn a 5th materia (should fail)
    ms.learnMateria(new Ice());
    
    // Create and equip materia
    AMateria* ice1 = ms.createMateria("ice");
    AMateria* ice2 = ms.createMateria("ice");
    AMateria* cure1 = ms.createMateria("cure");
    AMateria* cure2 = ms.createMateria("cure");
    
    std::cout << "Equipping John with materias..." << std::endl;
    john->equip(ice1);
    john->equip(ice2);
    john->equip(cure1);
    john->equip(cure2);
    
    // Try to equip a 5th materia (should fail)
    AMateria* extra = ms.createMateria("ice");
    john->equip(extra);
    
    // Create a target
    Character target("Target");
    
    // Use materia
    std::cout << "\nJohn using materia on target:" << std::endl;
    john->use(0, target);  // ice
    john->use(1, target);  // ice
    john->use(2, target);  // cure
    john->use(3, target);  // cure
    
    // Test invalid use
    std::cout << "\nTrying invalid materia use:" << std::endl;
    john->use(-1, target);  // Invalid index
    john->use(4, target);   // Invalid index
    
    // Test unequip
    std::cout << "\nUnequipping and re-using:" << std::endl;
    john->unequip(1);  // Unequip ice2
    john->use(1, target);  // Should do nothing
    
    // Clean up the unequipped materia (in real implementation, you'd store this somewhere)
    delete extra;  // Clean up the materia that wasn't equipped
    delete ice2;   // Clean up the materia we unequipped
    
    // Test deep copy through copy constructor
    std::cout << "\nTesting copy constructor:" << std::endl;
    Character* johnCopy = new Character(*john);
    
    std::cout << "Original John using materia:" << std::endl;
    john->use(0, target);
    john->use(2, target);
    
    std::cout << "Copy of John using materia:" << std::endl;
    johnCopy->use(0, target);
    johnCopy->use(2, target);
    
    // Clean up
    delete john;
    delete johnCopy;
    
    return 0;
}