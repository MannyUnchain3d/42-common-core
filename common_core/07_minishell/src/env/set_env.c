/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:53:36 by Manny             #+#    #+#             */
/*   Updated: 2023/05/01 21:33:42 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char **realloc_env_vars(t_data *data, int size)
{
    char    **new_env;
    int     i;

	new_env = ft_calloc(sizeof *new_env, size + 1);
	if (!new_env)
		return (NULL);
	i = 0;
	while (data->env[i] && i < size)
	{
		new_env[i] = ft_strdup(data->env[i]);
		free_ptr(data->env[i]);
		i++;
	}
	free(data->env);
	return (new_env);
}

bool	set_env_var(t_data *data, char *key, char *value)
{
	int		index;
	char	*tmp;

	index = get_env_var_index(data->env, key);
	if (value == NULL)
		value = "";
	tmp = ft_strjoin("=", value);
	if (!tmp)
		return (false);
	if (index != -1 && data->env[index])
	{
		free_ptr(data->env[index]);
		data->env[index] = ft_strjoin(key, tmp);
	}
	else
	{
		index = env_var_count(data->env);
		data->env = realloc_env_vars(data, index + 1);
		if (!data->env)
			return (false);
		data->env[index] = ft_strjoin(key, tmp);
	}
	free_ptr(tmp);
	return (true);
 }

/* Removes the variable at the given index from the environment. 
 * Returns 1 if success or 0 if */

 bool	remove_env_var(t_data *data, int index)
 {
	int	i;
	int count;

	if (index > env_var_count(data->env))
		return (false);
	free_ptr(data->env[index]);
	i = index;
	count = index;
	while (data->env[i + 1])
	{
		data->env[i] = ft_strdup(data->env[i + 1]);
		free_ptr(data->env[i + 1]);
		i++;
		count++;
	}
	data->env = realloc_env_vars(data, count);
	if (!data->env)
		return (false);
	return (true);
 }
