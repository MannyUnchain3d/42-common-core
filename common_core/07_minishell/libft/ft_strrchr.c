/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:44:01 by Manny             #+#    #+#             */
/*   Updated: 2023/04/26 19:32:46 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_strrchr finds the last occurrence of character c in
	string str.

	RETURN VALUE:
	A pointer to the last occurrence of c in str.
	NULL if c is not found.
*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*p;
	unsigned char	ch;
	size_t			offset;

	ch = c;
	offset = ft_strlen(str);
	p = (char *)str + offset;
	if (ch == '\0')
		return (p++);
	while (p >= str)
	{
		if (*p == ch)
			return (p);
		p--;
	}
	p = NULL;
	return (p);
}
