/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:52:23 by Manny             #+#    #+#             */
/*   Updated: 2023/06/22 21:00:52 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Frees data used to run a command. If `clear_history` is true, frees the env
 * and command history before returning. */
void	free_data(t_data *data, bool clear_history, bool clear_input)
{
	if (data)
	{
		if (clear_history)
		{
			if (data->wd)
				free_ptr(data->wd);
			if (data->old_wd)
				free_ptr(data->old_wd);
			if (data->env)
				free_str_tab(data->env);
			rl_clear_history();
		}
		if (clear_input)
		{
			if (data->user_input)
			{
				free_ptr(data->user_input);
				data->user_input = NULL;
			}
			if (data->cmd)
				clear_cmd(data->cmd);
		}
	}
}

/* Closes opened fds, including pipes and input/output fds. If `close_backups`
 * is true, closes the backup STDIN and STDOUT fds as well. */
void	close_fds(t_cmd *cmds, bool close_backups)
{
	if (cmds->io_fds)
	{
		if (cmds->io_fds->fd_in != -1)
			close(cmds->io_fds->fd_in);
		if (cmds->io_fds->fd_out != -1)
			close(cmds->io_fds->fd_out);
		if (close_backups)
			restore_io(cmds->io_fds);
	}
	close_pipe_fds(cmds, NULL);
}

/* Frees the input/output fd structure. */
void	free_io(t_io_fds *io)
{
	if (!io)
		return ;
	restore_io(io);
	if (io->heredoc_delimiter)
		free_str_tab(io->heredoc_delimiter);
	if (io->infile)
		free_str_tab(io->infile);
	if (io->outfile)
		free_str_tab(io->outfile);
	if (io)
		free_ptr(io);
}

/* Frees an array of strings. */
void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free_ptr(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

/* Frees a pointer of any type if it's not NULL and sets it to NULL.
 * Avoids double free errors. */
void	free_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
