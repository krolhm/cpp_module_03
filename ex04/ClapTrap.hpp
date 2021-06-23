/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 14:21:36 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/23 11:33:40 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <stdlib.h>
#include <iostream>
#include <cstring>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(int const n);
    ClapTrap(ClapTrap const &src);
    ~ClapTrap();
    int rangedAttack(std::string const &target);
    int meleeAttack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void getHit() const;
    void getEnergy() const;
    int getHealth() const;
    void challengeNewcomer();
    std::string _Name;

    ClapTrap &operator=(const ClapTrap &rhs);

protected:
    int _HitPoints;
    int _MaxHitPoints;
    int _EnergyPoints;
    int _MaxEnergyPoints;
    int _Level;
    int _MeleeAttackDamage;
    int _RangedAttackDamage;
    int _ArmorDamageReduction;
    int vaulthunter_dot_exe(std::string const &target);
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &i);

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"

#endif