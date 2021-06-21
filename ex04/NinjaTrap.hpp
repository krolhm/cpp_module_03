/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:12:41 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/21 15:19:29 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(std::string name);
        NinjaTrap(int const n);
        NinjaTrap(NinjaTrap const &src);
        ~NinjaTrap();

        void ninjaShoeBox(FragTrap &target);
        void ninjaShoeBox(ScavTrap &target);
        void ninjaShoeBox(ClapTrap &target);
        void ninjaShoeBox(NinjaTrap &target);
};

std::ostream & operator << (std::ostream & o, NinjaTrap const & i);

#endif