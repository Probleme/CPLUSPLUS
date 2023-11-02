/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:06:07 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/22 02:53:35 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream> 
#include <iomanip>
#include <ostream>

class Contact{
    public:
        Contact(void);
        ~Contact(void);
        void print_table(int index) const;
        void print_infos(void) const;
        void set_infos(std::string firstName, std::string lastName,
        std::string nickname, std::string phoneNumber, std::string darkestSecret);
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
};

#endif