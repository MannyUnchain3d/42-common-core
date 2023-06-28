/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:15:50 by Manny             #+#    #+#             */
/*   Updated: 2023/06/23 15:59:05 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	DESCRIPTION:
	The function ft_putstr writes the given string to the standard output 
	
	RETURN VALUE:
	None.
*/

#include "libft.h"

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
