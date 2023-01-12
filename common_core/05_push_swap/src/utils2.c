/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:22:22 by Manny             #+#    #+#             */
/*   Updated: 2023/01/12 18:24:03 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Frees all the elements of the array and sets its pointer to NULL */
void	ft_split_free(char **srcs)
{
	int	i;

	if (srcs != NULL)
	{
		i = 0;
		while (srcs[i] != NULL)
		{
			free(srcs[i]);
			i++;
		}
		free(srcs);
	}
}

/* Calculates the size of the array */
int	ft_split_size(char **srcs)
{
	int	i;

	i = 0;
	if (srcs != NULL)
	{
		while (srcs[i] != NULL)
			i++;
	}
	return (i);
}
