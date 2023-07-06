/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:24:21 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 17:49:27 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execute_cmd_2(t_data *data, t_cmd *cmd);

int	create_children_2(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmd;
	while (data->pid && cmd)
	{
		data->pid = fork();
		if (data->pid == -1)
			return (errmsg_cmd("fork", NULL, strerror(errno), EXIT_FAILURE));
		else if (data->pid == 0)
		{
			set_signals_child(data);
			execute_cmd_2(data, cmd);
		}
		cmd = cmd->next;
	}
	return (get_children(data));
}

static int	execute_cmd_2(t_data *data, t_cmd *cmd)
{
	int	ret;

	if (!cmd)
		exit_shell(data, errmsg_cmd("child", NULL,
				"parsing error: no command to execute!", EXIT_FAILURE));
	sigaction(SIGQUIT, &data->sigquit, NULL);
	close_fds(data->cmd, false);
	if (ft_strchr(cmd->cmd, '/') == NULL)
	{
		ret = execute_sys_bin(data, cmd);
		if (ret != CMD_NOT_FOUND)
			exit_shell(data, ret);
	}
	ret = execute_local_bin(data, cmd);
	exit_shell(data, ret);
	return (ret);
}
