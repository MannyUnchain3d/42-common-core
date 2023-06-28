/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <nicklaw@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:30:54 by Manny             #+#    #+#             */
/*   Updated: 2023/06/14 19:55:59 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Checks access and permissions for each possible cmd path.
 * Returns the first path to a valid cmd, or NULL if none are valid. */
static char	*find_valid_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_path;

	i = 0;
	cmd_path = NULL;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
		{
			errmsg_cmd("malloc", NULL,
				"an unexpected error occurred", EXIT_FAILURE);
			return (NULL);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free_ptr(cmd_path);
		i++;
	}
	return (NULL);
}

/* Extracts paths from the PATH environment variable.
 * Returns an array of paths on success, or NULL on failure. */
static char	**get_paths_from_env(t_data *data)
{
	char	**env_paths;

	if (get_env_var_index(data->env, "PATH") == -1)
		return (NULL);
	env_paths = ft_split(get_env_var_value(data->env, "PATH"), ':');
	if (!env_paths)
		return (NULL);
	return (env_paths);
}

/* Searches the PATH environment variable for the given cmd.
 * Returns the first path to a valid cmd, or NULL if none are valid. */
char	*get_cmd_path(t_data *data, char *name)
{
	char	**env_paths;
	char	*cmd_path;
	char	*cmd;

	if (!name)
		return (NULL);
	env_paths = get_paths_from_env(data);
	if (!env_paths)
		return (NULL);
	cmd = ft_strjoin("/", name);
	if (!cmd)
	{
		free_str_tab(env_paths);
		return (NULL);
	}
	cmd_path = find_valid_cmd_path(cmd, env_paths);
	if (!cmd_path)
	{
		free_str_tab(env_paths);
		free_ptr(cmd);
		return (NULL);
	}
	return (cmd_path);
}
