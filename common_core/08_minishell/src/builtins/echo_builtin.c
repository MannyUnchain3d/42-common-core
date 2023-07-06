/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:52:26 by Manny             #+#    #+#             */
/*   Updated: 2023/06/24 17:55:43 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Checks the -n flags. Returns true if variation of -n is found (-nn, -nnn...)
 * Returns false if anything else is found. (-nnnmm, -n1234...) */
static bool	check_n_flag(char *arg)
{
	int	i;

	i = 0;
	if (arg[i++] != '-')
		return (false);
	if (arg[i] == 'n')
	{
		while (arg[i] == 'n')
			i++;
		if (!arg[i])
			return (true);
	}
	return (false);
}

/* Prints the arguments of the echo command to stdout. */
static void	echo_print_args(char **args, bool n_flag, int i)
{
	if (!args[i])
	{
		if (!n_flag)
			ft_putchar_fd('\n', STDOUT_FILENO);
		return ;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		else if (!args[i + 1] && !n_flag)
			ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
}

/* Prints the given strings and adds a \n or not depending on the -n flag.
 * Returns 0 on completion. */
int	echo_builtin(t_data *data, char **args)
{
	int		i;
	bool	n_flag;

	(void)data;
	n_flag = false;
	i = 1;
	while (args[i] && check_n_flag(args[i]))
	{
		n_flag = true;
		i++;
	}
	echo_print_args(args, n_flag, i);
	return (EXIT_SUCCESS);
}
