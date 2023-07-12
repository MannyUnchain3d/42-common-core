/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BetterSed.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:51:47 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/12 20:23:31 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BETTERSED_HPP
# define BETTERSED_HPP

# include <iostream>
# include <cstdlib>
# include <fstream>

class BetterSed {
	public:
		BetterSed(std::string const& filename);
		~BetterSed(void);

		void	replace(std::string s1, std::string s2);

	private:
		std::string	_infile;
		std::string	_outfile;
};

#endif