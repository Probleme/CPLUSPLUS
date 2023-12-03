/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:29:21 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/03 16:05:29 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const AAnimal &a);
        AAnimal& operator=(const AAnimal &a);
        virtual ~AAnimal() = 0;
        std::string getType() const;
        void makeSound() const;
};

#endif
