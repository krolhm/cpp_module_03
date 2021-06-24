/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:17:00 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/24 15:15:16 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), NinjaTrap(name), FragTrap(name)
{
	_HitPoints = FragTrap::_HitPoints;
	_MaxHitPoints = FragTrap::_HitPoints;
	_EnergyPoints = NinjaTrap::_EnergyPoints;
	_MaxEnergyPoints = NinjaTrap::_MaxEnergyPoints;
	_MeleeAttackDamage = NinjaTrap::_MeleeAttackDamage;
	_RangedAttackDamage = FragTrap::_RangedAttackDamage;
	_ArmorDamageReduction = FragTrap::_ArmorDamageReduction;
}

SuperTrap::SuperTrap(int const n) : ClapTrap(n), NinjaTrap(n), FragTrap(n)
{

}

SuperTrap::SuperTrap(const SuperTrap &src) : ClapTrap(src), NinjaTrap(src), FragTrap(src)
{
	*this = src;
}

SuperTrap::~SuperTrap()
{
	std::cout << GREEN << BOLD << _Name << ": SuperTrap désactivé."
			  << RESET << std::endl;
}

SuperTrap &SuperTrap::operator=(const SuperTrap &rhs)
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
