/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:40:23 by Manny             #+#    #+#             */
/*   Updated: 2023/11/10 21:48:26 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(std::string const& target);
		ShrubberyCreationForm(ShrubberyCreationForm const& rhs);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

		void	execute(Bureaucrat const& executor) const;

	private:
		std::string const _target;
		
		ShrubberyCreationForm(void);
};

#endif
