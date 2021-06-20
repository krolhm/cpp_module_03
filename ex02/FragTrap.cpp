/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:44:09 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/20 13:18:39 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : _Name(name), _HitPoints(100), _MaxHitPoints(100),
	_EnergyPoints(100), _MaxEnergyPoints(100), _Level(1), _MeleeAttackDamage(30),
	_RangedAttackDamage(20), _ArmorDamageReduction(5)
{
	std::cout << BOLD << GREEN << _Name << ": Séquence d'initiation terminée.\
 Bonjour, je suis votre nouveau robot multifonction.\
 Nom : " << _Name << ". Niveau: " << _Level << ". Energie Max: " << _MaxEnergyPoints
 << ". Robot d'Hyperion classe F. Veuillez régler\
 les paramètres d'usine en fonction de vos besoins avant déploiement."
 << RESET << std::endl;
	srand(time(0));
}

FragTrap::FragTrap(int const n) : _HitPoints(n)
{

}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << GREEN << BOLD << _Name << ": Passez un bon après-midi. Et merci d'utiliser\
 les services robotiques d'Hyperion." 
	<< RESET << std::endl;
}

int FragTrap::getHealth() const
{
	return (_HitPoints);
}

void FragTrap::getHit() const
{
	std::cout << PINK << _Name << ": Diagnostique en cours... Il me reste " << _HitPoints
			<< " points de vies." << std::endl;
}

void FragTrap::getEnergy() const
{
	std::cout << PINK << _Name << ": Diagnostique en cours... Il me reste " << _EnergyPoints
			<< " points d'energie." << std::endl;
}

int FragTrap::rangedAttack(std::string const & target)
{
	std::cout << BOLD << RED << "FR4G-TP " << _Name << " attaque " << target 
	<< " à distance, causant " << _RangedAttackDamage << " points de dégats !" 
	<< RESET << std::endl;
	return (_RangedAttackDamage);
}

int FragTrap::meleeAttack(std::string const & target)
{
	std::cout << BOLD << RED << "FR4G-TP " << _Name << " attaque " << target << 
	" en mêlée, causant " << _MeleeAttackDamage << " points de dégats !" 
	<< RESET << std::endl;
	return (_MeleeAttackDamage);
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints - (int)amount + _ArmorDamageReduction < 0)
		_HitPoints = 0;
	else
		_HitPoints -= amount - _ArmorDamageReduction;
	std::cout << RED << _Name << ": Systeme endommagé... Dégats reçu: " << amount 
			<< " ... Points de vie restant: " << _HitPoints << RESET << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_HitPoints + (int)amount > _MaxHitPoints)
		_HitPoints = _MaxHitPoints;
	else
		_HitPoints = amount;
	std::cout << BLUE << _Name << ": Auto-Réparation terminé... Il me reste " << _HitPoints
			<< " points de vie." << RESET << std::endl;
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

std::ostream &operator<<(std::ostream &o, FragTrap const &FragTrap)
{
	o << FragTrap.getHealth();
	return o;
}