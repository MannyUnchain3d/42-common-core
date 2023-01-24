/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:15:50 by Manny             #+#    #+#             */
/*   Updated: 2023/01/25 02:16:44 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Prints a string to the standard output */
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		write(1, &str[i], 1);
		i++;
	}
}
