/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:12:41 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/21 14:13:49 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(std::string name);
        NinjaTrap(int const n);
        NinjaTrap(NinjaTrap const &src);
        ~NinjaTrap();

};

std::ostream & operator << (std::ostream & o, NinjaTrap const & i);

#endif