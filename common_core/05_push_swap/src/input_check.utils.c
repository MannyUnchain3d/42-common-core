/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:08:38 by Manny             #+#    #+#             */
/*   Updated: 2022/12/26 17:35:19 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Checks if the character is a digit, returns 1 if digit or 0 if not */
int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* Checks if the character is a + or - sign, returns 1 if sign or 0 if not */
int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

/* Compares 2 strings of digits, + sign is ignored, returns 0 if they match */
int	strnb_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
