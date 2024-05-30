#include "shared_toy_ptr.h"

SharedToyPtr makeSharedToy(std::string name)
{
    return {name};
}

SharedToyPtr makeSharedToy(Toy* toy)
{
    if (toy == nullptr)
        return SharedToyPtr();
    else
        return {toy};
}

unsigned long SharedToyPtr::getUseCount() const {
    if (checkBlock == nullptr)
    {
        return 0;
    }
    else
    {
        return checkBlock->getUseCount();
    }
}

void SharedToyPtr::reset()
{
    if (checkBlock == nullptr)
        return;
    else
    {
        checkBlock->decrementUseCount();
        checkBlock = nullptr;
    }
}

SharedToyPtr::SharedToyPtr(const SharedToyPtr &other)
{
    if (other.checkBlock != nullptr)
    {
        this->checkBlock = other.checkBlock;
        this->checkBlock->incrementUseCount();
    }
}

SharedToyPtr &SharedToyPtr::operator=(const SharedToyPtr &other){

    if (this->checkBlock == other.checkBlock)
        return *this;
    else if (this->checkBlock != nullptr)
        this->checkBlock->decrementUseCount();

    this->checkBlock = other.checkBlock;

    if (this->checkBlock != nullptr)
        this->checkBlock->incrementUseCount();
    return *this;
}

Toy *SharedToyPtr::get() {
    if (checkBlock == nullptr)
    {
        return nullptr;
    }
    else
    {
        return checkBlock->getToy();
    }
}

CheckBlock *SharedToyPtr::getCheckBlock() {
    return checkBlock;
}

SharedToyPtr::~SharedToyPtr()
{
    std::cout << "SharedPtr is deleted " << this << "\n";
    if (checkBlock != nullptr)
    {
        checkBlock->decrementUseCount();
    }
}