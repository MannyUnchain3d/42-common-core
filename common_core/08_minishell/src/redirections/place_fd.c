/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:50:08 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 15:10:31 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	place_fd_out(t_cmd *cmd);
static int	place_fd_app(t_cmd *cmd);

/* Sets up fds for input and output redirection in the given command.
 * If input or output file fails to open, prints an errmsg and returns false.
 * Uses place_fd_out and place_fd_app for output and append redirection.
 * Returns True if fds are placed successfully, false otherwise. */

int	place_fd(t_cmd *cmd)
{
	int		i;

	i = 0;
	if (cmd->io_fds)
	{
		if (cmd->io_fds->infile[0])
		{
			while (cmd->io_fds->infile[i++])
			{
				cmd->io_fds->fd_in = open(cmd->io_fds->infile[i - 1], O_RDONLY);
				if (cmd->io_fds->fd_in == -1)
				{
					errmsg(cmd->io_fds->infile[i - 1], strerror(errno), 0);
					return (false);
				}
			}
		}
		if (place_fd_out(cmd) == false)
			return (false);
		if (place_fd_app(cmd) == false)
			return (false);
	}
	return (true);
}

static int	place_fd_out(t_cmd *cmd)
{
	int	i;
	int	res;

	if (cmd->io_fds->outfile[0])
	{
		i = 0;
		while (cmd->io_fds->outfile[i++])
		{
			if (opendir(cmd->io_fds->outfile[i - 1]))
			{
				errmsg(cmd->io_fds->outfile[i - 1], "Is a directory", 0);
				return (false);
			}
			res = open(cmd->io_fds->outfile[i - 1], \
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (res == -1)
			{
				errmsg(cmd->io_fds->outfile[i - 1], strerror(errno), 0);
				return (false);
			}
			else
				cmd->io_fds->fd_out = res;
		}
	}
	return (true);
}

static int	place_fd_app(t_cmd *cmd)
{
	int	i;
	int	res;

	if (cmd->io_fds->append[0])
	{
		i = 0;
		while (cmd->io_fds->append[i++])
		{
			if (opendir(cmd->io_fds->append[i - 1]))
			{
				errmsg(cmd->io_fds->append[i - 1], "Is a directory", 0);
				return (false);
			}
			res = open(cmd->io_fds->append[i - 1], \
				O_WRONLY | O_CREAT | O_APPEND, 0777);
			if (res == -1)
			{
				errmsg(cmd->io_fds->append[i - 1], strerror(errno), 0);
				return (false);
			}
			else
				cmd->io_fds->fd_out = res;
		}
	}
	return (true);
}
