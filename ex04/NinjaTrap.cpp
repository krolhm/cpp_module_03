/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:14:01 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/23 14:24:04 by rbourgea         ###   ########.fr       */
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

int NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << BOLD << RED << "N1NJ4-TP " << _Name << " attaque " << target
			  << " à distance, causant " << _RangedAttackDamage << " points de dégats !"
			  << RESET << std::endl;
	return (_RangedAttackDamage);
}

int NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << BOLD << RED << "N1NJ4-TP " << _Name << " attaque " << target
			  << " en mêlée, causant " << _MeleeAttackDamage << " points de dégats !"
			  << RESET << std::endl;
	return (_MeleeAttackDamage);
}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &rhs)
{
	_HitPoints = rhs._HitPoints;
	_MaxHitPoints = rhs._MaxHitPoints;
	_EnergyPoints = rhs._EnergyPoints;
	_MaxEnergyPoints = rhs._MaxEnergyPoints;
	_Level = rhs._Level;
	_MeleeAttackDamage = rhs._MeleeAttackDamage;
	_RangedAttackDamage = rhs._RangedAttackDamage;
	_ArmorDamageReduction = rhs._ArmorDamageReduction;
	_Name = rhs._Name;
	return *this;
}

std::ostream &operator<<(std::ostream &o, NinjaTrap const &i)
{
	o << i.getHealth();
	return o;
}