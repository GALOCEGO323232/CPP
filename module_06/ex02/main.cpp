#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::srand(std::time(NULL));

    Base* p = generate();

    std::cout << "identify by pointer: ";
    identify(p);

    std::cout << "identify by reference: ";
    identify(*p);

    delete p;
    return 0;
}