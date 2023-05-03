/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:20:23 by Manny             #+#    #+#             */
/*   Updated: 2023/05/03 16:11:59 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Counts all the environment variables and returns their numbers. */
int env_var_count(char **env)
{
	int i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

/* Searches for the given variable in the environment variables.
 * Returns the index of the variable if it's a full match.
 * Returns -1 if the string cannot be found */
int get_env_var_index(char **env, char *var)
{
	int     i;
	char    *tmp;

	tmp = ft_strjoin(var, "=");
	if (!tmp)
		return (-1);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], tmp, ft_strlen(tmp)) == 0)
		{
			free_ptr(tmp);
			return (i);
		}
		i++;
	} 
	free_ptr(tmp);
	return (-1);
}

/* Checks if the key has a valid name for environment variable. *
 * Returns true if the key contains only alphanumeri chars or '_' if not. */
bool    is_valid_env_var_key(char *var)
{
	int i;
	
	i = 0;
	if (ft_isalpha(var[i]) == 0 && var[i] != '_')
		return (false);
	i++;
	while (var[i] && var[i] != '=')
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			return (false);
		i++;
	}
	return (true);
}
