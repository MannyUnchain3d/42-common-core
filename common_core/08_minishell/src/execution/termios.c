/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:54:03 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 17:39:14 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Initializes terminal settings for minishell:
 * Saves the current terminal settings for parent, child, and original states.
 * Toggles off the ECHOCTL flag in the parent terminal settings.
 * Enables the ECHOCTL and ECHO flags in the child terminal settings. */
void	init_termios(t_data *data)
{
	tcgetattr(STDIN_FILENO, &data->parent);
	tcgetattr(STDIN_FILENO, &data->child);
	tcgetattr(STDIN_FILENO, &data->original);
	data->parent.c_lflag ^= (ECHOCTL);
	data->child.c_lflag |= (ECHOCTL | ECHO);
}
