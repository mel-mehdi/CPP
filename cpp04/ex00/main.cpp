#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    // Test from the subject
    std::cout << "*** Testing regular polymorphism ***" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    // Clean up memory
    delete meta;
    delete j;
    delete i;
    
    // Additional tests for WrongAnimal/WrongCat
    std::cout << "\n*** Testing wrong polymorphism ***" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // will output the WrongAnimal sound!
    wrongMeta->makeSound();
    
    // Clean up memory
    delete wrongMeta;
    delete wrongCat;
    
    // Direct tests with objects (not pointers)
    std::cout << "\n*** Testing with objects directly ***" << std::endl;
    Animal regularAnimal;
    Dog regularDog;
    Cat regularCat;
    WrongAnimal regularWrongAnimal;
    WrongCat regularWrongCat;
    
    std::cout << "Regular Animal: ";
    regularAnimal.makeSound();
    std::cout << "Regular Dog: ";
    regularDog.makeSound();
    std::cout << "Regular Cat: ";
    regularCat.makeSound();
    std::cout << "Wrong Animal: ";
    regularWrongAnimal.makeSound();
    std::cout << "Wrong Cat: ";
    regularWrongCat.makeSound();
    
    return 0;
}