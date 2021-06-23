/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:17:15 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/23 11:25:52 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : virtual public ClapTrap, public NinjaTrap, public FragTrap
{
	public:
		SuperTrap();
		SuperTrap(std::string name);
		SuperTrap(int const n);
		SuperTrap(const SuperTrap & src);
		~SuperTrap(void);

		SuperTrap &operator=(const SuperTrap &rhs);
};

#endif