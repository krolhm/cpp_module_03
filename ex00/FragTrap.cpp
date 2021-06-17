/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:44:09 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/17 15:55:52 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{

}

FragTrap::FragTrap(std::string name)
{

}

FragTrap::FragTrap(int const n)
{

}

FragTrap::FragTrap(FragTrap const & src)
{
    
}

FragTrap::~FragTrap()
{

}

void FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "<FR4G-TP " << _Name << " attaque " << target << " à distance, causant"
	          << _RangedAttackDamage << " points de dégats !" << std::endl;
}
