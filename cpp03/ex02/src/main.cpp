/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:50:40 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/26 00:18:12 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main()
{
    FragTrap fragTrap("FragTrap");
    ScavTrap scavTrap("ScavTrap");

    fragTrap.attack("target");
    fragTrap.takeDamage(5);
    fragTrap.beRepaired(5);
    fragTrap.highFivesGuys();
    scavTrap.attack("target");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(5);
    scavTrap.guardGate();
    return (0);
}
