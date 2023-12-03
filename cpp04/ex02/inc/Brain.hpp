/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 05:04:05 by ataouaf           #+#    #+#             */
/*   Updated: 2023/11/25 05:04:28 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP


#include <iostream>
#include <string>

class Brain{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &b);
        Brain& operator=(const Brain &b);
        virtual ~Brain();
        std::string getIdea(int i) const;
        void setIdea(int i, std::string idea);
};

#endif