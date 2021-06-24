/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:44:19 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/23 14:19:13 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(int const n);
		FragTrap(FragTrap const & src);
		~FragTrap();
		int rangedAttack(std::string const &target);
		int meleeAttack(std::string const &target);
		int vaulthunter_dot_exe(std::string const &target);

		FragTrap &operator=(const FragTrap &rhs);
};

std::ostream &operator<<(std::ostream &o, FragTrap const &i);

#endif
