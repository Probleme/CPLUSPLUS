/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:50:40 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/26 00:15:13 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("testclap");

    clapTrap.attack("target");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);
    return (0);
}
