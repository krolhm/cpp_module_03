/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:21:07 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/21 14:08:01 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << BOLD << GREEN << _Name << ": Séquence d'initiation terminée.\
 Mise à jour ... ScavTrap activé."
 << RESET << std::endl;
	_EnergyPoints = 50;
	_MaxEnergyPoints = 50;
	_MeleeAttackDamage = 20;
	_RangedAttackDamage = 15;
	_ArmorDamageReduction = 3;
	srand(time(0));
}

ScavTrap::ScavTrap(int const n) : ClapTrap(n)
{
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << GREEN << BOLD << _Name << ": ScavTrap désactivé."
			  << RESET << std::endl;
}

void ScavTrap::challengeNewcomer()
{
	int random = rand() % 5;
	std::string randChallenge[5] =
		{
			": Si tu arrives à ouvrir les portes plus vites que moi, tu pourras passer.",
			": Entre 1kg d'uranium et 1kg d'helium, quel est le plus léger ?",
			": Si tu trouves pourquoi 0 perds toujours ses débats, alors tu pourras passer.",
			": F et F' sont sur un yacht. F tombe à l'eau, que fait F' ?",
			": Un atome réconforte son ami qui a récemment perdu un électron\
 que lui dit-il ?"};
	std::cout << BOLD << RED << _Name << randChallenge[random]
			  << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &o, ScavTrap const &ScavTrap)
{
	o << ScavTrap.getHealth();
	return o;
}