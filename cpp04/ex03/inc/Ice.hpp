/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:53:21 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/04 11:54:39 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria{
    public:
        Ice();
        Ice(const Ice &i);
        Ice& operator=(const Ice &i);
        virtual ~Ice();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif