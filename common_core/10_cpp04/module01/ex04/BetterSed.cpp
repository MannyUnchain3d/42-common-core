/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BetterSed.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:31:31 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/12 18:02:13 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BetterSed.hpp"

BetterSed::BetterSed(std::string const& filename) : _infile(filename.c_str()) {
	this->_outfile = this->_infile + ".replace";
}

BetterSed::~BetterSed(void) {
}

void	BetterSed::replace(std::string s1, std::string s2) {
	std::string 	content;
	size_t			pos;

	std::ifstream	ifs(this->_infile.c_str());
	if (ifs.is_open()) {
		if (std::getline(ifs, content, '\0')) {
			std::ofstream	ofs(this->_outfile.c_str());
			pos = content.find(s1);
			while (pos != std::string::npos) {
				content.erase(pos, s1.length());
				content.insert(pos, s2);
				pos = content.find(s1);
			}
			ofs << content;
			ofs.close();
		}
		else
			std::cout << "Error: empty file" << std::endl;
		ifs.close();
	}
	else {
		std::cout << "Error: can't open file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}