#include <iostream>
#include "shared_toy_ptr.h"


void getSharedPtrStatus(SharedToyPtr* sharedToyPtr, std::string tag)
{
    std::cout << tag << " - check block @-> " << sharedToyPtr->getCheckBlock() << ", toy @-> " << sharedToyPtr->get() << " links: " << sharedToyPtr->getUseCount() << "\n";
}


int main()
 {
     std::cout << "+- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --+\n";
     std::cout << "| 31.5 Practical Work.Task 2. Smart pointer implementation |\n";
     std::cout << "+- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --+\n\n";

     std::cout << "-----Creation sharedToyPtr_1 (with Ball) and sharedToyPtr_2 (with nullptr)-----\n";
     SharedToyPtr sharedToyPtr_1 = makeSharedToy("Ball");
     SharedToyPtr sharedToyPtr_2 = makeSharedToy(nullptr);
     getSharedPtrStatus(&sharedToyPtr_1, "sharedToyPtr_1");
     getSharedPtrStatus(&sharedToyPtr_2, "sharedToyPtr_2");

     std::cout << "\n-----Set sharedToyPtr_1 = sharedToyPtr_2-----\n";
     sharedToyPtr_2 = sharedToyPtr_1;
     getSharedPtrStatus(&sharedToyPtr_1, "sharedToyPtr_1");
     getSharedPtrStatus(&sharedToyPtr_2, "sharedToyPtr_2");

     std::cout << "\n-----Creation sharedToyPtr_3 as a copy of sharedToyPtr_2-----\n";
     SharedToyPtr sharedToyPtr_3(sharedToyPtr_2);
     getSharedPtrStatus(&sharedToyPtr_1, "sharedToyPtr_1");
     getSharedPtrStatus(&sharedToyPtr_2, "sharedToyPtr_2");
     getSharedPtrStatus(&sharedToyPtr_3, "sharedToyPtr_3");

     std::cout << "\n-----Creation sharedToyPtr_4 (with Bone))-----\n";
     SharedToyPtr sharedToyPtr_4 = makeSharedToy("Bone");
     getSharedPtrStatus(&sharedToyPtr_1, "sharedToyPtr_1");
     getSharedPtrStatus(&sharedToyPtr_2, "sharedToyPtr_2");
     getSharedPtrStatus(&sharedToyPtr_3, "sharedToyPtr_3");
     getSharedPtrStatus(&sharedToyPtr_4, "sharedToyPtr_4");

     std::cout << "\n-----Reset of sharedToyPtr_4 and sharedToyPtr_3-----\n";
     sharedToyPtr_3.reset();
     sharedToyPtr_4.reset();
     getSharedPtrStatus(&sharedToyPtr_1, "sharedToyPtr_1");
     getSharedPtrStatus(&sharedToyPtr_2, "sharedToyPtr_2");
     getSharedPtrStatus(&sharedToyPtr_3, "sharedToyPtr_3");
     getSharedPtrStatus(&sharedToyPtr_4, "sharedToyPtr_4");

     std::cout << "\n-----Set sharedToyPtr_1 equal to sharedToyPtr_2 (no changes expected)-----\n";
     sharedToyPtr_1 = sharedToyPtr_2;
     getSharedPtrStatus(&sharedToyPtr_1, "sharedToyPtr_1");
     getSharedPtrStatus(&sharedToyPtr_2, "sharedToyPtr_2");
     getSharedPtrStatus(&sharedToyPtr_3, "sharedToyPtr_3");
     getSharedPtrStatus(&sharedToyPtr_4, "sharedToyPtr_4");

     std::cout << "\n-----Set sharedToyPtr_1 equal to sharedToyPtr_3 (which is reset)-----\n";
     sharedToyPtr_1 = sharedToyPtr_3;
     getSharedPtrStatus(&sharedToyPtr_1, "sharedToyPtr_1");
     getSharedPtrStatus(&sharedToyPtr_2, "sharedToyPtr_2");
     getSharedPtrStatus(&sharedToyPtr_3, "sharedToyPtr_3");
     getSharedPtrStatus(&sharedToyPtr_4, "sharedToyPtr_4");

     std::cout << "\n-----Set sharedToyPtr_1 and sharedToyPtr_3 equal to sharedToyPtr_2-----\n";
     sharedToyPtr_1 = sharedToyPtr_2;
     sharedToyPtr_3 = sharedToyPtr_2;
     getSharedPtrStatus(&sharedToyPtr_1, "sharedToyPtr_1");
     getSharedPtrStatus(&sharedToyPtr_2, "sharedToyPtr_2");
     getSharedPtrStatus(&sharedToyPtr_3, "sharedToyPtr_3");
     getSharedPtrStatus(&sharedToyPtr_4, "sharedToyPtr_4");

     std::cout << "\n-----Create new toy (Rope) and set to sharedToyPtr_4-----\n";
     Toy *toy = new Toy("Rope");
     sharedToyPtr_4 = makeSharedToy(toy);
     getSharedPtrStatus(&sharedToyPtr_1, "sharedToyPtr_1");
     getSharedPtrStatus(&sharedToyPtr_2, "sharedToyPtr_2");
     getSharedPtrStatus(&sharedToyPtr_3, "sharedToyPtr_3");
     getSharedPtrStatus(&sharedToyPtr_4, "sharedToyPtr_4");
     std::cout << "\n-----Deleting of objects-----\n";

     return 0;
}