/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:21:07 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/21 13:54:56 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : _Name(name), _HitPoints(100), _MaxHitPoints(100),
			_EnergyPoints(50), _MaxEnergyPoints(50), _Level(1), _MeleeAttackDamage(20),
			_RangedAttackDamage(15), _ArmorDamageReduction(5)
{
	std::cout << BOLD << GREEN << _Name << ": Séquence d'initiation terminée.\
 Bonjour, je suis votre nouveau robot de porte.\
 Nom : " << _Name
			  << ". Niveau: " << _Level << ". Energie Max: " << _MaxEnergyPoints
			  << ". Robot d'Hyperion classe S type SC4V-TP. Veuillez régler\
 les paramètres d'usine en fonction de vos besoins avant déploiement."
			  << RESET << std::endl;
	srand(time(0));
}

ScavTrap::ScavTrap(int const n) : _HitPoints(n)
{
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << GREEN << BOLD << _Name << ": Passez une bonne soirée. Et merci d'utiliser\
 les services robotiques d'Hyperion. N'hésitez pas à faire appel à moi en cas de portes."
			  << RESET << std::endl;
}

int ScavTrap::getHealth() const
{
	return (_HitPoints);
}

void ScavTrap::getHit() const
{
	std::cout << PINK << _Name << ": Diagnostique en cours... Il me reste " << _HitPoints
			<< " points de vies." << std::endl;
}

void ScavTrap::getEnergy() const
{
	std::cout << PINK << _Name << ": Diagnostique en cours... Il me reste " << _EnergyPoints
			<< " points d'energie." << std::endl;
}

int ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << BOLD << RED << "SC4V-TP " << _Name << " attaque " << target
			  << " à distance, causant " << _RangedAttackDamage << " points de dégats !"
			  << RESET << std::endl;
	return (_RangedAttackDamage);
}

int ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << BOLD << RED << "SC4V-TP " << _Name << " attaque " << target 
	<< " en mêlée, causant " << _MeleeAttackDamage << " points de dégats !"
			  << RESET << std::endl;
	return (_MeleeAttackDamage);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints - (int)amount + _ArmorDamageReduction < 0)
		_HitPoints = 0;
	else
		_HitPoints -= amount - _ArmorDamageReduction;
	std::cout << RED << _Name << ": Systeme endommagé... Dégats reçu: " << amount
			  << " ... Points de vie restant: " << _HitPoints << RESET << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_HitPoints + (int)amount > _MaxHitPoints)
		_HitPoints = _MaxHitPoints;
	else
		_HitPoints = amount;
	std::cout << BLUE << _Name << ": Auto-Réparation terminé... Il me reste " << _HitPoints
			  << " points de vie." << RESET << std::endl;
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
