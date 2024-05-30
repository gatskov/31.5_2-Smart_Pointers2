#ifndef CHECKBLOCK_H
#define CHECKBLOCK_H

#include "Toy.h"

class CheckBlock {

private:
    unsigned long useCount;
    Toy* toy;

public:
    CheckBlock(Toy* toy) : useCount(1), toy(new Toy(*toy)){};
    CheckBlock(std::string toyName) : useCount(1), toy(new Toy(toyName)){};
    ~CheckBlock();
    unsigned long getUseCount() const;
    void incrementUseCount();
    void decrementUseCount();
    Toy* getToy();
};

#endif  