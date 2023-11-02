/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:48:34 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 15:37:30 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(std::string name) : _name(name) {};
        ~Zombie() { std::cout << this->_name << " has been detroyed" << std::endl; };
        void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif