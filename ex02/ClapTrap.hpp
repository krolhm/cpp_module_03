/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 14:21:36 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/20 14:23:10 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstring>

class ClapTrap
{
public:
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
    std::string _Name;
    void challengeNewcomer();

private:
    int _HitPoints;
    int _MaxHitPoints;
    int _EnergyPoints;
    int _MaxEnergyPoints;
    int _Level;
    int _MeleeAttackDamage;
    int _RangedAttackDamage;
    int _ArmorDamageReduction;
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &i);

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"

#endif