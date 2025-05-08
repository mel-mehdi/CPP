#include "Base.hpp"

Base::~Base() {}

Base* generate(void) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    
    int random = std::rand() % 3;
    
    switch (random) {
        case 0:
            std::cout << "Generated an A object" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated a B object" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated a C object" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "Pointer type identified as: A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "Pointer type identified as: B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "Pointer type identified as: C" << std::endl;
    } else {
        std::cout << "Pointer type could not be identified" << std::endl;
    }
}

void identify(Base& p) {
    A* a_ptr = dynamic_cast<A*>(&p);
    if (a_ptr != NULL) {
        std::cout << "Reference type identified as: A" << std::endl;
        return;
    }
    
    B* b_ptr = dynamic_cast<B*>(&p);
    if (b_ptr != NULL) {
        std::cout << "Reference type identified as: B" << std::endl;
        return;
    }
    
    C* c_ptr = dynamic_cast<C*>(&p);
    if (c_ptr != NULL) {
        std::cout << "Reference type identified as: C" << std::endl;
        return;
    }
    
    std::cout << "Reference type could not be identified" << std::endl;
}