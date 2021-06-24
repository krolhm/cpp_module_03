/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:44:09 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/24 15:22:03 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << BOLD << GREEN << _Name << ": Séquence d'initiation terminée.\
 Mise à jour ... FragTrap activé."
 << RESET << std::endl;
	_HitPoints = 100;
	_MaxHitPoints = 100;
	_RangedAttackDamage = 20;
	_ArmorDamageReduction = 5;
	srand(time(0));
}

FragTrap::FragTrap(int const n) : ClapTrap(n)
{

}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << GREEN << BOLD << _Name << ": FragTrap désactivé." 
	<< RESET << std::endl;
}

int FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int damage = 0;
	int random = rand() % 5;
	std::string randAttack[5] =
	{
		": Compétence activée: Punch d'Hyperion ! Ensemble, nous libérerons Pandora !",
		": BOOM ! Voilà... Je n'aime pas ça... ça me rend nerveux\
 - Respire profondément - je ne peux pas respirer ! C'est juste un enregistrement de\
 quelqu'un qui respire ! Ce n'est pas réel ! ça me rend juste encore plus nerveux !",
		": Pas question ! C'est, genre, mon troisième type de magie préféré ! Bon ok... *SPLASH*",
		": Je suis le meilleur robot. Ouais, ouais, je suis le meilleur robot.\
 Ooh, ooh, on y va ! Désintegration de l'ennemie.",
		": Mon Dieu. Cette fête est pire que des escaliers. Combustion de l'adversaire activée."
	};

	if (_EnergyPoints >= 25)
	{
		damage = (random + 3) * 2;
		std::cout << BOLD << RED << _Name << " vs " << target << randAttack[random] 
				<< RESET << std::endl;
		_EnergyPoints -= 25;
	}
	else
		std::cout << BOLD << RED << _Name << ": Je ne peux pas faire ça, il me manque " 
			<< 25 - _EnergyPoints << " pour activer vaulthunter.exe" << std::endl;
	return (damage);
}

int FragTrap::rangedAttack(std::string const &target)
{
	std::cout << BOLD << RED << "FR4G-TP " << _Name << " attaque " << target
			  << " à distance, causant " << _RangedAttackDamage << " points de dégats !"
			  << RESET << std::endl;
	return (_RangedAttackDamage);
}

int FragTrap::meleeAttack(std::string const &target)
{
	std::cout << BOLD << RED << "FR4G-TP " << _Name << " attaque " << target
			  << " en mêlée, causant " << _MeleeAttackDamage << " points de dégats !"
			  << RESET << std::endl;
	return (_MeleeAttackDamage);
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	_HitPoints = rhs._HitPoints;
	_MaxHitPoints = rhs._MaxHitPoints;
	_EnergyPoints = rhs._EnergyPoints;
	_MaxEnergyPoints = rhs._MaxEnergyPoints;
	_Level = rhs._Level;
	_MeleeAttackDamage = rhs._MeleeAttackDamage;
	_RangedAttackDamage = rhs._RangedAttackDamage;
	_ArmorDamageReduction = rhs._ArmorDamageReduction;
	_Name = rhs._Name;
	return *this;
}

std::ostream &operator<<(std::ostream &o, FragTrap const &i)
{
	o << i.getHealth();
	return o;
}