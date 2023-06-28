/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:09:33 by Manny             #+#    #+#             */
/*   Updated: 2023/04/26 19:25:50 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_memchr searches n bytes of the memory area pointed to
	by s for the first occurence of c. Both c and the bytes of s are
	interpreted as unsigned char.

	RETURN VALUE:
	A pointer to the matching byte. NULL if the character does not occur
	in the given memory area.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		ch;
	const unsigned char	*str;

	ch = c;
	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
