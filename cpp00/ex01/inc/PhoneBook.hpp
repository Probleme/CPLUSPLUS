/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 02:42:14 by ataouaf           #+#    #+#             */
/*   Updated: 2023/10/20 05:56:37 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
    public :
        PhoneBook(void);
        ~PhoneBook(void);
        bool    addContact(void);
        void    searchContact(void) const;
    private :
        int     _index;
        int     _nbContacts;
        Contact _contacts[8];
};

#endif