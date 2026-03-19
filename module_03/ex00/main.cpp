#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap b("João");
	a.attack("João");
	b.takeDamage(5);
	b.beRepaired(3);
	b.takeDamage(5);
	b.takeDamage(5);
	a.attack("João");
	a.attack("João");
	a.attack("João");
	a.attack("João");
	a.attack("João");
	a.attack("João");
	a.attack("João");
	a.attack("João");
	a.attack("João");
	a.attack("João");
	a.attack("João");
	a.attack("João");
	a.attack("João");
	a.attack("João");
}