/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:43:57 by Manny             #+#    #+#             */
/*   Updated: 2023/11/13 20:24:14 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Parameter Constructor */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

/* Copy Constructor */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& rhs) :
	AForm(rhs), _target(rhs._target){
}

/* ----- DESTRUCTOR ------------------- */

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

/* ----- OPERATOR OVERLOAD ------------ */

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {
	(void)rhs;
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	
	std::ofstream file((this->getName() + "_shrubbery").c_str());
	file << "                      ___" << std::endl;
	file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
	file << "             ,-'          __,,-- \\" << std::endl;
	file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
	file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
	file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
	file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
	file << "     (     ,-'                  `." << std::endl;
	file << "      `._,'     _   _             ;" << std::endl;
	file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
	file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
	file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
	file << "                \"Hb HH dF" << std::endl;
	file << "                 \"HbHHdF" << std::endl;
	file << "                  |HHHF" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  dHHHb" << std::endl;
	file << "                .dFd|bHb." << std::endl;
	file << "              .dHFdH|HbTHb." << std::endl;
	file << "           __,dHHFdHH|HHhoHHb.__Hi It's Me Manny The Tree!" << std::endl;
	file << "##########################################################" << std::endl;
	file.close();
}
