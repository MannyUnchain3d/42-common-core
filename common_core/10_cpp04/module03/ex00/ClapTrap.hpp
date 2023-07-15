/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:48:28 by Manny             #+#    #+#             */
/*   Updated: 2023/07/15 20:48:34 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define BOLD		"\033[1m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"
# define BLINK		"\033[5m"
# define NC			"\033[0m"

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& src);
		~ClapTrap(void);

		ClapTrap& operator=(const ClapTrap& rhs);

		virtual	~ClapTrap(void);
};

#endif