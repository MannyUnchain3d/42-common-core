/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BetterSed.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:51:47 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/12 13:54:15 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BETTERSED_HPP
# define BETTERSED_HPP

# include <iostream>
# include <cstdlib>
# include <fstream>

class BetterSed {
	public:
		BetterSed(std::string filename);
		~BetterSed(void);

		void	replace(std::string s1, std::string s2);

	private:
		std::string	_infile;
		std::string	_outfile;
};

#endif