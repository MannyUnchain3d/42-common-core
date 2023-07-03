/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <nicklaw@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:56:00 by Manny             #+#    #+#             */
/*   Updated: 2023/06/16 19:04:00 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Creates a set of pipes for each command in cmds.
 * Returns 1 on success, 0 on failure. */
bool	create_pipes(t_data *data)
{
	t_cmd	*tmp;

	tmp = data->cmd;
	while (tmp)
	{
		if (tmp->pipe_output || (tmp->prev && tmp->prev->pipe_output))
		{
			if (pipe(tmp->pipe_fd) != 0)
			{
				free_data(data, false, true);
				return (false);
			}
		}
		tmp = tmp->next;
	}
	return (true);
}

/* Sets the pipe fds for this command.
 * If the previous command is piped, the input fd is set as the read end
 * of the previous command, pipe_fd[0].
 * If the next command is piped, the output fd is set as the write end
 * of the next command, pipe_fd[1].
 * Returns true when the pipe fds are set, false otherwise. */
bool	set_pipe_fds(t_cmd *cmds, t_cmd *c)
{
	if (!c)
		return (false);
	if (c->prev && c->prev->pipe_output)
		dup2(c->prev->pipe_fd[0], STDIN_FILENO);
	if (c->pipe_output)
		dup2(c->pipe_fd[1], STDOUT_FILENO);
	close_pipe_fds(cmds, c);
	return (true);
}

/* Closes all pipe fds except for the ones in skip_cmd.
 * The parent specifies NULL for skip_cmd while closing all pipe fds.
 * The child specifies its own skip_cmd, while closing all pipe fds, to avoid
 * closing its own pipe fds. */
void	close_pipe_fds(t_cmd *cmds, t_cmd *skip_cmd)
{
	while (cmds)
	{
		if (cmds != skip_cmd && cmds->pipe_fd[0] != -1)
		{
			close(cmds->pipe_fd[0]);
			close(cmds->pipe_fd[1]);
		}
		cmds = cmds->next;
	}
}
