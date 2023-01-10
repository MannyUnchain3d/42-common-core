/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:07:05 by Manny             #+#    #+#             */
/*   Updated: 2023/01/07 16:21:13 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Checks if the argument is a number, returns 1 if number or 0 if not */
static int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] != '\0' && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

/* Checks if the argument is a duplicate, returns 1 if duplicate or 0 if not */
static int	arg_is_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && strnb_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* Checks if the argument is a zero to avoid duplicates (-0, +0, 00, +000 etc.)
 * Returns 1 if the argument is a zero, or 0 if not */
static int	arg_is_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] != '\0' && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

/* Checks if the argument is a valid number, returns 1 if valid or 0 if not */
int	is_valid_input(char **argv)
{
	int	i;
	int	zeros;

	i = 1;
	zeros = 0;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		zeros += arg_is_zero(argv[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (arg_is_duplicate(argv))
		return (0);
	return (1);
}

/* Writes an error message to the standard error, frees the array and exits
 * Used only if argv[1] is a string of numbers separated by spaces */
void	exit_error_strs(char **strs)
{
	if (strs)
		free(strs);
	write(2, "Error\n", 6);
	exit(1);
}
