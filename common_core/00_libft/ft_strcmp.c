/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:04:59 by Manny             #+#    #+#             */
/*   Updated: 2023/07/16 23:05:08 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_strcmp compares the given strings s1 and s2.

	RETURN VALUE:
	An integer less than, equal to, or greater than zero, if s1 is found to be
	less than, to match, or be greater than s2, respectively.
*/

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0')
		&& s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	else if (s1[i] != '\0' && s2[i] == '\0')
		return (1);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
