/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:29:53 by Manny             #+#    #+#             */
/*   Updated: 2023/06/29 00:22:48 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Checks if the command is a directory.
 * Returns true if it is, false if it is not. */
bool	cmd_is_dir(char *cmd)
{
	struct stat	cmd_stat;

	ft_memset(&cmd_stat, 0, sizeof(cmd_stat));
	stat(cmd, &cmd_stat);
	return (S_ISDIR(cmd_stat.st_mode));
}

/* Checks why a command was not found in the system binaries.
 * Returns an error message if the command is invalid.
 * Returns 0 if the command is valid and should be executed. */
int	check_cmd_not_found(t_data *data, t_cmd *cmd)
{
	if (ft_strchr(cmd->cmd, '/') == NULL
		&& get_env_var_index(data->env, "PATH") != -1)
		return (errmsg_cmd(cmd->cmd, NULL, "command not found",
				CMD_NOT_FOUND));
	if (access(cmd->cmd, F_OK) != 0)
		return (errmsg_cmd(cmd->cmd, NULL, strerror(errno), CMD_NOT_FOUND));
	else if (cmd_is_dir(cmd->cmd))
		return (errmsg_cmd(cmd->cmd, NULL, "is a directory",
				CMD_NOT_EXECUTABLE));
	else if (access(cmd->cmd, F_OK | X_OK) != 0)
		return (errmsg_cmd(cmd->cmd, NULL, strerror(errno),
				CMD_NOT_EXECUTABLE));
	return (EXIT_SUCCESS);
}

int	parent_built_check(t_data *data)
{
	int		ret;
	t_cmd	*cmd;

	ret = 0;
	cmd = data->cmd;
	if (!data->cmd->pipe_output && !data->cmd->prev)
	{
		if (!ft_strncmp(cmd->cmd, "cd", 3)
			|| !ft_strncmp(cmd->cmd, "env", 4)
			|| !ft_strncmp(cmd->cmd, "exit", 5)
			|| !ft_strncmp(cmd->cmd, "export", 7)
			|| !ft_strncmp(cmd->cmd, "unset", 6))
			ret = 1;
	}
	return (ret);
}

void	execute_cmd_chain(t_data *data, t_cmd *cmd, int ret)
{
	ret = execute_builtin(data, cmd);
	if (ret != CMD_NOT_FOUND)
		exit_shell(data, ret);
	ret = execute_sys_bin(data, cmd);
	if (ret != CMD_NOT_FOUND)
		exit_shell(data, ret);
}
