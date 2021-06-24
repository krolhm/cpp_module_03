/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:12:41 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/23 14:20:16 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
	public:
        NinjaTrap();
		NinjaTrap(std::string name);
        NinjaTrap(int const n);
        NinjaTrap(NinjaTrap const &src);
        ~NinjaTrap();
        int rangedAttack(std::string const &target);
        int meleeAttack(std::string const &target);
        void ninjaShoeBox(FragTrap &target);
        void ninjaShoeBox(ScavTrap &target);
        void ninjaShoeBox(ClapTrap &target);
        void ninjaShoeBox(NinjaTrap &target);

        NinjaTrap &operator=(const NinjaTrap &rhs);
};

std::ostream &operator<<(std::ostream &o, FragTrap const &i);

#endif