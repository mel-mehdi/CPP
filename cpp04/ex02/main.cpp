#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
    // This would cause a compilation error because Animal is now an abstract class
    // const Animal* meta = new Animal();
    
    // But we can still use pointers to Animal for the derived classes
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " says: ";
    j->makeSound();
    std::cout << i->getType() << " says: ";
    i->makeSound();
    
    delete j;
    delete i;

    // Test deep copy
    std::cout << "\n--- Testing deep copy ---" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "I love bones!");
    
    // Create a copy using the copy constructor
    Dog* copyDog = new Dog(*originalDog);
    
    // Verify both have the same idea
    std::cout << "Original dog's idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy dog's idea: " << copyDog->getBrain()->getIdea(0) << std::endl;
    
    // Change the idea in the copy and verify it doesn't affect the original
    copyDog->getBrain()->setIdea(0, "I prefer toys!");
    
    std::cout << "After modification:" << std::endl;
    std::cout << "Original dog's idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy dog's idea: " << copyDog->getBrain()->getIdea(0) << std::endl;
    
    // Clean up
    delete originalDog;
    delete copyDog;
    
    // Uncomment to test that Animal can't be instantiated
    /*
    std::cout << "\n--- Trying to instantiate an Animal ---" << std::endl;
    Animal abstractAnimal; // This should cause a compilation error
    */
    
    return 0;
}