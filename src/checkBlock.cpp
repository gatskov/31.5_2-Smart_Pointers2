#include "checkblock.h"

unsigned long CheckBlock::getUseCount() const
{
    return useCount;
}

void CheckBlock::incrementUseCount()
{
    ++useCount;
}

void CheckBlock::decrementUseCount()
{
    if (useCount > 1)
    {
        --useCount;
    }
    else
    {
        delete this;
    }
}

Toy *CheckBlock::getToy()
{
    return toy;
}

CheckBlock::~CheckBlock()
{
    std::cout << "CheckBlock is deleted " << this << "\n";
    if (useCount > 0 && toy != nullptr)
        delete toy;
}