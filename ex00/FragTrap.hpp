/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:44:19 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/16 12:34:30 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <cstring>

class FragTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(int const n);
        FragTrap(FragTrap const & src);
        ~FragTrap();
        void rangedAttack(std::string const & target);
        void meleeAttack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
    private:
        int _HitPoints;
        int _MaxHitPoints;
        int _EnergyPoints;
        int _MaxEnergyPoints;
        int _Level;
        std::string _Name;
        int _MeleeAttackDamage;
        int _RangedAttackDamage;
        int _ArmorDamageReduction;
};

std::ostream & operator << (std::ostream & o, FragTrap const & i);

#endif
