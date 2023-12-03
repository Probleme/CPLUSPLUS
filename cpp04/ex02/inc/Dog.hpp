/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:34:37 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/03 16:06:30 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
    private:
        Brain* _brain;
    public:
        Dog();
        Dog(const Dog &d);
        Dog& operator=(const Dog &d);
        virtual ~Dog();
        void makeSound() const;
};

#endif