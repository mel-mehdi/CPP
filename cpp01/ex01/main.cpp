#include "Zombie.hpp"
#include <iostream>

int main() {
    int N = 5;
    std::string name = "HordeZombie";
    Zombie* horde = zombieHorde(N, name);

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    delete[] horde;

    return 0;
}