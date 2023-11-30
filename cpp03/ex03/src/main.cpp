/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:50:40 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/28 00:10:35 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

int main() {
    DiamondTrap diamondTrap("DiamondTrap");
    diamondTrap.attack("target");
    diamondTrap.beRepaired(10);
    diamondTrap.takeDamage(10);
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    diamondTrap.whoAmI();
    return (0);
}
