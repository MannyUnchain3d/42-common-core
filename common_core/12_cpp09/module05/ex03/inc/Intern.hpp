/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:08:28 by Manny             #+#    #+#             */
/*   Updated: 2023/11/13 21:26:53 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const& rhs);
		~Intern();

		Intern&	operator=(Intern const& rhs);

		AForm*	makeForm(std::string formName, std::string target);
};

#endif
