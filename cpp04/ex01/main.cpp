#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
    // Basic test from subject
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // should not create a leak
    delete i;

    // Array of Animal objects
    std::cout << "\n--- Creating array of animals ---" << std::endl;
    const int count = 4;
    Animal* animals[count];
    
    // Half filled with dogs
    for (int i = 0; i < count/2; i++) {
        animals[i] = new Dog();
    }
    
    // Half filled with cats
    for (int i = count/2; i < count; i++) {
        animals[i] = new Cat();
    }
    
    // Make each animal sound
    for (int i = 0; i < count; i++) {
        std::cout << "Animal #" << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    // Clean up the array
    for (int i = 0; i < count; i++) {
        delete animals[i];
    }
    
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
    
    return 0;
}