/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:27:28 by Manny             #+#    #+#             */
/*   Updated: 2023/06/28 16:00:19 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Execute a given builtin command.
 * Returns 0 if the command is executed successfully, or 1 if it fails.
 * Returns 127 if the command is not a builtin. */
int	execute_builtin(t_data *data, t_cmd *cmd)
{
	int	ret;

	ret = CMD_NOT_FOUND;
	if (ft_strncmp(cmd->cmd, "cd", 3) == 0)
		ret = cd_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "echo", 5) == 0)
		ret = echo_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "env", 4) == 0)
		ret = env_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "exit", 5) == 0)
		ret = exit_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "export", 7) == 0)
		ret = export_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "pwd", 4) == 0)
		ret = pwd_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "unset", 6) == 0)
		ret = unset_builtin(data, cmd->args);
	return (ret);
}

int	execute_builtin_parent(t_data *data, t_cmd *cmd, int ret)
{
	if (ft_strncmp(cmd->cmd, "cd", 3) == 0)
		ret = cd_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "env", 4) == 0)
		ret = env_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "exit", 5) == 0)
		ret = exit_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "export", 7) == 0)
		ret = export_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->cmd, "unset", 6) == 0)
		ret = unset_builtin(data, cmd->args);
	return (ret);
}

/* Executes the command's system binary file if it exists in the PATH.
 * Returns 127 if the command is not found
 * Returns 1 if execution of existing command fails. */
int	execute_sys_bin(t_data *data, t_cmd *cmd)
{
	if (!cmd->cmd || cmd->cmd[0] == '\0')
		return (CMD_NOT_FOUND);
	if (cmd_is_dir(cmd->cmd))
		return (CMD_NOT_FOUND);
	cmd->path = get_cmd_path(data, cmd->cmd);
	if (!cmd->path)
		return (CMD_NOT_FOUND);
	if (execve(cmd->path, cmd->args, data->env) == -1)
		errmsg_cmd("execve", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}

/* Executes the command's local binary file if it exists.
 * Returns 127 if the command is not found.
 * Returns 1 if execution of existing command fails. */
int	execute_local_bin(t_data *data, t_cmd *cmd)
{
	int	ret;

	ret = check_cmd_not_found(data, cmd);
	if (ret != 0)
		return (ret);
	if (execve(cmd->cmd, cmd->args, data->env) == -1)
		return (errmsg_cmd("execve", NULL, strerror(errno), errno));
	return (EXIT_FAILURE);
}

/* Child process tries to execute the given command by settings
 * its input/output fds and searching for an executable in this order:
 * 1. Builtin command
 * 2. System binary file
 * 3. Local binary file
 * If it cannot find a matching executable, it prints an error message.
 * Child exits with its program's exit code, or 1 if it cannot find one. */
int	execute_cmd(t_data *data, t_cmd *cmd)
{
	int	ret;

	ret = 0;
	set_signals_child(data);
	if (parent_built_check(data))
		exit_shell(data, EXIT_SUCCESS);
	if (!cmd || !cmd->cmd)
		exit_shell(data, errmsg_cmd("child", NULL,
				"parsing error: no command to execute!", EXIT_FAILURE));
	if (place_fd(cmd) == false)
		exit_shell(data, EXIT_FAILURE);
	set_pipe_fds(data->cmd, cmd);
	sigaction(SIGQUIT, &data->sigquit, NULL);
	redirect_io(cmd->io_fds);
	close_fds(data->cmd, false);
	if (ft_strchr(cmd->cmd, '/') == NULL)
		execute_cmd_chain(data, cmd, ret);
	ret = execute_local_bin(data, cmd);
	exit_shell(data, ret);
	return (ret);
}
