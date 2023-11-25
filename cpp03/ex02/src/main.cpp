/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:50:40 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/23 11:13:20 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main()
{
    ClapTrap claptrap1; 
    ClapTrap claptrap2("Claptrap2");
    ClapTrap claptrap3 = claptrap1;
    ClapTrap claptrap4;
    claptrap4 = claptrap2;

    ScavTrap scavtrap1("Scavtrap1");
    scavtrap1.attack("Target1");
    scavtrap1.takeDamage(5);
    scavtrap1.beRepaired(5);
    scavtrap1.guardGate();

    FragTrap fragtrap1("Fragtrap1");
    fragtrap1.attack("Target1");
    fragtrap1.takeDamage(5);
    fragtrap1.beRepaired(5);
    fragtrap1.highFivesGuys();

    return 0;
}
