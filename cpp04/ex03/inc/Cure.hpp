/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:58:08 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/04 11:59:06 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria{
    public:
        Cure();
        Cure(const Cure &c);
        Cure& operator=(const Cure &c);
        virtual ~Cure();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif