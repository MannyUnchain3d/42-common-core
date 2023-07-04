/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:40:20 by Manny             #+#    #+#             */
/*   Updated: 2023/07/05 01:54:17 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define MAGENTA	"\033[0;35m"
# define LRED		"\033[0;91m"
# define BOLD		"\033[1m"
# define BLINK		"\033[5m"
# define RESET		"\033[0m"

class	PhoneBook {
	private:
		int		_index;
		bool	_abort;
		Contact	_list[8];

		std::string	_getInput(std::string const prompt);
		void		_incrementIndex(void);
		void		_printTable(void) const;
		void		_printInfo(int const index) const;
		void		_printTableString(std::string str) const;
		bool		_printContactByIndex(std::string const input) const;
	
	public:
		PhoneBook(void);
		~PhoneBook(void);

		std::string	trimSpace(std::string str);
		bool		addContact(void);
		bool		searchContact(void);
};

#endif