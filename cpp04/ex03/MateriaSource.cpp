#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    // std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &src) {
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (src.templates[i])
            this->templates[i] = src.templates[i]->clone();
        else
            this->templates[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
    // std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &src) {
        // Clean up existing templates
        for (int i = 0; i < 4; i++) {
            if (this->templates[i]) {
                delete this->templates[i];
                this->templates[i] = NULL;
            }
        }
        
        // Copy new templates
        for (int i = 0; i < 4; i++) {
            if (src.templates[i])
                this->templates[i] = src.templates[i]->clone();
            else
                this->templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    // std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (templates[i]) {
            delete templates[i];
            templates[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    
    for (int i = 0; i < 4; i++) {
        if (!templates[i]) {
            templates[i] = m;
            // std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }
    
    // If inventory is full, the materia is not learned
    // std::cout << "MateriaSource cannot learn more materias. Memory full!" << std::endl;
    delete m;  // We need to delete it if we can't store it
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] && templates[i]->getType() == type) {
            // std::cout << "MateriaSource created " << type << std::endl;
            return templates[i]->clone();
        }
    }
    
    // std::cout << "MateriaSource does not know type " << type << std::endl;
    return NULL;
}