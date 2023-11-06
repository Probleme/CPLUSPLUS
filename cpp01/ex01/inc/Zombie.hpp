/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:47:42 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 18:37:43 by ataouaf          ###   ########.fr       */
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
        Zombie();
        ~Zombie(){ std::cout << this->_name << " has been destroyed" << std::endl; };
        void announce(std::string const _name){this->_name = _name;};
        void announce(void){std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;};
};

Zombie* zombieHorde(int N, std::string name);

#endif