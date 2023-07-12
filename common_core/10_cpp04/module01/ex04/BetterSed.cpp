/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BetterSed.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:31:31 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/12 23:05:32 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BetterSed.hpp"

BetterSed::BetterSed(std::string const& filename) : _infile(filename.c_str()) {
	this->_outfile = this->_infile + ".replace";
}

BetterSed::~BetterSed(void) {
}

void	BetterSed::replace(std::string s1, std::string s2) {
	std::ifstream	ifs(this->_infile.c_str());
	if (!ifs.is_open()) {
		std::cout << "Error: cannot open file " << this->_infile << std::endl;
		std::exit(EXIT_FAILURE);
	}

	std::string	content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	ifs.close();

	if (content.empty()) {
		std::cout << "Error: file " << this->_infile << " is empty" << std::endl;
		return ;
	}

	std::ofstream	ofs(this->_outfile.c_str());
	if (!ofs.is_open()) {
		std::cout << "Error: cannot create outpule file " << this->_outfile << std::endl;
		std::exit(EXIT_FAILURE);
	}

	if (s1 != s2) {
		size_t	pos = content.find(s1);
		size_t	len = s1.length();
		while (pos != std::string::npos) {
			content.erase(pos, len);
			content.insert(pos, s2);
			pos = content.find(s1, pos + s2.length());
		}
	}
	else {
		std::cout << "Error: s1 and s2 are the same" << std::endl;
		return ;
	}
	ofs << content;
	ofs.close();
}