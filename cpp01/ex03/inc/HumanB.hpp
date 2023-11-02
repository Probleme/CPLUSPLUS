/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:09:23 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 19:59:32 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string const _name;
        Weapon *_weapon;
    public:
        HumanB(std::string const name);
        ~HumanB();
        void attack(void) const;
        void setWeapon(Weapon &weapon);
};

#endif