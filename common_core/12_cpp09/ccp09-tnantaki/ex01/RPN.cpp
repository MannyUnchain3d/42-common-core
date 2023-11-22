#include "RPN.hpp"

void	prtErrMsg(char const* msg)
{
	std::cerr << RED << msg << RESET << std::endl;
}

bool	isNumbers(std::string str)
{
	size_t	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	if (i == 1)
		return true;
	prtErrMsg("Error : Numbers must less than 10.");
	exit(1);
}

bool	isOperator(std::string str)
{
	if ((str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/') && !str[1])
		return true;
	else
		return false;
}

bool	operating(char opr, std::stack<int> &stk)
{
	int	nums;
	int	a;
	int	b;

	b = stk.top();
	stk.pop();
	if (stk.empty())
		return prtErrMsg("Error : Wrong expression."), false;
	a = stk.top();
	stk.pop();
	if (opr == '+')
		nums = a + b;
	else if (opr == '-')
		nums = a - b;
	else if (opr == '*')
		nums = a * b;
	else if (opr == '/')
	{
		if (b == 0)
			return prtErrMsg("Error : dividing by zero is undefined."), false;
		nums = a / b;
	}
	stk.push(nums);
	// std::cout << a << opr << b << "=" << stk.top() << std::endl; //debug
	return true;
}