/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <nicklaw@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:26:24 by Manny             #+#    #+#             */
/*   Updated: 2023/06/14 19:58:01 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Exits the minishell cleanly by closing all opened file descriptors
 * and freeing all allocated memory. */
void	exit_shell(t_data *data, int exno)
{
	if (data)
	{
		if (data->cmd && data->cmd->io_fds)
			close_fds(data->cmd, true);
		free_data(data, true, true);
		rl_clear_history();
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &data->original);
	}
	exit(exno);
}
