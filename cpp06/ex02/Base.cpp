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
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Reference type identified as: A" << std::endl;
        return;
    } catch (std::bad_cast&) {
    }
    
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Reference type identified as: B" << std::endl;
        return;
    } catch (std::bad_cast&) {
    }
    
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Reference type identified as: C" << std::endl;
        return;
    } catch (std::bad_cast&) {

    }
    
    std::cout << "Reference type could not be identified" << std::endl;
}