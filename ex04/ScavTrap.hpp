/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:21:09 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/23 11:27:50 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(int const n);
        ScavTrap(ScavTrap const &src);
        ~ScavTrap();

		void challengeNewcomer();
		ScavTrap &operator=(ScavTrap const &rhs);
};

std::ostream & operator << (std::ostream & o, ScavTrap const & i);

#endif