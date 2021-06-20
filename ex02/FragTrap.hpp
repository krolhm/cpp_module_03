/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:44:19 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/19 14:32:43 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <cstring>

class FragTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(int const n);
		FragTrap(FragTrap const & src);
		~FragTrap();
		int rangedAttack(std::string const & target);
		int meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int vaulthunter_dot_exe(std::string const &target);
		void getHit() const;
		void getEnergy() const;
		int getHealth() const;
		std::string _Name;

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

std::ostream & operator << (std::ostream & o, FragTrap const & i);

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PINK "\033[35m"

#endif
