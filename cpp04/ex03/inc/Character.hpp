/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:31:45 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/06 10:29:59 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter{
    protected:
        std::string _name;
        AMateria* _inventory[4];
        AMateria** _materias;
        int _count;
    public:
        Character();
        Character(std::string const& name);
        Character(const Character& c);
        Character& operator=(const Character& c);
        virtual ~Character();
        virtual std::string const & getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif