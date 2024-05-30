#ifndef TOY_H
#define TOY_H

#include <iostream>

class Toy {

private:
    std::string name;

public:
    Toy() : name ("noName"){std::cout << "Toy is created: " << name << ", " << this << "\n";};
    Toy(std::string name) : name (name){std::cout << "Toy is created: " << name << ", " << this << "\n";};
    ~Toy();
};

#endif 