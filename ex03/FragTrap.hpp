/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:44:19 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/21 13:58:19 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(int const n);
		FragTrap(FragTrap const & src);
		~FragTrap();

		int vaulthunter_dot_exe(std::string const &target);
};

std::ostream & operator << (std::ostream & o, FragTrap const & i);

#endif
