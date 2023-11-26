/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:50:40 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/26 00:20:59 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("ScavTrap");

    scavTrap.attack("target");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(5);
    scavTrap.guardGate();
    return (0);
}
