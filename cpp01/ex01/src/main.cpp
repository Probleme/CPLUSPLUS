/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:45:42 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 18:00:24 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main()
{
    Zombie *zombies = zombieHorse(10, "Zombie");
    for (int i = 0; i < 10; i++)
        zombies[i].announce();
    delete [] zombies;
    return (0);
}