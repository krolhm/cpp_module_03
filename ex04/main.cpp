/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:21:43 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/21 15:25:23 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

int main()
{
	FragTrap R2D2("R2D2");
	ScavTrap C3PO("C3PO");
	ClapTrap BB8("BB8");
	NinjaTrap K2SO("K2SO");
	
	K2SO.ninjaShoeBox(R2D2);
	K2SO.ninjaShoeBox(C3PO);
	K2SO.ninjaShoeBox(BB8);
	K2SO.ninjaShoeBox(K2SO);
}