/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:40:12 by etetopat          #+#    #+#             */
/*   Updated: 2023/10/30 18:44:21 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_isprint checks whether c is a printable character or not.

	RETURN VALUE:
	Non-zero if c is printable, zero if not.
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 33 && c < 127)
		return (1);
	return (0);
}
