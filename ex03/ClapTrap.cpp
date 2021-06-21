/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 14:21:00 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/21 14:09:07 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoints(100), _MaxHitPoints(100),
	_EnergyPoints(100), _MaxEnergyPoints(100), _Level(1), _MeleeAttackDamage(30),
	_RangedAttackDamage(20), _ArmorDamageReduction(5)
{
	std::cout << BOLD << GREEN << _Name << ": Séquence d'initiation terminée.\
 Bonjour, je suis votre nouveau robot multifonction.\
 Nom : " << _Name << ". Niveau: " << _Level << ". Energie Max: " << _MaxEnergyPoints
 << ". Robot d'Hyperion classe C type CL4P-TP. Veuillez régler\
 les paramètres d'usine en fonction de vos besoins avant déploiement."
 << RESET << std::endl;
	srand(time(0));
}

ClapTrap::ClapTrap(int const n) : _HitPoints(n)
{
	
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    *this = src;
}

ClapTrap::~ClapTrap()
{
    std::cout << GREEN << BOLD << _Name << ": Destruction du ClapTrap..."
              << RESET << std::endl;
}

int ClapTrap::getHealth() const
{
	return (_HitPoints);
}

void ClapTrap::getHit() const
{
	std::cout << PINK << _Name << ": Diagnostique en cours... Il me reste " << _HitPoints
			  << " points de vies." << std::endl;
}

void ClapTrap::getEnergy() const
{
	std::cout << PINK << _Name << ": Diagnostique en cours... Il me reste " << _EnergyPoints
			  << " points d'energie." << std::endl;
}

int ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << BOLD << RED << "SC4V-TP " << _Name << " attaque " << target
			  << " à distance, causant " << _RangedAttackDamage << " points de dégats !"
			  << RESET << std::endl;
	return (_RangedAttackDamage);
}

int ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << BOLD << RED << "SC4V-TP " << _Name << " attaque " << target
			  << " en mêlée, causant " << _MeleeAttackDamage << " points de dégats !"
			  << RESET << std::endl;
	return (_MeleeAttackDamage);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints - (int)amount + _ArmorDamageReduction < 0)
		_HitPoints = 0;
	else
		_HitPoints -= amount - _ArmorDamageReduction;
	std::cout << RED << _Name << ": Systeme endommagé... Dégats reçu: " << amount
			  << " ... Points de vie restant: " << _HitPoints << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_HitPoints + (int)amount > _MaxHitPoints)
		_HitPoints = _MaxHitPoints;
	else
		_HitPoints = amount;
	std::cout << BLUE << _Name << ": Auto-Réparation terminé... Il me reste " << _HitPoints
			  << " points de vie." << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &ClapTrap)
{
	o << ClapTrap.getHealth();
	return o;
}