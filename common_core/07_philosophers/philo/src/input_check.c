/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:27:40 by Manny             #+#    #+#             */
/*   Updated: 2023/11/03 10:36:55 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Checks if the string contains only digits 0 - 9.
 * Returns true if the string only contains digits or false if not. */
static bool	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

/* Converts a digit-only string into a positive integer.
 * Returns the converted number between 0 and INT MAX or -1 if the converted
 * number exceeds INT MAX. */
int	digit_atoi(char *str)
{
	unsigned long long	nb;
	int					i;

	i = 0;
	nb = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}

/* Checks if all arguments are valid digit-only strings below INT MAX.
 * Checks if the number of philosophers is valid (between 1 and MAX_PHILOS).
 * Returns true if all arguments are valid or false if not. */
bool	is_valid_input(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	while (i < ac)
	{
		if (!str_is_digit(av[i]))
			return (msg(STR_ERR_INPUT_DIGIT, av[i], false));
		nb = digit_atoi(av[i]);
		if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
			return (msg(STR_ERR_INPUT_PHILO, STR_MAX_PHILOS, false));
		if (i != 1 && nb == -1)
			return (msg(STR_ERR_INPUT_DIGIT, av[i], false));
		i++;
	}
	return (true);
}
