#ifndef SHAREDTOYPTR_H
#define SHAREDTOYPTR_H

#include <iostream>
#include "checkblock.h"

class SharedToyPtr {

private:
    CheckBlock* checkBlock;
public:
    SharedToyPtr() : checkBlock(nullptr){};
    SharedToyPtr(Toy* toy) : checkBlock(new CheckBlock(toy)){};
    SharedToyPtr(std::string toyName) : checkBlock(new CheckBlock(toyName)){};
    ~SharedToyPtr();
    SharedToyPtr(const SharedToyPtr& other);
    SharedToyPtr& operator=(const SharedToyPtr& other);
    unsigned long getUseCount() const;
    void reset();
    Toy* get();
    CheckBlock* getCheckBlock();
    void pptt(SharedToyPtr &sharedToyPtr);
};

SharedToyPtr makeSharedToy(std::string name);
SharedToyPtr makeSharedToy(Toy* toy);

#endif  