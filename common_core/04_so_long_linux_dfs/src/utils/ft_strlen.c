/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:40:23 by etetopat          #+#    #+#             */
/*   Updated: 2022/11/30 20:02:16 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
	DESCRIPTION:
	The function ft_strlen measures the length of the given string str,
	excluding the terminating \0 character.

	RETURN VALUE:
	The number of bytes in the string str.
*/

int	ft_strlen(const char *str, int type)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (type == 1)
	{
		if (i > 0 && str[i - 1] == '\n')
			i--;
	}
	return (i);
}
