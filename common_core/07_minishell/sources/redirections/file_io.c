/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <nicklaw@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:56:05 by Manny             #+#    #+#             */
/*   Updated: 2023/06/15 15:51:15 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Checks if the infile and outfile are valid.
 * Returns 1 on success, 0 on failure. */
bool	check_infile_outfile(t_io_fds *io)
{
	if (!io || (!io->infile && !io->outfile))
		return (true);
	if ((!io->infile && io->fd_in != -1) || (!io->outfile && io->fd_out != -1))
		return (false);
	return (true);
}

/* Duplicates the input and output fds to stdin and stdout.
 * Saves the original stdin and stdout fds to stdin_backup and
 * stdout_backup before replacing them. Restores them after execution.
 * Returns 1 on success, 0 on failure. */
bool	redirect_io(t_io_fds *io)
{
	int	ret;

	ret = true;
	if (!io)
		return (ret);
	io->stdin_backup = dup(STDIN_FILENO);
	if (io->stdin_backup == -1)
		ret = errmsg_cmd("dup", "stdin_backup", strerror(errno), false);
	io->stdout_backup = dup(STDOUT_FILENO);
	if (io->stdout_backup == -1)
		ret = errmsg_cmd("dup", "stdout_backup", strerror(errno), false);
	if (io->fd_in != -1)
	{
		if (dup2(io->fd_in, STDIN_FILENO) == -1)
			ret = errmsg_cmd("dup2", "stdin_fileno", strerror(errno), false);
	}
	if (io->fd_out != -1)
	{
		if (dup2(io->fd_out, STDOUT_FILENO) == -1)
			ret = errmsg_cmd("dup2", "stdout_fileno", strerror(errno), false);
	}
	return (ret);
}

/* Restores the standard input and output file descriptors to their original
 * values 0 and 1. Clears the input and output fds after execution.
 * Returns 1 on success, 0 on failure. */
bool	restore_io(t_io_fds *io)
{
	int	ret;

	ret = true;
	if (!io)
		return (ret);
	if (io->stdin_backup != -1)
	{
		if (dup2(io->stdin_backup, STDIN_FILENO) == -1)
			ret = false;
		close(io->stdin_backup);
		io->stdin_backup = -1;
	}
	if (io->stdout_backup != -1)
	{
		if (dup2(io->stdout_backup, STDOUT_FILENO) == -1)
			ret = false;
		close(io->stdout_backup);
		io->stdout_backup = -1;
	}
	return (ret);
}
