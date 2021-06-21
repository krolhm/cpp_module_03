/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:21:09 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/21 14:06:03 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(int const n);
        ScavTrap(ScavTrap const &src);
        ~ScavTrap();

		void challengeNewcomer();
};

std::ostream & operator << (std::ostream & o, ScavTrap const & i);

#endif