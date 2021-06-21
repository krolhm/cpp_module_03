/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:14:01 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/21 15:21:50 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	std::cout << BOLD << GREEN << _Name << ": Séquence d'initiation terminée.\
 Mise à jour ... NinjaTrap activé."
			  << RESET << std::endl;
	_HitPoints = 60;
	_MaxHitPoints = 60;
	_EnergyPoints = 120;
	_MaxEnergyPoints = 120;
	_MeleeAttackDamage = 60;
	_RangedAttackDamage = 5;
	_ArmorDamageReduction = 0;
	srand(time(0));
}

NinjaTrap::NinjaTrap(int const n) : ClapTrap(n)
{

}

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap(src)
{
	*this = src;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << GREEN << BOLD << _Name << ": NinjaTrap désactivé."
			  << RESET << std::endl;
}

void NinjaTrap::ninjaShoeBox(FragTrap &target)
{
	std::cout << RED << BOLD << _Name << ": activation ninjaShoeBox !\
 FragTrap detecté... Lancé de shurikens ! Inflige " << _RangedAttackDamage << " dégats !"
		<< RESET << std::endl;
	target.takeDamage(_RangedAttackDamage);
}

void NinjaTrap::ninjaShoeBox(ScavTrap &target)
{
	std::cout << RED << BOLD << _Name << ": activation ninjaShoeBox !\
 ScavTrap detecté... Coup du petit doigt de pied ! Inflige " << _MeleeAttackDamage 
 << " dégats !" << RESET << std::endl;
	target.takeDamage(_MeleeAttackDamage);
}

void NinjaTrap::ninjaShoeBox(ClapTrap &target)
{
	std::cout << PINK << BOLD << _Name << ": activation ninjaShoeBox !\
 ClapTrap detecté... Protocole réparation allié ! Rend 5"
			  << " PV !" << RESET << std::endl;
	target.beRepaired(5);
}

void NinjaTrap::ninjaShoeBox(NinjaTrap &target)
{
	std::cout << PINK << BOLD << _Name << ": activation ninjaShoeBox !\
 NinjaTrap detecté... Protocole entraide allié ! Soigne 20"
			  << " PV !" << RESET << std::endl;
	target.beRepaired(20);
}

std::ostream &operator<<(std::ostream &o, NinjaTrap const &NinjaTrap)
{
	o << NinjaTrap.getHealth();
	return o;
}
