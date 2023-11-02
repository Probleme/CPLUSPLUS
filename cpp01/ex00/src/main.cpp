/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:54:55 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 15:20:30 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("zombie");
    zombie->announce();
    delete zombie;
    randomChump("random");
    return (0);
}