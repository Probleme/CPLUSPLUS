/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:46:36 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 18:32:27 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie* zombieHorse(int N, std::string name)
{
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombies[i].setName(name);
    return (zombies);
}