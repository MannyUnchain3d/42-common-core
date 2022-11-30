/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:33:23 by Manny             #+#    #+#             */
/*   Updated: 2022/11/30 18:24:28 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\nError\n", 2);
	exit (EXIT_FAILURE);
}
