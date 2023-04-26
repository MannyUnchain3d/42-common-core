/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:52:34 by etetopat          #+#    #+#             */
/*   Updated: 2023/04/26 19:11:26 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_calloc allocates a block of memory for an array of 
	count elements, each of size bytes, and initializes the memory to zero.

	It takes two arguments: the number of elements to allocate memory for 
	and the size of each element.

	RETURN VALUE:
	The pointer to the allocated memory. NULL if the memory allocation fails.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
