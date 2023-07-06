/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:21:17 by Manny             #+#    #+#             */
/*   Updated: 2023/06/28 12:43:00 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Checks if the given number goes over the limit of a long long int.
 * Sets a boolean to true if it does or false if it doesn't. */
static bool	is_int_overflow(int neg, unsigned long long nb, bool *error)
{
	if ((neg == 1 && nb > LLONG_MAX)
		|| (neg == -1 && nb > -(unsigned long long)LLONG_MIN))
		*error = true;
	return (*error);
}

/* Converts a string to a long long int. If the string is not a valid number,
 * sets a boolean to true. */
static int	ft_atoll(const char *str, bool *error)
{
	unsigned long long	nb;
	int					neg;
	int					i;

	nb = 0;
	neg = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		if (is_int_overflow(neg, nb, error))
			break ;
		i++;
	}
	return (nb * neg);
}

/* Retrieves the exit code from the argument given to the exit builtin command.
 * Returns 0 if there is no argument.
 * Returns 1 if the argument is not a valid number.
 * Returns the exit code reduced to 0-255 if the argument is a valid number. */
static int	get_exit_code(char *arg, bool *error)
{
	unsigned long long	i;

	if (!arg)
		return (0);
	i = 0;
	while (ft_isspace(arg[i]))
		i++;
	if (arg[i] == '\0')
		*error = true;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (!ft_isdigit(arg[i]))
		*error = true;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && !ft_isspace(arg[i]))
		{
			*error = true;
			return (255);
		}
		i++;
	}
	i = ft_atoll(arg, error);
	return (i % 256);
}

/* Prints "exit" and exits the shell with the provided exit code or 0.
 * If exit is piped, it exits the child process with the provided exit code,
 * but does not exit the shell.
 * Returns an error exit code if there are too many args,
 * or if the arg is not a valid number, and does not exit the shell. */
int	exit_builtin(t_data *data, char **args)
{
	int		exit_code;
	bool	error;

	error = false;
	if (!args || !args[1])
		exit_code = 0;
	else
	{
		exit_code = get_exit_code(args[1], &error);
		if (error)
		{
			errmsg_cmd("exit", args[1], "numeric argument required", 255);
			exit_code = 255;
			exit_shell(data, exit_code);
		}
		if (args[2])
		{
			errmsg_cmd("exit", NULL, "too many arguments", 1);
			return (1);
		}
	}
	ft_putendl_fd("exit", 1);
	exit_shell(data, exit_code);
	return (2);
}
