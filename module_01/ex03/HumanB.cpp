#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{

}

HumanB::~HumanB()
{

}

void HumanB::setWeapon(Weapon& weapon)
{
    _Weapon = &weapon;
}

void HumanB::attack()
{
	if (_Weapon != NULL)
	{
		std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
	}
}