/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:40:26 by Manny             #+#    #+#             */
/*   Updated: 2023/07/05 00:26:25 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define MAGENTA	"\033[0;35m"
# define LRED		"\033[0;91m"
# define BOLD		"\033[1m"
# define BLINK		"\033[5m"
# define RESET		"\033[0m"

class	Contact {
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_secret;
		
		bool		_onlyAlpha(std::string const input);
		bool		_onlyDigit(std::string const input);

	public:
		Contact(void);
		~Contact(void);

		std::string const	getFirstname(void) const;
		std::string const	getLastname(void) const;
		std::string const	getNickname(void) const;
		std::string const	getPhoneNumber(void) const;
		std::string const	getSecret(void) const;
		bool				isEmpty(void) const;
		bool				setFirstname(std::string str);
		bool				setLastname(std::string str);
		bool				setNickname(std::string str);
		bool				setPhoneNumber(std::string const str);
		bool				setSecret(std::string const str);
		bool				printContactInfo(void) const;
};

#endif