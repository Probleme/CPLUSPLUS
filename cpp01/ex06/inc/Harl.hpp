/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:23:47 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 23:32:19 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
#include <map>

class Harl
{
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
    private:
        void debug()const;
        void info() const;
        void warning() const;
        void error() const;
};

#endif