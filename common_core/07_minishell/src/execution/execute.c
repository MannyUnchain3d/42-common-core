/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <nicklaw@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:29:39 by Manny             #+#    #+#             */
/*   Updated: 2023/06/28 15:21:18 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Waits for child processes to terminate, cleans up file descriptors
 * and the command list, and retrieves the exit status of the processes.
 * Returns exit status of a single command or the last command in a pipeline.
 * Returns (128 + signal number) if terminated by a signal.
 * Returns the last value of save_stat on error. */
int	get_children(t_data *data)
{
	pid_t	wpid;
	int		status;
	int		save_stat;

	set_signals_noninteractive(data);
	close_fds(data->cmd, false);
	save_stat = 0;
	wpid = 0;
	while (wpid != -1 || errno != ECHILD)
	{
		wpid = waitpid(-1, &status, 0);
		if (wpid == data->pid)
			save_stat = status;
		continue ;
	}
	status = handle_exit_status(save_stat);
	return (status);
}

int	get_children_children(t_data *data)
{
	pid_t	wpid;
	int		status;
	int		save_stat;

	close_fds(data->cmd, false);
	save_stat = 0;
	wpid = 0;
	while (wpid != -1 || errno != ECHILD)
	{
		wpid = waitpid(-1, &status, 0);
		if (wpid == data->pid)
			save_stat = status;
		continue ;
	}
	if (WIFSIGNALED(save_stat))
		status = 128 + WTERMSIG(save_stat);
	else if (WIFEXITED(save_stat))
		status = WEXITSTATUS(save_stat);
	else
		status = save_stat;
	return (status);
}

/* Creates child processes for each command, except builtins or non-piped.
 * Returns the exit code from the last child to terminate.
 * Returns 1 if fork fails. */
static int	create_children(t_data *data)
{
	t_cmd	*cmd;
	int		ret;

	ret = 0;
	cmd = data->cmd;
	data->pid = fork();
	if (data->pid == -1)
		return (errmsg_cmd("fork", NULL, strerror(errno), EXIT_FAILURE));
	else if (data->pid == 0)
	{
		set_signals_child(data);
		heredoc_imp(data->cmd, data);
		while (cmd)
		{
			data->pid = fork();
			if (data->pid == -1)
				return (errmsg_cmd("fork", NULL, strerror(errno), 1));
			else if (data->pid == 0)
				execute_cmd(data, cmd);
			cmd = cmd->next;
		}
		ret = get_children_children(data);
		exit_shell(data, ret);
	}
	return (get_children(data));
}

/* Prepares the command list for execution by checking for command existence
 * and creating pipes.
 * Returns 0 if data or data->cmd is NULL.
 * Returns 1 if creating pipes fails, or 127 otherwise. */
static int	prep_for_exec(t_data *data)
{
	if (!data || !data->cmd)
		return (EXIT_SUCCESS);
	if (!create_pipes(data))
		return (EXIT_FAILURE);
	return (CMD_NOT_FOUND);
}

/* Executes the cmd list by creating child processes for each cmd
 * and waiting for them to terminate.
 * Returns the exit code of the last child to terminate or 1 if an error
 * occured during child creation. */
int	execute(t_data *data)
{
	int		ret;

	ret = prep_for_exec(data);
	if (ret != CMD_NOT_FOUND)
		return (ret);
	ret = create_children(data);
	if (parent_built_check(data) == 1 && ret != 130)
	{
		if (!place_fd(data->cmd))
			return (EXIT_FAILURE);
		redirect_io(data->cmd->io_fds);
		ret = execute_builtin_parent(data, data->cmd, ret);
		restore_io(data->cmd->io_fds);
	}
	return (ret);
}
