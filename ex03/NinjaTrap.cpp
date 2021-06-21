/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:14:01 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/21 15:07:41 by rbourgea         ###   ########.fr       */
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

std::ostream &operator<<(std::ostream &o, NinjaTrap const &NinjaTrap)
{
	o << NinjaTrap.getHealth();
	return o;
}