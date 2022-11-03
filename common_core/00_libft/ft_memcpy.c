/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:39:25 by etetopat          #+#    #+#             */
/*   Updated: 2022/08/30 13:53:21 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memcpy copies n bytes from memory area src to memory
	area dst.
	Does not account for memory overlaps. Use ft_memmove if the memory areas
	overlap or might overlap.

	RETURN VALUE :
	A pointer to dst. NULL if src and dst are both NULL.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;

	if (!dst && !src)
		return (0);
	if (n == 0 || (dst == src))
		return (dst);
	dp = (char *)dst;
	sp = (const char *)src;
	while (n != 0)
	{
		if (*dp != *sp)
			*dp = *sp;
		dp++;
		sp++;
		n--;
	}
	return (dst);
}
