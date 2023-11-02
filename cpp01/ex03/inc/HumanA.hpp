/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:08:17 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 20:06:09 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string const _name;
        Weapon const &_weapon;
    public:
        HumanA(std::string const& name, Weapon const& weapon);
        ~HumanA();
        void attack(void) const;
};
#endif