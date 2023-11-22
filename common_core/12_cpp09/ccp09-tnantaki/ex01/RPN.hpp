#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>	// std::stack
#include <sstream>	// istringstream
#include <cstdlib>	// atoi

# define BLACK	"\e[0;30m"
# define RED	"\e[0;31m"
# define GREEN	"\e[0;32m"
# define YELLOW	"\e[0;33m"
# define BLUE	"\e[0;34m"
# define PURPLE	"\e[0;35m"
# define CYAN	"\e[0;36m"
# define WHITE	"\e[0;37m"
# define RESET	"\e[0m"

void	prtErrMsg(char const* msg);
bool	isNumbers(std::string str);
bool	isOperator(std::string str);
bool	operating(char opr, std::stack<int> &stk);

#endif