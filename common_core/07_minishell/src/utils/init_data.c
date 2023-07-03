/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:23:30 by etetopat          #+#    #+#             */
/*   Updated: 2023/06/29 00:31:54 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_shlvl(t_data *data)
{
	int		shlvl_index;
	int		shlvl_value;
	char	*shlvl;

	shlvl_index = get_env_var_index(data->env, "SHLVL");
	if (shlvl_index != -1)
	{
		shlvl_value = ft_atoi(get_env_var_value(data->env, "SHLVL"));
		shlvl_value++;
		shlvl = ft_itoa(shlvl_value);
		if (shlvl)
		{
			set_env_var(data, "SHLVL", shlvl);
			free(shlvl);
		}
	}
}

/* Initializes a environment variable list inherited from the parent shell
 * excluding OLDPWD. OLDPWD is not inherited because it is set by minishell.
 * Returns 1 on success, or 0 on failure. */
static bool	init_env(t_data *data)
{
	int		i;
	int		env_count;
	int		new_env_count;

	env_count = 0;
	new_env_count = 0;
	while (environ[env_count])
		env_count++;
	data->env = ft_calloc(env_count + 1, sizeof(*data->env));
	if (!data->env)
		return (false);
	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "OLDPWD=", 7) != 0)
		{
			data->env[new_env_count] = ft_strdup(environ[i]);
			if (!data->env[new_env_count])
				return (false);
			new_env_count++;
		}
		i++;
	}
	update_shlvl(data);
	return (true);
}

/* Initializes the working directory variable.
 * Returns true on success, or false on failure. */
static bool	init_wd(t_data *data)
{
	char	buff[PATH_MAX];
	char	*wd;

	wd = getcwd(buff, PATH_MAX);
	data->wd = ft_strdup(wd);
	if (!data->wd)
		return (false);
	return (true);
}

/* Initializes the data structure used in parsing and executing user input.
 * Returns true on success, or false on failure. */
bool	init_data(t_data *data)
{
	if (!init_env(data))
	{
		errmsg_cmd("Fatal", NULL, "Could not initialize environment", 1);
		return (false);
	}
	if (!init_wd(data))
	{
		errmsg_cmd("Fatal", NULL, "Could not initialize working directories",
			1);
		return (false);
	}
	data->cmd = NULL;
	data->user_input = NULL;
	data->pid = -1;
	init_termios(data);
	return (true);
}

/* Initializes a structure with default values to contain infile and outfile
 * information for a command. */
void	init_io(t_cmd *cmd)
{
	if (!cmd->io_fds)
	{
		cmd->io_fds = malloc(sizeof * cmd->io_fds);
		if (!cmd->io_fds)
			return ;
		cmd->io_fds->infile = NULL;
		cmd->io_fds->outfile = NULL;
		cmd->io_fds->heredoc_delimiter = NULL;
		cmd->io_fds->heredoc_quotes = false;
		cmd->io_fds->fd_in = -1;
		cmd->io_fds->fd_out = -1;
		cmd->io_fds->stdin_backup = -1;
		cmd->io_fds->stdout_backup = -1;
	}
}
