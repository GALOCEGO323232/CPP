#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a;
	ScavTrap b("Pedro");
	ClapTrap c;
	ScavTrap d("João");
	a.attack("João");
	a.guardGate();
	b.takeDamage(50);
	b.beRepaired(3);
	b.takeDamage(100);
	b.takeDamage(5);
	b.beRepaired(5);
	c.attack("João");
	d.attack("Pedro");
	c.takeDamage(5);
	c.beRepaired(3);
	d.takeDamage(5);
	d.takeDamage(5);
	d.attack("Pedro");
}