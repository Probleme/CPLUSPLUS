/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:05:26 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 20:02:17 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(std::string type);
        ~Weapon();
        std::string const &getType(void) const;
        void setType(std::string const &type);
};

#endif