/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:40:54 by ataouaf           #+#    #+#             */
/*   Updated: 2023/12/03 16:06:33 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
    private:
        Brain* _brain;
    public:
        Cat();
        Cat(const Cat &c);
        Cat& operator=(const Cat &c);
        virtual ~Cat();
        void makeSound() const;
};


#endif