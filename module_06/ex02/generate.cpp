#include "Base.hpp"

Base* generate(void)
{
	int num = std::rand() % 3;

	if (num == 0)
		return new A();
	else if (num == 1)
		return new B();
	else
		return new C();
}

