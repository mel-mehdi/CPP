#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &src);
    Brain &operator=(const Brain &src);
    ~Brain();

    void setIdea(int index, std::string idea);
    std::string getIdea(int index) const;
};

#endif